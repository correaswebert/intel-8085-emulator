#include <string.h>
#include <strings.h>
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <errno.h>

#include "toHex.c"


void asm2hex(char *line, FILE *fpw)
{
    // obtain the meta-inst (eg. LXI, MOV, STC, ...)
    char *meta_inst = strtok(line, " ");

// ------------------------------- Data  Tranfer -------------------------------

    if (!strcasecmp(meta_inst, "MOV"))
    {
        // obtain registers as meta-inst needs them
        char *reg = strtok(NULL, " ");
        if (!strcasecmp(reg, "A,A"))
            fprintf(fpw, "%c", 0x7f);
        else if (!strcasecmp(reg, "A,B"))
            fprintf(fpw, "%c", 0x78);
        else if (!strcasecmp(reg, "A,C"))
            fprintf(fpw, "%c", 0x79);
        else if (!strcasecmp(reg, "A,D"))
            fprintf(fpw, "%c", 0x7A);
        else if (!strcasecmp(reg, "A,E"))
            fprintf(fpw, "%c", 0x7B);
        else if (!strcasecmp(reg, "A,H"))
            fprintf(fpw, "%c", 0x7C);
        else if (!strcasecmp(reg, "A,L"))
            fprintf(fpw, "%c", 0x7D);
        else if (!strcasecmp(reg, "A,M"))
            fprintf(fpw, "%c", 0x7E);

        else if (!strcasecmp(reg, "B,A"))
            fprintf(fpw, "%c", 0x47);
        else if (!strcasecmp(reg, "B,B"))
            fprintf(fpw, "%c", 0x40);
        else if (!strcasecmp(reg, "B,C"))
            fprintf(fpw, "%c", 0x41);
        else if (!strcasecmp(reg, "B,D"))
            fprintf(fpw, "%c", 0x42);
        else if (!strcasecmp(reg, "B,E"))
            fprintf(fpw, "%c", 0x43);
        else if (!strcasecmp(reg, "B,H"))
            fprintf(fpw, "%c", 0x44);
        else if (!strcasecmp(reg, "B,L"))
            fprintf(fpw, "%c", 0x45);
        else if (!strcasecmp(reg, "B,M"))
            fprintf(fpw, "%c", 0x46);
        
        else if (!strcasecmp(reg, "C,A"))
            fprintf(fpw, "%c", 0x4F);
        else if (!strcasecmp(reg, "C,B"))
            fprintf(fpw, "%c", 0x48);
        else if (!strcasecmp(reg, "C,C"))
            fprintf(fpw, "%c", 0x49);
        else if (!strcasecmp(reg, "C,D"))
            fprintf(fpw, "%c", 0x4A);
        else if (!strcasecmp(reg, "C,E"))
            fprintf(fpw, "%c", 0x4B);
        else if (!strcasecmp(reg, "C,H"))
            fprintf(fpw, "%c", 0x4C);
        else if (!strcasecmp(reg, "C,L"))
            fprintf(fpw, "%c", 0x4D);
        else if (!strcasecmp(reg, "C,M"))
            fprintf(fpw, "%c", 0x4E);
        
        else if (!strcasecmp(reg, "D,A"))
            fprintf(fpw, "%c", 0x57);
        else if (!strcasecmp(reg, "D,B"))
            fprintf(fpw, "%c", 0x50);
        else if (!strcasecmp(reg, "D,C"))
            fprintf(fpw, "%c", 0x51);
        else if (!strcasecmp(reg, "D,D"))
            fprintf(fpw, "%c", 0x52);
        else if (!strcasecmp(reg, "D,E"))
            fprintf(fpw, "%c", 0x53);
        else if (!strcasecmp(reg, "D,H"))
            fprintf(fpw, "%c", 0x54);
        else if (!strcasecmp(reg, "D,L"))
            fprintf(fpw, "%c", 0x55);
        else if (!strcasecmp(reg, "D,M"))
            fprintf(fpw, "%c", 0x56);
        
        else if (!strcasecmp(reg, "E,A"))
            fprintf(fpw, "%c", 0x5F);
        else if (!strcasecmp(reg, "E,B"))
            fprintf(fpw, "%c", 0x58);
        else if (!strcasecmp(reg, "E,C"))
            fprintf(fpw, "%c", 0x59);
        else if (!strcasecmp(reg, "E,D"))
            fprintf(fpw, "%c", 0x5A);
        else if (!strcasecmp(reg, "E,E"))
            fprintf(fpw, "%c", 0x5B);
        else if (!strcasecmp(reg, "E,H"))
            fprintf(fpw, "%c", 0x5C);
        else if (!strcasecmp(reg, "E,L"))
            fprintf(fpw, "%c", 0x5D);
        else if (!strcasecmp(reg, "E,M"))
            fprintf(fpw, "%c", 0x5E);
        
        else if (!strcasecmp(reg, "H,A"))
            fprintf(fpw, "%c", 0x67);
        else if (!strcasecmp(reg, "H,B"))
            fprintf(fpw, "%c", 0x60);
        else if (!strcasecmp(reg, "H,C"))
            fprintf(fpw, "%c", 0x61);
        else if (!strcasecmp(reg, "H,D"))
            fprintf(fpw, "%c", 0x62);
        else if (!strcasecmp(reg, "H,E"))
            fprintf(fpw, "%c", 0x63);
        else if (!strcasecmp(reg, "H,H"))
            fprintf(fpw, "%c", 0x64);
        else if (!strcasecmp(reg, "H,L"))
            fprintf(fpw, "%c", 0x65);
        else if (!strcasecmp(reg, "H,M"))
            fprintf(fpw, "%c", 0x66);
        
        else if (!strcasecmp(reg, "L,A"))
            fprintf(fpw, "%c", 0x6F);
        else if (!strcasecmp(reg, "L,B"))
            fprintf(fpw, "%c", 0x68);
        else if (!strcasecmp(reg, "L,C"))
            fprintf(fpw, "%c", 0x69);
        else if (!strcasecmp(reg, "L,D"))
            fprintf(fpw, "%c", 0x6A);
        else if (!strcasecmp(reg, "L,E"))
            fprintf(fpw, "%c", 0x6B);
        else if (!strcasecmp(reg, "L,H"))
            fprintf(fpw, "%c", 0x6C);
        else if (!strcasecmp(reg, "L,L"))
            fprintf(fpw, "%c", 0x6D);
        else if (!strcasecmp(reg, "L,M"))
            fprintf(fpw, "%c", 0x6E);
        
        else if (!strcasecmp(reg, "M,A"))
            fprintf(fpw, "%c", 0x77);
        else if (!strcasecmp(reg, "M,B"))
            fprintf(fpw, "%c", 0x70);
        else if (!strcasecmp(reg, "M,C"))
            fprintf(fpw, "%c", 0x71);
        else if (!strcasecmp(reg, "M,D"))
            fprintf(fpw, "%c", 0x72);
        else if (!strcasecmp(reg, "M,E"))
            fprintf(fpw, "%c", 0x73);
        else if (!strcasecmp(reg, "M,H"))
            fprintf(fpw, "%c", 0x74);
        else if (!strcasecmp(reg, "M,L"))
            fprintf(fpw, "%c", 0x75);
        
        else
        {
            printf("Some error occured - MOV\n");
        }
    }

    else if (!strcasecmp(meta_inst, "MVI"))
    {
        char *reg = strtok(NULL, " ");
        uint8_t data = toHex(strtok(NULL, " "));
        
        if (!strcasecmp(reg, "A,"))
        {
            fprintf(fpw, "%c", 0x3E);
            fprintf(fpw, "%c", data);
        }
        else if (!strcasecmp(reg, "B,"))
        {
            fprintf(fpw, "%c", 0x06);
            fprintf(fpw, "%c", data);
        }
        else if (!strcasecmp(reg, "C,"))
        {
            fprintf(fpw, "%c", 0x0E);
            fprintf(fpw, "%c", data);
        }
        else if (!strcasecmp(reg, "D,"))
        {
            fprintf(fpw, "%c", 0x16);
            fprintf(fpw, "%c", data);
        }
        else if (!strcasecmp(reg, "E,"))
        {
            fprintf(fpw, "%c", 0x1E);
            fprintf(fpw, "%c", data);
        }
        else if (!strcasecmp(reg, "H,"))
        {
            fprintf(fpw, "%c", 0x26);
            fprintf(fpw, "%c", data);
        }
        else if (!strcasecmp(reg, "L,"))
        {
            fprintf(fpw, "%c", 0x2E);
            fprintf(fpw, "%c", data);
        }
        else if (!strcasecmp(reg, "M,"))
        {
            fprintf(fpw, "%c", 0x36);
            fprintf(fpw, "%c", data);
        }
        
        else
        {
            printf("Some error occured - MVI\n");
        }   
    }

    else if(!strcasecmp(meta_inst, "LXI"))
    {
        char *reg = strtok(NULL, " ");
        uint16_t data = toHex(strtok(NULL, " "));
        
        if (!strcasecmp(reg, "B,"))
        {
            fprintf(fpw, "%c", 0x01);
            fprintf(fpw, "%c", data);
            fprintf(fpw, "%c", data >> 8);
        }
        else if (!strcasecmp(reg, "D,"))
        {
            fprintf(fpw, "%c", 0x11);
            fprintf(fpw, "%c", data);
            fprintf(fpw, "%c", data >> 8);
        }
        else if (!strcasecmp(reg, "H,"))
        {
            fprintf(fpw, "%c", 0x21);
            fprintf(fpw, "%c", data);
            fprintf(fpw, "%c", data >> 8);
        }
        else if (!strcasecmp(reg, "SP,"))
        {
            fprintf(fpw, "%c", 0x31);
            fprintf(fpw, "%c", data);
            fprintf(fpw, "%c", data >> 8);
        }
        
        else
        {
            printf("Some error occured - LXI\n");
        }
        
    }

    else if(!strcasecmp(meta_inst, "LDA"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0x3A);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if(!strcasecmp(meta_inst, "STA"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0x32);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcasecmp(meta_inst, "LHLD"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0x2A);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcasecmp(meta_inst, "SHLD"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0x22);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if(!strcasecmp(meta_inst, "LDAX"))
    {
        char *reg = strtok(NULL, " ");
        if (!strcasecmp(reg, "B"))
            fprintf(fpw, "%c", 0x0A);
        else if (!strcasecmp(reg, "D"))
            fprintf(fpw, "%c", 0x1A);
        
        else
        {
            printf("Some error occured - LDAX\n");
        }
    }

    else if(!strcasecmp(meta_inst, "STAX"))
    {
        char *reg = strtok(NULL, " ");
        if (!strcasecmp(reg, "B"))
            fprintf(fpw, "%c", 0x02);
        else if (!strcasecmp(reg, "D"))
            fprintf(fpw, "%c", 0x12);
        
        else
        {
            printf("Some error occured - STAX\n");
        }
    }

    else if (!strcasecmp(meta_inst, "XCHG"))
        fprintf(fpw, "%c", 0xEB);


// -------------------------------- Arithematic --------------------------------

    else if (!strcasecmp(meta_inst, "ADD"))
    {
        char *reg = strtok(NULL, " ");
        if (!strcasecmp(reg, "A"))
            fprintf(fpw, "%c", 0x87);
        else if (!strcasecmp(reg, "B"))
            fprintf(fpw, "%c", 0x80);
        else if (!strcasecmp(reg, "C"))
            fprintf(fpw, "%c", 0x81);
        else if (!strcasecmp(reg, "D"))
            fprintf(fpw, "%c", 0x82);
        else if (!strcasecmp(reg, "E"))
            fprintf(fpw, "%c", 0x83);
        else if (!strcasecmp(reg, "H"))
            fprintf(fpw, "%c", 0x84);
        else if (!strcasecmp(reg, "L"))
            fprintf(fpw, "%c", 0x85);
        else if (!strcasecmp(reg, "M"))
            fprintf(fpw, "%c", 0x86);
        
        else
        {
            printf("Some error occured - ADD\n");
        }
        
    }

    else if (!strcasecmp(meta_inst, "ADC"))
    {
        char *reg = strtok(NULL, " ");
        if (!strcasecmp(reg, "A"))
            fprintf(fpw, "%c", 0x8F);
        else if (!strcasecmp(reg, "B"))
            fprintf(fpw, "%c", 0x88);
        else if (!strcasecmp(reg, "C"))
            fprintf(fpw, "%c", 0x89);
        else if (!strcasecmp(reg, "D"))
            fprintf(fpw, "%c", 0x8A);
        else if (!strcasecmp(reg, "E"))
            fprintf(fpw, "%c", 0x8B);
        else if (!strcasecmp(reg, "H"))
            fprintf(fpw, "%c", 0x8C);
        else if (!strcasecmp(reg, "L"))
            fprintf(fpw, "%c", 0x8D);
        else if (!strcasecmp(reg, "M"))
            fprintf(fpw, "%c", 0x8E);
        
        else
        {
            printf("Some error occured - ADC\n");
        }
        
    }

    else if (!strcasecmp(meta_inst, "SUB"))
    {
        char *reg = strtok(NULL, " ");
        if (!strcasecmp(reg, "A"))
            fprintf(fpw, "%c", 0x97);
        else if (!strcasecmp(reg, "B"))
            fprintf(fpw, "%c", 0x90);
        else if (!strcasecmp(reg, "C"))
            fprintf(fpw, "%c", 0x91);
        else if (!strcasecmp(reg, "D"))
            fprintf(fpw, "%c", 0x92);
        else if (!strcasecmp(reg, "E"))
            fprintf(fpw, "%c", 0x93);
        else if (!strcasecmp(reg, "H"))
            fprintf(fpw, "%c", 0x94);
        else if (!strcasecmp(reg, "L"))
            fprintf(fpw, "%c", 0x95);
        else if (!strcasecmp(reg, "M"))
            fprintf(fpw, "%c", 0x96);
        
        else
        {
            printf("Some error occured - SUB\n");
        }
        
    }

    else if (!strcasecmp(meta_inst, "SBB"))
    {
        char *reg = strtok(NULL, " ");
        if (!strcasecmp(reg, "A"))
            fprintf(fpw, "%c", 0x9F);
        else if (!strcasecmp(reg, "B"))
            fprintf(fpw, "%c", 0x98);
        else if (!strcasecmp(reg, "C"))
            fprintf(fpw, "%c", 0x99);
        else if (!strcasecmp(reg, "D"))
            fprintf(fpw, "%c", 0x9A);
        else if (!strcasecmp(reg, "E"))
            fprintf(fpw, "%c", 0x9B);
        else if (!strcasecmp(reg, "H"))
            fprintf(fpw, "%c", 0x9C);
        else if (!strcasecmp(reg, "L"))
            fprintf(fpw, "%c", 0x9D);
        else if (!strcasecmp(reg, "M"))
            fprintf(fpw, "%c", 0x9E);
        
        else
        {
            printf("Some error occured - SBB\n");
        }
        
    }

    else if (!strcasecmp(meta_inst, "INR"))
    {
        char *reg = strtok(NULL, " ");
        if (!strcasecmp(reg, "A"))
            fprintf(fpw, "%c", 0x3C);
        else if (!strcasecmp(reg, "B"))
            fprintf(fpw, "%c", 0x04);
        else if (!strcasecmp(reg, "C"))
            fprintf(fpw, "%c", 0x0C);
        else if (!strcasecmp(reg, "D"))
            fprintf(fpw, "%c", 0x14);
        else if (!strcasecmp(reg, "E"))
            fprintf(fpw, "%c", 0x1C);
        else if (!strcasecmp(reg, "H"))
            fprintf(fpw, "%c", 0x24);
        else if (!strcasecmp(reg, "L"))
            fprintf(fpw, "%c", 0x2C);
        else if (!strcasecmp(reg, "M"))
            fprintf(fpw, "%c", 0x34);
        
        else
        {
            printf("Some error occured - INR\n");
        }
        
    }

    else if (!strcasecmp(meta_inst, "DCR"))
    {
        char *reg = strtok(NULL, " ");
        if (!strcasecmp(reg, "A"))
            fprintf(fpw, "%c", 0x3D);
        else if (!strcasecmp(reg, "B"))
            fprintf(fpw, "%c", 0x05);
        else if (!strcasecmp(reg, "C"))
            fprintf(fpw, "%c", 0x0D);
        else if (!strcasecmp(reg, "D"))
            fprintf(fpw, "%c", 0x15);
        else if (!strcasecmp(reg, "E"))
            fprintf(fpw, "%c", 0x1D);
        else if (!strcasecmp(reg, "H"))
            fprintf(fpw, "%c", 0x25);
        else if (!strcasecmp(reg, "L"))
            fprintf(fpw, "%c", 0x2D);
        else if (!strcasecmp(reg, "M"))
            fprintf(fpw, "%c", 0x35);
        
        else
        {
            printf("Some error occured - DCR\n");
        }
        
    }

    else if (!strcasecmp(meta_inst, "INX"))
    {
        char *reg = strtok(NULL, " ");
        if (!strcasecmp(reg, "B"))
            fprintf(fpw, "%c", 0x03);
        else if (!strcasecmp(reg, "D"))
            fprintf(fpw, "%c", 0x13);
        else if (!strcasecmp(reg, "H"))
            fprintf(fpw, "%c", 0x23);
        else if (!strcasecmp(reg, "SP"))
            fprintf(fpw, "%c", 0x33);
        
        else
        {
            printf("Some error occured - INX\n");
        }   
    }

    else if (!strcasecmp(meta_inst, "DCX"))
    {
        char *reg = strtok(NULL, " ");
        if (!strcasecmp(reg, "B"))
            fprintf(fpw, "%c", 0x0B);
        else if (!strcasecmp(reg, "D"))
            fprintf(fpw, "%c", 0x1B);
        else if (!strcasecmp(reg, "H"))
            fprintf(fpw, "%c", 0x2B);
        else if (!strcasecmp(reg, "SP"))
            fprintf(fpw, "%c", 0x3B);
        
        else
        {
            printf("Some error occured - DCX\n");
        }   
    }

    else if (!strcasecmp(meta_inst, "DAD"))
    {
        char *reg = strtok(NULL, " ");
        if (!strcasecmp(reg, "B"))
            fprintf(fpw, "%c", 0x09);
        else if (!strcasecmp(reg, "D"))
            fprintf(fpw, "%c", 0x19);
        else if (!strcasecmp(reg, "H"))
            fprintf(fpw, "%c", 0x29);
        else if (!strcasecmp(reg, "SP"))
            fprintf(fpw, "%c", 0x39);
        
        else
        {
            printf("Some error occured - DAD\n");
        }   
    }

    else if (!strcasecmp(meta_inst, "ADI"))
    {
        uint8_t data = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xC6);
        fprintf(fpw, "%c", data);
    }

    else if (!strcasecmp(meta_inst, "ACI"))
    {
        uint8_t data = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xCE);
        fprintf(fpw, "%c", data);
    }

    else if (!strcasecmp(meta_inst, "SUI"))
    {
        uint8_t data = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xD6);
        fprintf(fpw, "%c", data);
    }

    else if (!strcasecmp(meta_inst, "SBI"))
    {
        uint8_t data = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xDE);
        fprintf(fpw, "%c", data);
    }

    else if(!strcasecmp(meta_inst, "DAA"))
        fprintf(fpw, "%c", 27);



