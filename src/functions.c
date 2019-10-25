#include "CPU.h"


void add(char reg, char carry)
{
    if (carry)
    {
        char cy = (CY_MASK & F) == CY_MASK;
        A += reg + cy;
    }
    else
        A +=  reg;
}


char sub(char reg, char borrow)
{
    if (borrow)
    {
        char cy = (CY_MASK & F) == CY_MASK;
        A -= (reg + cy);
    }
    else
        A -=  reg;
}


void updateFlags(char s, char z, char ac, char p, char cy)
{
    // this is the new flag
    char F_ = NULL;

    char flag_arr[] = {s, z, ac, p, cy};

    for (int i = 0; i < 8; i++)
    {
        // don't care bits (keep them zero)
        if (i == 1 || i == 3 || i == 5)
        {
            F_ << 1;
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

    F_ << 1;
}