#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <errno.h>


int toHex(const char *string)
{
    int len = strlen(string), num = 0, i = len;
    char ch;

    while((ch = string[--i]) != '\0')
    {
        if ('0' <= ch && ch <= '9')
            num += pow(16, len - i - 1) * (ch - '0');
        else if ('A' <= ch && ch <= 'F')
            num += pow(16, len - i - 1) * (ch - 'A' + 10);
        else if ('a' <= ch && ch <= 'f')
            num += pow(16, len - i - 1) * (ch - 'a' + 10);
    }
    
    return num;
}


void asm2hex(char *line, FILE *fpw)
{
    // obtain the meta-inst (eg. LXI, MOV, STC, ...)
    char *meta_inst = strtok(line, " ");
    // printf("meta : %s\n", meta_inst);

// ------------------------------- Data  Tranfer -------------------------------

    if (!strcmp(meta_inst, "MOV"))
    {
        // obtain registers as meta-inst needs them
        char *reg = strtok(NULL, " ");
        if (!strcmp(reg, "A,A"))
            fprintf(fpw, "%c", 0x7f);
        else if (!strcmp(reg, "A,B"))
            fprintf(fpw, "%c", 0x78);
        else if (!strcmp(reg, "A,C"))
            fprintf(fpw, "%c", 0x79);
        else if (!strcmp(reg, "A,D"))
            fprintf(fpw, "%c", 0x7A);
        else if (!strcmp(reg, "A,E"))
            fprintf(fpw, "%c", 0x7B);
        else if (!strcmp(reg, "A,H"))
            fprintf(fpw, "%c", 0x7C);
        else if (!strcmp(reg, "A,L"))
            fprintf(fpw, "%c", 0x7D);
        else if (!strcmp(reg, "A,M"))
            fprintf(fpw, "%c", 0x7E);

        else if (!strcmp(reg, "B,A"))
            fprintf(fpw, "%c", 0x47);
        else if (!strcmp(reg, "B,B"))
            fprintf(fpw, "%c", 0x40);
        else if (!strcmp(reg, "B,C"))
            fprintf(fpw, "%c", 0x41);
        else if (!strcmp(reg, "B,D"))
            fprintf(fpw, "%c", 0x42);
        else if (!strcmp(reg, "B,E"))
            fprintf(fpw, "%c", 0x43);
        else if (!strcmp(reg, "B,H"))
            fprintf(fpw, "%c", 0x44);
        else if (!strcmp(reg, "B,L"))
            fprintf(fpw, "%c", 0x45);
        else if (!strcmp(reg, "B,M"))
            fprintf(fpw, "%c", 0x46);
        
        else if (!strcmp(reg, "C,A"))
            fprintf(fpw, "%c", 0x4F);
        else if (!strcmp(reg, "C,B"))
            fprintf(fpw, "%c", 0x48);
        else if (!strcmp(reg, "C,C"))
            fprintf(fpw, "%c", 0x49);
        else if (!strcmp(reg, "C,D"))
            fprintf(fpw, "%c", 0x4A);
        else if (!strcmp(reg, "C,E"))
            fprintf(fpw, "%c", 0x4B);
        else if (!strcmp(reg, "C,H"))
            fprintf(fpw, "%c", 0x4C);
        else if (!strcmp(reg, "C,L"))
            fprintf(fpw, "%c", 0x4D);
        else if (!strcmp(reg, "C,M"))
            fprintf(fpw, "%c", 0x4E);
        
        else if (!strcmp(reg, "D,A"))
            fprintf(fpw, "%c", 0x57);
        else if (!strcmp(reg, "D,B"))
            fprintf(fpw, "%c", 0x50);
        else if (!strcmp(reg, "D,C"))
            fprintf(fpw, "%c", 0x51);
        else if (!strcmp(reg, "D,D"))
            fprintf(fpw, "%c", 0x52);
        else if (!strcmp(reg, "D,E"))
            fprintf(fpw, "%c", 0x53);
        else if (!strcmp(reg, "D,H"))
            fprintf(fpw, "%c", 0x54);
        else if (!strcmp(reg, "D,L"))
            fprintf(fpw, "%c", 0x55);
        else if (!strcmp(reg, "D,M"))
            fprintf(fpw, "%c", 0x56);
        
        else if (!strcmp(reg, "E,A"))
            fprintf(fpw, "%c", 0x5F);
        else if (!strcmp(reg, "E,B"))
            fprintf(fpw, "%c", 0x58);
        else if (!strcmp(reg, "E,C"))
            fprintf(fpw, "%c", 0x59);
        else if (!strcmp(reg, "E,D"))
            fprintf(fpw, "%c", 0x5A);
        else if (!strcmp(reg, "E,E"))
            fprintf(fpw, "%c", 0x5B);
        else if (!strcmp(reg, "E,H"))
            fprintf(fpw, "%c", 0x5C);
        else if (!strcmp(reg, "E,L"))
            fprintf(fpw, "%c", 0x5D);
        else if (!strcmp(reg, "E,M"))
            fprintf(fpw, "%c", 0x5E);
        
        else if (!strcmp(reg, "H,A"))
            fprintf(fpw, "%c", 0x67);
        else if (!strcmp(reg, "H,B"))
            fprintf(fpw, "%c", 0x60);
        else if (!strcmp(reg, "H,C"))
            fprintf(fpw, "%c", 0x61);
        else if (!strcmp(reg, "H,D"))
            fprintf(fpw, "%c", 0x62);
        else if (!strcmp(reg, "H,E"))
            fprintf(fpw, "%c", 0x63);
        else if (!strcmp(reg, "H,H"))
            fprintf(fpw, "%c", 0x64);
        else if (!strcmp(reg, "H,L"))
            fprintf(fpw, "%c", 0x65);
        else if (!strcmp(reg, "H,M"))
            fprintf(fpw, "%c", 0x66);
        
        else if (!strcmp(reg, "L,A"))
            fprintf(fpw, "%c", 0x6F);
        else if (!strcmp(reg, "L,B"))
            fprintf(fpw, "%c", 0x68);
        else if (!strcmp(reg, "L,C"))
            fprintf(fpw, "%c", 0x69);
        else if (!strcmp(reg, "L,D"))
            fprintf(fpw, "%c", 0x6A);
        else if (!strcmp(reg, "L,E"))
            fprintf(fpw, "%c", 0x6B);
        else if (!strcmp(reg, "L,H"))
            fprintf(fpw, "%c", 0x6C);
        else if (!strcmp(reg, "L,L"))
            fprintf(fpw, "%c", 0x6D);
        else if (!strcmp(reg, "L,M"))
            fprintf(fpw, "%c", 0x6E);
        
        else if (!strcmp(reg, "M,A"))
            fprintf(fpw, "%c", 0x77);
        else if (!strcmp(reg, "M,B"))
            fprintf(fpw, "%c", 0x70);
        else if (!strcmp(reg, "M,C"))
            fprintf(fpw, "%c", 0x71);
        else if (!strcmp(reg, "M,D"))
            fprintf(fpw, "%c", 0x72);
        else if (!strcmp(reg, "M,E"))
            fprintf(fpw, "%c", 0x73);
        else if (!strcmp(reg, "M,H"))
            fprintf(fpw, "%c", 0x74);
        else if (!strcmp(reg, "M,L"))
            fprintf(fpw, "%c", 0x75);
        
        else
        {
            printf("some error occured\n");
        }
    }

    else if (!strcmp(meta_inst, "MVI"))
    {
        char *reg = strtok(NULL, " ");
        uint8_t data = toHex(strtok(NULL, " "));
        
        if (!strcmp(reg, "A,"))
        {
            fprintf(fpw, "%c", 0x3E);
            fprintf(fpw, "%c", data);
        }
        else if (!strcmp(reg, "B,"))
        {
            fprintf(fpw, "%c", 0x06);
            fprintf(fpw, "%c", data);
        }
        else if (!strcmp(reg, "C,"))
        {
            fprintf(fpw, "%c", 0x0E);
            fprintf(fpw, "%c", data);
        }
        else if (!strcmp(reg, "D,"))
        {
            fprintf(fpw, "%c", 0x16);
            fprintf(fpw, "%c", data);
        }
        else if (!strcmp(reg, "E,"))
        {
            fprintf(fpw, "%c", 0x1E);
            fprintf(fpw, "%c", data);
        }
        else if (!strcmp(reg, "H,"))
        {
            fprintf(fpw, "%c", 0x26);
            fprintf(fpw, "%c", data);
        }
        else if (!strcmp(reg, "L,"))
        {
            fprintf(fpw, "%c", 0x2E);
            fprintf(fpw, "%c", data);
        }
        else if (!strcmp(reg, "M,"))
        {
            fprintf(fpw, "%c", 0x36);
            fprintf(fpw, "%c", data);
        }
        
        else
        {
            printf("some error occured\n");
        }   
    }

    else if(!strcmp(meta_inst, "LXI"))
    {
        char *reg = strtok(NULL, " ");
        uint16_t data = toHex(strtok(NULL, " "));
        
        if (!strcmp(reg, "B,"))
        {
            fprintf(fpw, "%c", 0x01);
            fprintf(fpw, "%c", data);
            fprintf(fpw, "%c", data >> 8);
        }
        else if (!strcmp(reg, "D,"))
        {
            fprintf(fpw, "%c", 0x11);
            fprintf(fpw, "%c", data);
            fprintf(fpw, "%c", data >> 8);
        }
        else if (!strcmp(reg, "H,"))
        {
            fprintf(fpw, "%c", 0x21);
            fprintf(fpw, "%c", data);
            fprintf(fpw, "%c", data >> 8);
        }
        else if (!strcmp(reg, "SP,"))
        {
            fprintf(fpw, "%c", 0x31);
            fprintf(fpw, "%c", data);
            fprintf(fpw, "%c", data >> 8);
        }
        
        else
        {
            printf("some error occured\n");
        }
        
    }

    else if(!strcmp(meta_inst, "LDA"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0x3A);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if(!strcmp(meta_inst, "STA"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0x32);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcmp(meta_inst, "LHLD"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0x2A);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcmp(meta_inst, "SHLD"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0x22);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if(!strcmp(meta_inst, "LDAX"))
    {
        char *reg = strtok(NULL, " ");
        if (!strcmp(reg, "B"))
            fprintf(fpw, "%c", 0x0A);
        else if (!strcmp(reg, "C"))
            fprintf(fpw, "%c", 0x1A);
        
        else
        {
            printf("some error occured\n");
        }
    }

    else if(!strcmp(meta_inst, "STAX"))
    {
        char *reg = strtok(NULL, " ");
        if (!strcmp(reg, "B"))
            fprintf(fpw, "%c", 0x02);
        else if (!strcmp(reg, "C"))
            fprintf(fpw, "%c", 0x12);
        
        else
        {
            printf("some error occured\n");
        }
    }

    else if (!strcmp(meta_inst, "XCHG"))
        fprintf(fpw, "%c", 0xEB);


// -------------------------------- Arithematic --------------------------------

    else if (!strcmp(meta_inst, "ADD"))
    {
        char *reg = strtok(NULL, " ");
        if (!strcmp(reg, "A"))
            fprintf(fpw, "%c", 0x87);
        else if (!strcmp(reg, "B"))
            fprintf(fpw, "%c", 0x80);
        else if (!strcmp(reg, "C"))
            fprintf(fpw, "%c", 0x81);
        else if (!strcmp(reg, "D"))
            fprintf(fpw, "%c", 0x82);
        else if (!strcmp(reg, "E"))
            fprintf(fpw, "%c", 0x83);
        else if (!strcmp(reg, "H"))
            fprintf(fpw, "%c", 0x84);
        else if (!strcmp(reg, "L"))
            fprintf(fpw, "%c", 0x85);
        else if (!strcmp(reg, "M"))
            fprintf(fpw, "%c", 0x86);
        
        else
        {
            printf("some error occured\n");
        }
        
    }

    else if (!strcmp(meta_inst, "ADC"))
    {
        char *reg = strtok(NULL, " ");
        if (!strcmp(reg, "A"))
            fprintf(fpw, "%c", 0x8F);
        else if (!strcmp(reg, "B"))
            fprintf(fpw, "%c", 0x88);
        else if (!strcmp(reg, "C"))
            fprintf(fpw, "%c", 0x89);
        else if (!strcmp(reg, "D"))
            fprintf(fpw, "%c", 0x8A);
        else if (!strcmp(reg, "E"))
            fprintf(fpw, "%c", 0x8B);
        else if (!strcmp(reg, "H"))
            fprintf(fpw, "%c", 0x8C);
        else if (!strcmp(reg, "L"))
            fprintf(fpw, "%c", 0x8D);
        else if (!strcmp(reg, "M"))
            fprintf(fpw, "%c", 0x8E);
        
        else
        {
            printf("some error occured\n");
        }
        
    }

    else if (!strcmp(meta_inst, "SUB"))
    {
        char *reg = strtok(NULL, " ");
        if (!strcmp(reg, "A"))
            fprintf(fpw, "%c", 0x97);
        else if (!strcmp(reg, "B"))
            fprintf(fpw, "%c", 0x90);
        else if (!strcmp(reg, "C"))
            fprintf(fpw, "%c", 0x91);
        else if (!strcmp(reg, "D"))
            fprintf(fpw, "%c", 0x92);
        else if (!strcmp(reg, "E"))
            fprintf(fpw, "%c", 0x93);
        else if (!strcmp(reg, "H"))
            fprintf(fpw, "%c", 0x94);
        else if (!strcmp(reg, "L"))
            fprintf(fpw, "%c", 0x95);
        else if (!strcmp(reg, "M"))
            fprintf(fpw, "%c", 0x96);
        
        else
        {
            printf("some error occured\n");
        }
        
    }

    else if (!strcmp(meta_inst, "SBB"))
    {
        char *reg = strtok(NULL, " ");
        if (!strcmp(reg, "A"))
            fprintf(fpw, "%c", 0x9F);
        else if (!strcmp(reg, "B"))
            fprintf(fpw, "%c", 0x98);
        else if (!strcmp(reg, "C"))
            fprintf(fpw, "%c", 0x99);
        else if (!strcmp(reg, "D"))
            fprintf(fpw, "%c", 0x9A);
        else if (!strcmp(reg, "E"))
            fprintf(fpw, "%c", 0x9B);
        else if (!strcmp(reg, "H"))
            fprintf(fpw, "%c", 0x9C);
        else if (!strcmp(reg, "L"))
            fprintf(fpw, "%c", 0x9D);
        else if (!strcmp(reg, "M"))
            fprintf(fpw, "%c", 0x9E);
        
        else
        {
            printf("some error occured\n");
        }
        
    }

    else if (!strcmp(meta_inst, "INR"))
    {
        char *reg = strtok(NULL, " ");
        if (!strcmp(reg, "A"))
            fprintf(fpw, "%c", 0x3C);
        else if (!strcmp(reg, "B"))
            fprintf(fpw, "%c", 0x04);
        else if (!strcmp(reg, "C"))
            fprintf(fpw, "%c", 0x0C);
        else if (!strcmp(reg, "D"))
            fprintf(fpw, "%c", 0x14);
        else if (!strcmp(reg, "E"))
            fprintf(fpw, "%c", 0x1C);
        else if (!strcmp(reg, "H"))
            fprintf(fpw, "%c", 0x24);
        else if (!strcmp(reg, "L"))
            fprintf(fpw, "%c", 0x2C);
        else if (!strcmp(reg, "M"))
            fprintf(fpw, "%c", 0x34);
        
        else
        {
            printf("some error occured\n");
        }
        
    }

    else if (!strcmp(meta_inst, "DCR"))
    {
        char *reg = strtok(NULL, " ");
        if (!strcmp(reg, "A"))
            fprintf(fpw, "%c", 0x3D);
        else if (!strcmp(reg, "B"))
            fprintf(fpw, "%c", 0x05);
        else if (!strcmp(reg, "C"))
            fprintf(fpw, "%c", 0x0D);
        else if (!strcmp(reg, "D"))
            fprintf(fpw, "%c", 0x15);
        else if (!strcmp(reg, "E"))
            fprintf(fpw, "%c", 0x1D);
        else if (!strcmp(reg, "H"))
            fprintf(fpw, "%c", 0x25);
        else if (!strcmp(reg, "L"))
            fprintf(fpw, "%c", 0x2D);
        else if (!strcmp(reg, "M"))
            fprintf(fpw, "%c", 0x35);
        
        else
        {
            printf("some error occured\n");
        }
        
    }

    else if (!strcmp(meta_inst, "INX"))
    {
        char *reg = strtok(NULL, " ");
        if (!strcmp(reg, "B"))
            fprintf(fpw, "%c", 0x03);
        else if (!strcmp(reg, "D"))
            fprintf(fpw, "%c", 0x13);
        else if (!strcmp(reg, "H"))
            fprintf(fpw, "%c", 0x23);
        else if (!strcmp(reg, "SP"))
            fprintf(fpw, "%c", 0x33);
        
        else
        {
            printf("some error occured\n");
        }   
    }

    else if (!strcmp(meta_inst, "DCX"))
    {
        char *reg = strtok(NULL, " ");
        if (!strcmp(reg, "B"))
            fprintf(fpw, "%c", 0x0B);
        else if (!strcmp(reg, "D"))
            fprintf(fpw, "%c", 0x1B);
        else if (!strcmp(reg, "H"))
            fprintf(fpw, "%c", 0x2B);
        else if (!strcmp(reg, "SP"))
            fprintf(fpw, "%c", 0x3B);
        
        else
        {
            printf("some error occured\n");
        }   
    }

    else if (!strcmp(meta_inst, "DAD"))
    {
        char *reg = strtok(NULL, " ");
        if (!strcmp(reg, "B"))
            fprintf(fpw, "%c", 0x09);
        else if (!strcmp(reg, "D"))
            fprintf(fpw, "%c", 0x19);
        else if (!strcmp(reg, "H"))
            fprintf(fpw, "%c", 0x29);
        else if (!strcmp(reg, "SP"))
            fprintf(fpw, "%c", 0x39);
        
        else
        {
            printf("some error occured\n");
        }   
    }

    else if (!strcmp(meta_inst, "ADI"))
    {
        uint8_t data = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xC6);
        fprintf(fpw, "%c", data);
    }

    else if (!strcmp(meta_inst, "ACI"))
    {
        uint8_t data = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xCE);
        fprintf(fpw, "%c", data);
    }

    else if (!strcmp(meta_inst, "SUI"))
    {
        uint8_t data = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xD6);
        fprintf(fpw, "%c", data);
    }

    else if (!strcmp(meta_inst, "SBI"))
    {
        uint8_t data = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xDE);
        fprintf(fpw, "%c", data);
    }

    else if(!strcmp(meta_inst, "DAA"))
        fprintf(fpw, "%c", 27);



