#include <stdlib.h>
#include "CPU.h"
#include "prototypes.h"


void add(uint8_t reg, uint8_t withCarry)
{
    uint8_t isSetAuxCarry = checkAuxCarry(A, reg);
    uint8_t isCarrySet = (A + reg > 0xff) ? 1 : 0;

    if (withCarry)
    {
        uint8_t cy = (CY_MASK & F) == CY_MASK;
        A += reg + cy;
    }
    else
        A +=  reg;
        
    adjustFlags(isCarrySet, isSetAuxCarry);
}


void subtract(uint8_t reg, uint8_t withBorrow)
{
    uint8_t isSetAuxCarry = checkAuxCarry(A, reg);
    uint8_t isCarrySet = (A - reg < 0) ? 1 : 0;

    if (withBorrow)
    {
        uint8_t cy = (CY_MASK & F) == CY_MASK;
        A -= (reg + cy);
    }
    else
        A -=  reg;

    adjustFlags(isCarrySet, isSetAuxCarry);
}


void increment(uint8_t *reg1, uint8_t *reg2)
{
    uint8_t isCarrySet, isSetAuxCarry = checkAuxCarry(A, *reg1);

    // INR
    if (reg2 == NULL)
    {
        if (*reg1 & 0xff)
            isCarrySet = 1;
        *reg1++;
    }

    // INX
    else{
        uint16_t regpair = *reg1;
        regpair <<= 4;
        regpair |= *reg2;

        regpair++;
        *reg2 = (uint8_t) regpair;
        regpair >>=4;
        *reg1 = (uint8_t) regpair;
    }

    adjustFlags(isCarrySet, isSetAuxCarry);
}


void decrement(uint8_t *reg1, uint8_t *reg2)
{
    uint8_t isCarrySet, isAuxCarrySet = checkAuxCarry(A, *reg1);

    // DCR
    if (reg2 == NULL)
    {
        // if isCarrySet is declared in the if statement (without {})
        // a dependent statement may not be a declaration
        // also, if isCarrySet is declared in the if body, it will be destroyed
        // and cannot be accessible after the if statement...
        if (*reg1 & 0xff)
            isCarrySet = 1;
        *reg1--;
    }

    // DCX
    else
    {
        uint16_t regpair = *reg1;
        regpair <<= 4;
        regpair |= *reg2;

        regpair--;
        *reg2 = (uint8_t) regpair;
        regpair >>=4;
        *reg1 = (uint8_t) regpair;
    }

    adjustFlags(isCarrySet, isAuxCarrySet);
}


void decimalAdjustAcc()
{
    // LS of A > 9 or AC = 1
    if (((A & 0x0f) > 0x09) || (F & AC_MASK))
        A += 0x06;
    
    // MS of A > 9 or CY = 1
    if (((A & 0xf0) > 0x90) || (F & CY_MASK))
    {
        A += 0x60;
        updateFlags(-1, -1, -1, -1, 1);
    }
}

void doubleAdd(uint8_t reg1, uint8_t reg2)
{
    uint32_t num = (reg1 << 8) | reg2;
    num += (H << 8) | L;

    L = num;
    num >>= 8;

    H = num;
    num >>= 8;

    updateFlags(-1, -1, -1, -1, num & 0x01);
}


void loadAcc(uint8_t reg1, uint8_t reg2)
{
    uint16_t addr = (reg1 << 8) | reg2;
    A = memory[addr];
    adjustFlags(-1, -1);
}

void storeAcc(uint8_t reg1, uint8_t reg2)
{
    uint16_t addr = (reg1 << 8) | reg2;
    memory[addr] = A;
}


void bitwiseAnd(uint8_t reg)
{
    A &= reg;
    adjustFlags(-1, -1);
}

void bitwiseOr(uint8_t reg)
{
    A |= reg;
    adjustFlags(-1, -1);
}

void bitwiseXor(uint8_t reg)
{
    A ^= reg;
    adjustFlags(-1, -1);
}