// ---------------------------------- Logical ----------------------------------

    else if (!strcasecmp(meta_inst, "ANA"))
    {
        char *reg = strtok(NULL, " ");
        if (!strcasecmp(reg, "A"))
            fprintf(fpw, "%c", 0xA7);
        else if (!strcasecmp(reg, "B"))
            fprintf(fpw, "%c", 0xA0);
        else if (!strcasecmp(reg, "C"))
            fprintf(fpw, "%c", 0xA1);
        else if (!strcasecmp(reg, "D"))
            fprintf(fpw, "%c", 0xA2);
        else if (!strcasecmp(reg, "E"))
            fprintf(fpw, "%c", 0xA3);
        else if (!strcasecmp(reg, "H"))
            fprintf(fpw, "%c", 0xA4);
        else if (!strcasecmp(reg, "L"))
            fprintf(fpw, "%c", 0xA5);
        else if (!strcasecmp(reg, "M"))
            fprintf(fpw, "%c", 0xA6);
        
        else
        {
            printf("Some error occured - ANA\n");
        }
    }

    else if (!strcasecmp(meta_inst, "XRA"))
    {
        char *reg = strtok(NULL, " ");
        if (!strcasecmp(reg, "A"))
            fprintf(fpw, "%c", 0xAF);
        else if (!strcasecmp(reg, "B"))
            fprintf(fpw, "%c", 0xA8);
        else if (!strcasecmp(reg, "C"))
            fprintf(fpw, "%c", 0xA9);
        else if (!strcasecmp(reg, "D"))
            fprintf(fpw, "%c", 0xAA);
        else if (!strcasecmp(reg, "E"))
            fprintf(fpw, "%c", 0xAB);
        else if (!strcasecmp(reg, "H"))
            fprintf(fpw, "%c", 0xAC);
        else if (!strcasecmp(reg, "L"))
            fprintf(fpw, "%c", 0xAD);
        else if (!strcasecmp(reg, "M"))
            fprintf(fpw, "%c", 0xAE);
        
        else
        {
            printf("Some error occured -XRA\n");
        }
    }

    else if (!strcasecmp(meta_inst, "ORA"))
    {
        char *reg = strtok(NULL, " ");
        if (!strcasecmp(reg, "A"))
            fprintf(fpw, "%c", 0xB7);
        else if (!strcasecmp(reg, "B"))
            fprintf(fpw, "%c", 0xB0);
        else if (!strcasecmp(reg, "C"))
            fprintf(fpw, "%c", 0xB1);
        else if (!strcasecmp(reg, "D"))
            fprintf(fpw, "%c", 0xB2);
        else if (!strcasecmp(reg, "E"))
            fprintf(fpw, "%c", 0xB3);
        else if (!strcasecmp(reg, "H"))
            fprintf(fpw, "%c", 0xB4);
        else if (!strcasecmp(reg, "L"))
            fprintf(fpw, "%c", 0xB5);
        else if (!strcasecmp(reg, "M"))
            fprintf(fpw, "%c", 0xB6);
        
        else
        {
            printf("Some error occured - ORA\n");
        }
    }

    else if (!strcasecmp(meta_inst, "CMP"))
    {
        char *reg = strtok(NULL, " ");
        if (!strcasecmp(reg, "A"))
            fprintf(fpw, "%c", 0xBF);
        else if (!strcasecmp(reg, "B"))
            fprintf(fpw, "%c", 0xB8);
        else if (!strcasecmp(reg, "C"))
            fprintf(fpw, "%c", 0xB9);
        else if (!strcasecmp(reg, "D"))
            fprintf(fpw, "%c", 0xBA);
        else if (!strcasecmp(reg, "E"))
            fprintf(fpw, "%c", 0xBB);
        else if (!strcasecmp(reg, "H"))
            fprintf(fpw, "%c", 0xBC);
        else if (!strcasecmp(reg, "L"))
            fprintf(fpw, "%c", 0xBD);
        else if (!strcasecmp(reg, "M"))
            fprintf(fpw, "%c", 0xBE);
        
        else
        {
            printf("Some error occured - CMP\n");
        }
    }


    else if (!strcasecmp(meta_inst, "ANI"))
    {
        uint8_t data = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xE6);
        fprintf(fpw, "%c", data);
    }

    else if (!strcasecmp(meta_inst, "XRI"))
    {
        uint8_t data = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xEE);
        fprintf(fpw, "%c", data);
    }

    else if (!strcasecmp(meta_inst, "ORI"))
    {
        uint8_t data = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xF6);
        fprintf(fpw, "%c", data);
    }

    else if (!strcasecmp(meta_inst, "CPI"))
    {
        uint8_t data = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xFE);
        fprintf(fpw, "%c", data);
    }

    else if (!strcasecmp(meta_inst, "RAL"))
        fprintf(fpw, "%c", 0x17);

    else if (!strcasecmp(meta_inst, "RAR"))
        fprintf(fpw, "%c", 0x1F);

    else if (!strcasecmp(meta_inst, "RLC"))
        fprintf(fpw, "%c", 0x07);

    else if (!strcasecmp(meta_inst, "RRC"))
        fprintf(fpw, "%c", 0x0F);

    else if (!strcasecmp(meta_inst, "CMA"))
        fprintf(fpw, "%c", 0x2F);

    else if (!strcasecmp(meta_inst, "CMC"))
        fprintf(fpw, "%c", 0x3F);

    else if (!strcasecmp(meta_inst, "STC"))
        fprintf(fpw, "%c", 0x37);
    