// ---------------------------------- Logical ----------------------------------

    else if (!strcmp(meta_inst, "ANA"))
    {
        char *reg = strtok(NULL, " ");
        if (!strcmp(reg, "A"))
            fprintf(fpw, "%c", 0xA7);
        else if (!strcmp(reg, "B"))
            fprintf(fpw, "%c", 0xA0);
        else if (!strcmp(reg, "C"))
            fprintf(fpw, "%c", 0xA1);
        else if (!strcmp(reg, "D"))
            fprintf(fpw, "%c", 0xA2);
        else if (!strcmp(reg, "E"))
            fprintf(fpw, "%c", 0xA3);
        else if (!strcmp(reg, "H"))
            fprintf(fpw, "%c", 0xA4);
        else if (!strcmp(reg, "L"))
            fprintf(fpw, "%c", 0xA5);
        else if (!strcmp(reg, "M"))
            fprintf(fpw, "%c", 0xA6);
        
        else
        {
            printf("some error occured\n");
        }
    }

    else if (!strcmp(meta_inst, "XRA"))
    {
        char *reg = strtok(NULL, " ");
        if (!strcmp(reg, "A"))
            fprintf(fpw, "%c", 0xAF);
        else if (!strcmp(reg, "B"))
            fprintf(fpw, "%c", 0xA8);
        else if (!strcmp(reg, "C"))
            fprintf(fpw, "%c", 0xA9);
        else if (!strcmp(reg, "D"))
            fprintf(fpw, "%c", 0xAA);
        else if (!strcmp(reg, "E"))
            fprintf(fpw, "%c", 0xAB);
        else if (!strcmp(reg, "H"))
            fprintf(fpw, "%c", 0xAC);
        else if (!strcmp(reg, "L"))
            fprintf(fpw, "%c", 0xAD);
        else if (!strcmp(reg, "M"))
            fprintf(fpw, "%c", 0xAE);
        
        else
        {
            printf("some error occured\n");
        }
    }

    else if (!strcmp(meta_inst, "ORA"))
    {
        char *reg = strtok(NULL, " ");
        if (!strcmp(reg, "A"))
            fprintf(fpw, "%c", 0xB7);
        else if (!strcmp(reg, "B"))
            fprintf(fpw, "%c", 0xB0);
        else if (!strcmp(reg, "C"))
            fprintf(fpw, "%c", 0xB1);
        else if (!strcmp(reg, "D"))
            fprintf(fpw, "%c", 0xB2);
        else if (!strcmp(reg, "E"))
            fprintf(fpw, "%c", 0xB3);
        else if (!strcmp(reg, "H"))
            fprintf(fpw, "%c", 0xB4);
        else if (!strcmp(reg, "L"))
            fprintf(fpw, "%c", 0xB5);
        else if (!strcmp(reg, "M"))
            fprintf(fpw, "%c", 0xB6);
        
        else
        {
            printf("some error occured\n");
        }
    }

    else if (!strcmp(meta_inst, "CMP"))
    {
        char *reg = strtok(NULL, " ");
        if (!strcmp(reg, "A"))
            fprintf(fpw, "%c", 0xBF);
        else if (!strcmp(reg, "B"))
            fprintf(fpw, "%c", 0xB8);
        else if (!strcmp(reg, "C"))
            fprintf(fpw, "%c", 0xB9);
        else if (!strcmp(reg, "D"))
            fprintf(fpw, "%c", 0xBA);
        else if (!strcmp(reg, "E"))
            fprintf(fpw, "%c", 0xBB);
        else if (!strcmp(reg, "H"))
            fprintf(fpw, "%c", 0xBC);
        else if (!strcmp(reg, "L"))
            fprintf(fpw, "%c", 0xBD);
        else if (!strcmp(reg, "M"))
            fprintf(fpw, "%c", 0xBE);
        
        else
        {
            printf("some error occured\n");
        }
    }


    else if (!strcmp(meta_inst, "ANI"))
    {
        uint8_t data = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xE6);
        fprintf(fpw, "%c", data);
    }

    else if (!strcmp(meta_inst, "XRI"))
    {
        uint8_t data = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xEE);
        fprintf(fpw, "%c", data);
    }

    else if (!strcmp(meta_inst, "ORI"))
    {
        uint8_t data = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xF6);
        fprintf(fpw, "%c", data);
    }

    else if (!strcmp(meta_inst, "CPI"))
    {
        uint8_t data = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xFE);
        fprintf(fpw, "%c", data);
    }

    else if (!strcmp(meta_inst, "RAL"))
        fprintf(fpw, "%c", 0x17);

    else if (!strcmp(meta_inst, "RAR"))
        fprintf(fpw, "%c", 0x1F);

    else if (!strcmp(meta_inst, "RLC"))
        fprintf(fpw, "%c", 0x07);

    else if (!strcmp(meta_inst, "RRC"))
        fprintf(fpw, "%c", 0x0F);

    else if (!strcmp(meta_inst, "CMA"))
        fprintf(fpw, "%c", 0x2F);

    else if (!strcmp(meta_inst, "CMC"))
        fprintf(fpw, "%c", 0x3F);

    else if (!strcmp(meta_inst, "STC"))
        fprintf(fpw, "%c", 0x37);
    

