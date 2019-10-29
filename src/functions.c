#include <stdlib.h>
#include "../include/CPU.h"


void add(uint8_t reg, uint8_t carry)
{
    if (carry)
    {
        uint8_t cy = (CY_MASK & F) == CY_MASK;
        A += reg + cy;
    }
    else
        A +=  reg;
}


void sub(uint8_t reg, uint8_t borrow)
{
    if (borrow)
    {
        uint8_t cy = (CY_MASK & F) == CY_MASK;
        A -= (reg + cy);
    }
    else
        A -=  reg;
}


void inc(uint8_t *reg1, uint8_t *reg2)
{
    // INR
    if (reg2 == NULL)
    {
        if (*reg1 & 11111111)
            // setcarry;
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
}


void dec(uint8_t *reg1, uint8_t *reg2)
{
    // DCR
    if (reg2 == NULL)
    {
        if (*reg1 & 11111111)
            // setcarry;
        *reg1--;
    }
    // DCX
    else{
        uint16_t regpair = *reg1;
        regpair <<= 4;
        regpair |= *reg2;

        regpair--;
        *reg2 = (uint8_t) regpair;
        regpair >>=4;
        *reg1 = (uint8_t) regpair;
    }
}


void load(uint8_t reg1, uint8_t reg2)
{
    uint16_t addr = (reg1 << 8) | reg2;
    A = memory[addr];
}


void store(uint8_t reg1, uint8_t reg2)
{
    uint16_t addr = (reg1 << 8) | reg2;
    memory[addr] = A;
}


void bitwiseAnd(uint8_t reg)
{
    A &= reg;
}


void bitwiseOr(uint8_t reg)
{
    A |= reg;
}


void bitwiseXor(uint8_t reg)
{
    A ^= reg;
}

void bitwiseNot(uint8_t reg)
{
    A = ~reg;
}

void updateFlags(uint8_t s, uint8_t z, uint8_t ac, uint8_t p, uint8_t cy)
{
    // this is the new flag
    uint8_t F_ = NULL;

    uint8_t flag_arr[] = {s, z, ac, p, cy};

    for (uint8_t i = 0; i < 8; i++)
    {
        // don't care bits (keep them zero)
        if (i == 1 || i == 3 || i == 5)
        {
            F_ <<= 1;
            continue;
        }
        
        switch (flag_arr[i])
        {
            case 0:
                F_ &= 0;
                break;
            case 1:
                F_ |= 1;
                break;
            case 2:
                char isBitSet = 
                F_ 
            
            default:
                break;
        }
    }

    F_ <<= 1;
}


void move(uint8_t *dest, uint8_t *src, uint8_t data)
{
    // immediate
    if (src == NULL)
        *dest = data;
    // register indirect
    else
        *dest = *src;
}

uint8_t checkAuxCarry(uint8_t x, uint8_t y)
{
    x &= 00001111;              // extract lower nibble of x
    y &= 00001111;              // extract lower nibble of y
    return (x + y) & 00010000;  // check if carry rolled over to higher nibble
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

uint8_t extractMemory()
{
    // extract location pointed by HL pair in index
    uint16_t index = H;
    index <<= 4;
    index |= L;

    return memory[index];
}