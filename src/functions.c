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


uint8_t sub(uint8_t reg, uint8_t borrow)
{
    if (borrow)
    {
        uint8_t cy = (CY_MASK & F) == CY_MASK;
        A -= (reg + cy);
    }
    else
        A -=  reg;
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

void inc(uint8_t *reg1, uint8_t *reg2)
{
    // INR
    if (reg2 == NULL)
    {
        if (reg & 11111111)
            // setcarry;
        *reg1++;
    }
}


uint8_t checkAuxCarry(uint8_t x, uint8_t y)
{
    x &= 00001111;              // extract lower nibble of x
    y &= 00001111;              // extract lower nibble of y
    return (x + y) & 00010000;  // check if carry rolled over to higher nibble
}

uint8_t extractMemory()
{
    // extract location pointed by HL pair in index
    uint16_t index = H;
    index <<= 4;
    index |= L;

    return memory[index];
}