// --------------------------------- Branching ---------------------------------

    else if (!strcmp(meta_inst, "JMP"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xC3);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcmp(meta_inst, "JNZ"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xC2);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcmp(meta_inst, "JZ"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xCA);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcmp(meta_inst, "JNC"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xD2);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcmp(meta_inst, "JC"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xDA);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcmp(meta_inst, "JPE"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xEA);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcmp(meta_inst, "JPO"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xE2);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcmp(meta_inst, "JP"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xF2);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcmp(meta_inst, "JM"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xFA);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }
    


    else if (!strcmp(meta_inst, "CALL"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xCD);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcmp(meta_inst, "CNZ"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xC4);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcmp(meta_inst, "CZ"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xCC);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcmp(meta_inst, "CNC"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xD4);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcmp(meta_inst, "CC"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xDC);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcmp(meta_inst, "CPE"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xEC);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcmp(meta_inst, "CPO"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xE4);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcmp(meta_inst, "CP"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xF4);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcmp(meta_inst, "CM"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xFC);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }



    else if (!strcmp(meta_inst, "RET"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xC9);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcmp(meta_inst, "RNZ"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xC0);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcmp(meta_inst, "RZ"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xC8);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcmp(meta_inst, "RNC"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xD0);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcmp(meta_inst, "RC"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xD8);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcmp(meta_inst, "RPE"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xE8);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcmp(meta_inst, "RPO"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xE0);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcmp(meta_inst, "RP"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xF0);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }

    else if (!strcmp(meta_inst, "RM"))
    {
        uint16_t addr = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xF8);
        fprintf(fpw, "%c", addr);
        fprintf(fpw, "%c", addr >> 8);
    }


    else if (!strcmp(meta_inst, "RST0"))
        fprintf(fpw, "%c", 0xC7);

    else if (!strcmp(meta_inst, "RST1"))
        fprintf(fpw, "%c", 0xCF);

    else if (!strcmp(meta_inst, "RST2"))
        fprintf(fpw, "%c", 0xD7);

    else if (!strcmp(meta_inst, "RST3"))
        fprintf(fpw, "%c", 0xDF);

    else if (!strcmp(meta_inst, "RST4"))
        fprintf(fpw, "%c", 0xE7);

    else if (!strcmp(meta_inst, "RST5"))
        fprintf(fpw, "%c", 0xEF);

    else if (!strcmp(meta_inst, "RST6"))
        fprintf(fpw, "%c", 0xF7);

    else if (!strcmp(meta_inst, "RST7"))
        fprintf(fpw, "%c", 0xFF);
    