/* RAR
 * CY --> D7 -> D6 -> D5 -> D4 -> D3 -> D2 -> D1 -> D0 ->+
 * |                                                     |
 * +-----------------------------------------------------+
 * 
 * RRC
 * CY     D7 -> D6 -> D5 -> D4 -> D3 -> D2 -> D1 -> D0 ->+
 * |      |                                              |
 * +------+----------------------------------------------+
 * 
 * 
 * RAL
 * CY <-- D7 <- D6 <- D5 <- D4 <- D3 <- D2 <- D1 <- D0 <-+
 * |                                                     |
 * +-----------------------------------------------------+
 * 
 * RLC
 * CY <-- D7 <- D6 <- D5 <- D4 <- D3 <- D2 <- D1 <- D0 <-+
 *        |                                              |
 *        +----------------------------------------------+
 */
void rotateLeft(uint8_t alongCarry)
{
    uint8_t isExtremeBitSet = (A & 0x80) ? 1 : 0;
    A <<= 1;

    if (alongCarry)
        A |= F & 0x01;
    else
        A |= isExtremeBitSet;

    adjustFlags(isExtremeBitSet, -1);
}

void rotateRight(uint8_t alongCarry)
{
    uint8_t isExtremeBitSet = (A & 0x01) ? 1 : 0;
    uint16_t A_;

    if (alongCarry)
        A_ = ((F & CY_MASK) ? 1 : 0) << 8;
    else
        A_ = isExtremeBitSet << 8;
    
    A_ |= A;
    A_ >>= 1;
    A = A_;

    adjustFlags(isExtremeBitSet, -1);
}


/* A < data: C = 1
 * A = data: Z = 1
 * A > data: C = Z = 0
 */ 
void compareWithAcc(uint8_t reg)
{
    if (A < reg)
        updateFlags(-1, -1, -1, -1, 1);
    else if (A == reg)
        updateFlags(-1, 1, -1, -1, -1);
    else
        updateFlags(-1, 0, -1, -1, 0);
}


/* arguments are the flag bits
 * -1 : preserve previous
 *  0 : RESET
 *  1 : SET
 */
void updateFlags(uint8_t s, uint8_t z, uint8_t ac, uint8_t p, uint8_t cy)
{
    // this is the new flag
    uint8_t F_ = 0;

    // don't care bits previous value is preserved
    uint8_t flag_arr[] = {s, z, -1, ac, -1, p, -1, cy};

    for (int i = 0; i < 8; i++)
    {
        // shift right, make way for next bit!
        F_ <<= 1;
        if (
            (flag_arr[i] == 1) ||
            ((flag_arr[i] == 0xff) && (F & (1 << i)))
        )
        {
            F_ |= 1;
        }
    }

    // update the Flags
    F = F_;
}

// updates the Flags according to contents of Accumulator
void adjustFlags(uint8_t isCarrySet, uint8_t isAuxCarrySet)
{
    uint8_t isSignSet = (A & 0x80) ? 1 : 0;
    uint8_t isZeroSet = (A == 0x00) ? 1 : 0;
    uint8_t isParitySet = checkParity();

    updateFlags(isSignSet, isZeroSet, isAuxCarrySet, isParitySet, isCarrySet);
}

uint8_t checkAuxCarry(uint8_t x, uint8_t y)
{
    x &= 0x0f;              // extract lower nibble of x
    y &= 0x0f;              // extract lower nibble of y
    return (x + y) & 0x10;  // check if carry rolled over to higher nibble
}

uint8_t checkParity()
{
    // create a copy of accumulator to work on
    uint8_t A_ = A;
    uint8_t isParityEven = 1;

    // while the accumulator copy is not zero
    while (A_)
    {
        if (A_ & 1)
            isParityEven = 1 - isParityEven;    // toggle parity
        A_ >>= 1;
    }
    
    return isParityEven;
}


void pushToStack(uint8_t reg1, uint8_t reg2)
{
    memory[--stack_ptr] = reg1;
    memory[--stack_ptr] = reg2;
}

void popFromStack(uint8_t *reg1, uint8_t *reg2)
{
    *reg2 = memory[stack_ptr++];
    *reg1 = memory[stack_ptr++];
}

void callSubroutine(uint16_t addr)
{
    memory[--stack_ptr] = prog_cntr;
    memory[--stack_ptr] = prog_cntr >> 8;
    prog_cntr = addr;
}

void returnToMain()
{
    prog_cntr = (memory[stack_ptr++] << 8) | memory[stack_ptr++];
}


void swap(uint8_t *reg1, uint8_t *reg2)
{
    uint8_t temp = *reg1;
    *reg1 = *reg2;
    *reg2 = temp;
}