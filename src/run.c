#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "compilation.c"


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

void printCPU()
{
    printf("A: 0x%2x    B: 0x%2x    D: 0x%2x    H: 0x%2x\n", A, B, D, H);
    printf("F: 0x%2x    C: 0x%2x    E: 0x%2x    L: 0x%2x\n", F, C, E, L);
    printf("\n");

    printf("PC: 0x%4x\n", prog_cntr);
    printf("SP: 0x%4x\n", stack_ptr);
    printf("\n");

    printf("S%c\t",  (F & S_MASK)  ? '*' : 0);
    printf("Z%c\t",  (F & Z_MASK)  ? '*' : 0);
    printf("AC%c\t", (F & AC_MASK) ? '*' : 0);
    printf("P%c\t",  (F & P_MASK)  ? '*' : 0);
    printf("CY%c\n", (F & CY_MASK) ? '*' : 0);
    printf("\n");
}


int main(int argc, char const *argv[])
{
    if (argc < 3)
    {
        errno = EINVAL;
        perror("invalid arguments!");
        return errno;
    }
    
    int fd = open(argv[1], O_RDONLY);
    // if (argv[1][0] == '-')
    //     fd = 0;
    // else
    //     fd = open(argv[1], O_RDONLY);
    
    if (fd == -1)
    {
        perror("open failed");
        return errno;
    }
    
    instruction inst;
    uint8_t state = CONTINUE;
    memory = (uint8_t *) malloc(65536);

    uint16_t prog_cntr = toHex(argv[2]);
    // if (argv[2][0] == '-')
    //     prog_cntr = 0x0000;
    // else
    //     prog_cntr = atoi(argv[2]);
    
    printf("Intializing CPU...\n");
    printCPU();

    printf("Loading code...\n");
    loadCode(fd, prog_cntr);
    printf("Code loaded!\n\n");
    char next = 4;

    uint8_t hexcode;
    uint16_t prog_addr = prog_cntr;    

    int stepwise = 0;
    printf("Do you want to go step-wise? (0/1)\n>>> ");
    scanf("%d", &stepwise);
    system("clear");


    while (state == CONTINUE)
    {
        // if (stepwise)
        //     scanf("%c", &next);

        inst = getInstruction(fd);
        state = performInstruction(inst);
        
        if(stepwise)
        {
            system("clear");
            if (inst.type == BYTES0)
                printf("instruction:  %2x          \n", inst.opcode);
            else if (inst.type == BYTES1)
                printf("instruction:  %2x  %2x     \n", inst.opcode, inst.bytes.one);
            else if (inst.type == BYTES2)
                printf("instruction:  %2x  %2x  %2x\n", inst.opcode, inst.bytes.two & 0xff, (inst.bytes.two >> 8) & 0xff);
            
            printCPU();
            printf("------------------------------------------\n");
            scanf("%c", &next);
        }
        
        prog_cntr++;
    }

    system("clear");
    printf("Final State...\n");
    printCPU();
    
    free(memory);
    close(fd);
    return 0;
}