// --------------------------------- Branching ---------------------------------

    else if (!strcasecmp(meta_inst, "JMP"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xC3);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcasecmp(meta_inst, "JNZ"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xC2);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcasecmp(meta_inst, "JZ"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xCA);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcasecmp(meta_inst, "JNC"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xD2);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcasecmp(meta_inst, "JC"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xDA);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcasecmp(meta_inst, "JPE"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xEA);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcasecmp(meta_inst, "JPO"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xE2);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcasecmp(meta_inst, "JP"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xF2);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcasecmp(meta_inst, "JM"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xFA);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }
    


    else if (!strcasecmp(meta_inst, "CALL"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xCD);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcasecmp(meta_inst, "CNZ"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xC4);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcasecmp(meta_inst, "CZ"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xCC);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcasecmp(meta_inst, "CNC"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xD4);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcasecmp(meta_inst, "CC"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xDC);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcasecmp(meta_inst, "CPE"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xEC);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcasecmp(meta_inst, "CPO"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xE4);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcasecmp(meta_inst, "CP"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xF4);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcasecmp(meta_inst, "CM"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xFC);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }



    else if (!strcasecmp(meta_inst, "RET"))
        fprintf(fpw, "%c", 0xC9);

    else if (!strcasecmp(meta_inst, "RNZ"))
        fprintf(fpw, "%c", 0xC0);

    else if (!strcasecmp(meta_inst, "RZ"))
        fprintf(fpw, "%c", 0xC8);

    else if (!strcasecmp(meta_inst, "RNC"))
        fprintf(fpw, "%c", 0xD0);

    else if (!strcasecmp(meta_inst, "RC"))
        fprintf(fpw, "%c", 0xD8);

    else if (!strcasecmp(meta_inst, "RPE"))
        fprintf(fpw, "%c", 0xE8);

    else if (!strcasecmp(meta_inst, "RPO"))
        fprintf(fpw, "%c", 0xE0);

    else if (!strcasecmp(meta_inst, "RP"))
        fprintf(fpw, "%c", 0xF0);

    else if (!strcasecmp(meta_inst, "RM"))
        fprintf(fpw, "%c", 0xF8);


    else if (!strcasecmp(meta_inst, "RST0"))
        fprintf(fpw, "%c", 0xC7);

    else if (!strcasecmp(meta_inst, "RST1"))
        fprintf(fpw, "%c", 0xCF);

    else if (!strcasecmp(meta_inst, "RST2"))
        fprintf(fpw, "%c", 0xD7);

    else if (!strcasecmp(meta_inst, "RST3"))
        fprintf(fpw, "%c", 0xDF);

    else if (!strcasecmp(meta_inst, "RST4"))
        fprintf(fpw, "%c", 0xE7);

    else if (!strcasecmp(meta_inst, "RST5"))
        fprintf(fpw, "%c", 0xEF);

    else if (!strcasecmp(meta_inst, "RST6"))
        fprintf(fpw, "%c", 0xF7);

    else if (!strcasecmp(meta_inst, "RST7"))
        fprintf(fpw, "%c", 0xFF);
    