// --------------------------- I/O & Machine Control ---------------------------
 
    else if (!strcmp(meta_inst, "PUSH"))
    {
        char *reg = strtok(NULL, " ");
        if (!strcmp(reg, "B"))
            fprintf(fpw, "%c", 0xC5);
        else if (!strcmp(reg, "D"))
            fprintf(fpw, "%c", 0xD5);
        else if (!strcmp(reg, "H"))
            fprintf(fpw, "%c", 0xE5);
        else if (!strcmp(reg, "PSW"))
            fprintf(fpw, "%c", 0xF5);
        
        else
        {
            printf("some error occured\n");
        }   
    }
    
    else if (!strcmp(meta_inst, "POP"))
    {
        char *reg = strtok(NULL, " ");
        if (!strcmp(reg, "B"))
            fprintf(fpw, "%c", 0xC1);
        else if (!strcmp(reg, "D"))
            fprintf(fpw, "%c", 0xD1);
        else if (!strcmp(reg, "H"))
            fprintf(fpw, "%c", 0xE1);
        else if (!strcmp(reg, "PSW"))
            fprintf(fpw, "%c", 0xF1);
        
        else
        {
            printf("some error occured\n");
        }   
    }

    else if (!strcmp(meta_inst, "SPHL"))
        fprintf(fpw, "%c", 0xF9);

    else if (!strcmp(meta_inst, "XTHL"))
        fprintf(fpw, "%c", 0xE3);

    else if (!strcmp(meta_inst, "OUT"))
    {
        uint8_t data = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xD3);
        fprintf(fpw, "%c", data);
    }

    else if (!strcmp(meta_inst, "IN"))
    {
        uint8_t data = toHex(strtok(NULL, " "));
        fprintf(fpw, "%c", 0xDB);
        fprintf(fpw, "%c", data);
    }
    

    else if (!strcmp(meta_inst, "DI"))
        fprintf(fpw, "%c", 0xF3);

    else if (!strcmp(meta_inst, "EI"))
        fprintf(fpw, "%c", 0xFB);


    else if (!strcmp(meta_inst, "HLT"))
        fprintf(fpw, "%c", 0x76);

    else if (!strcmp(meta_inst, "NOP"))
        fprintf(fpw, "%c", 0x00);


    else if (!strcmp(meta_inst, "RIM"))
        fprintf(fpw, "%c", 0x20);

    else if (!strcmp(meta_inst, "SIM"))
        fprintf(fpw, "%c", 0x30);


    else
    {
        printf("some error occured\n");
    }
}

int main(int argc, char const *argv[])
{
    FILE *fpr = fopen("code.asm", "r");
    FILE *fpw = fopen("code.mc", "w");

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

    char line[20];
    while (fgets(line, 20, fpr))
    {
        // printf("%s\n", line);
        asm2hex(line, fpw);
    }

    fclose(fpw);
    fclose(fpr);
    return 0;
}