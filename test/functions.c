#include <stdio.h>
#include <stdint.h>
// #include "../src/functions.c"

uint8_t F = 0x00;//0b10010110;
uint8_t A = 0xdd;

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

void printBinary(uint8_t num)
{
    for(int i=0; i < 8; i++)
    {
        printf("%d", (num & 0b10000000) ? 1 : 0);
        num <<= 1;
    }
    printf("\n");
}


uint8_t H = 0x43, L = 0x23;

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

int main(int argc, char const *argv[])
{
    printf("%x %2x%2x\n", F & 0x01, H, L);
    doubleAdd(0xb2, 0xf7);
    printf("%x %2x%2x\n", F & 0x01, H, L);
    return 0;
}