// --------------------------- I/O & Machine Control ---------------------------
 
    else if (!strcasecmp(meta_inst, "PUSH"))
    {
        char *reg = strtok(NULL, " ");
        if (!strcasecmp(reg, "B"))
            fprintf(fpw, "%c", 0xC5);
        else if (!strcasecmp(reg, "D"))
            fprintf(fpw, "%c", 0xD5);
        else if (!strcasecmp(reg, "H"))
            fprintf(fpw, "%c", 0xE5);
        else if (!strcasecmp(reg, "PSW"))
            fprintf(fpw, "%c", 0xF5);
        
        else
        {
            printf("Some error occured - PUSH\n");
        }   
    }
    
    else if (!strcasecmp(meta_inst, "POP"))
    {
        char *reg = strtok(NULL, " ");
        if (!strcasecmp(reg, "B"))
            fprintf(fpw, "%c", 0xC1);
        else if (!strcasecmp(reg, "D"))
            fprintf(fpw, "%c", 0xD1);
        else if (!strcasecmp(reg, "H"))
            fprintf(fpw, "%c", 0xE1);
        else if (!strcasecmp(reg, "PSW"))
            fprintf(fpw, "%c", 0xF1);
        
        else
        {
            printf("Some error occured - POP\n");
        }   
    }

    else if (!strcasecmp(meta_inst, "SPHL"))
        fprintf(fpw, "%c", 0xF9);

    else if (!strcasecmp(meta_inst, "XTHL"))
        fprintf(fpw, "%c", 0xE3);

    else if (!strcasecmp(meta_inst, "OUT"))
    {
        uint8_t data = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xD3);
        fprintf(fpw, "%c", data);
    }

    else if (!strcasecmp(meta_inst, "IN"))
    {
        uint8_t data = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xDB);
        fprintf(fpw, "%c", data);
    }
    

    else if (!strcasecmp(meta_inst, "DI"))
        fprintf(fpw, "%c", 0xF3);

    else if (!strcasecmp(meta_inst, "EI"))
        fprintf(fpw, "%c", 0xFB);


    else if (!strcasecmp(meta_inst, "HLT"))
        fprintf(fpw, "%c", 0x76);

    else if (!strcasecmp(meta_inst, "NOP"))
        fprintf(fpw, "%c", 0x00);


    else if (!strcasecmp(meta_inst, "RIM"))
        fprintf(fpw, "%c", 0x20);

    else if (!strcasecmp(meta_inst, "SIM"))
        fprintf(fpw, "%c", 0x30);


    else
    {
        if (meta_inst[0] == ';')
            return;
        printf("Some error occured - UKNOWN\n");
    }
}

int main(int argc, char const *argv[])
{
    int filename_size = strlen(argv[1]);
    char w_filename[80];

    // change format from .asm to .mc
    strncpy(w_filename, argv[1], filename_size - 4);
    w_filename[filename_size-4] = '\0';
    strcat(w_filename, ".mc");
    
    FILE *fpr = fopen(argv[1], "r");
    FILE *fpw = fopen(w_filename, "w+");

    if (fpr == NULL)
    {
        perror("fopen failed (read)");
        return errno;
    }

    if (fpw == NULL)
    {
        perror("fopen failed (write)");
        return errno;
    }

    char line[80];
    while (fgets(line, 80, fpr))
        asm2hex(line, fpw);

    fclose(fpw);
    fclose(fpr);
    return 0;
}