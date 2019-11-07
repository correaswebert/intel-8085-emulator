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
    printf("A: 0x%02x    B: 0x%02x    D: 0x%02x    H: 0x%02x\n", A, B, D, H);
    printf("F: 0x%02x    C: 0x%02x    E: 0x%02x    L: 0x%02x\n", F, C, E, L);
    printf("\n");

    printf("PC: 0x%04x\n", prog_cntr);
    printf("SP: 0x%04x\n", stack_ptr);
    printf("\n");

    printf("S%c\t",  (F & S_MASK)  ? '*' : 0);
    printf("Z%c\t",  (F & Z_MASK)  ? '*' : 0);
    printf("AC%c\t", (F & AC_MASK) ? '*' : 0);
    printf("P%c\t",  (F & P_MASK)  ? '*' : 0);
    printf("CY%c\n", (F & CY_MASK) ? '*' : 0);
    printf("\n");
}

void viewMemory(uint16_t addr)
{

}


int main(int argc, char const *argv[])
{
    if (argc < 3)
    {
        errno = EINVAL;
        perror("invalid arguments!");
        return errno;
    }
    
    // temporary variable for self added breakpoints
    char next;

    instruction inst;
    uint16_t prog_cntr;
    // state after each instruction
    uint8_t state = CONTINUE;
    // memory of 2^16 bytes
    memory = (uint8_t *) malloc(65536);



    int fd, num_files = (argc - 1) / 2, i = 1;
    while (i <= num_files)
    {
        printf("Loading %s @ %s...\n", argv[2*i - 1], argv[2*i]);
        fd = open(argv[2*i - 1], O_RDONLY);
        
        if (fd == -1)
        {
            perror("open failed");
            return errno;
        }

        prog_cntr = toHex(argv[2*i]);
        loadCode(fd, prog_cntr);
        i++;
    }
    // scanf("%c", &next);
    
    system("clear");
    char strAddr[5], strData[3];
    uint16_t hexAddr;
    
    printf("Enter ADDR <ENTER> DATA\n");
    while (1)
    {
        system("clear");
        printf("%04xH : %02x\n\n", hexAddr, memory[hexAddr]);

        printf("Enter (ADDR = p) for prev addr\n");
        printf("Enter (ADDR = n) for next addr\n");
        printf("Enter (ADDR = q) to quit\n\n");

        printf("addr >>> ");
        scanf("%s", strAddr);

        if (strcmp("q", strAddr) == 0)
            break;
        else if (strcmp("p", strAddr) == 0)
            hexAddr--;
        else if (strcmp("n", strAddr) == 0)
            hexAddr++;
        else
            hexAddr = toHex(strAddr);
        
        printf("data >>> ");
        scanf("%s", strData);
        printf("\n");

        memory[hexAddr] = toHex(strData);
    }
    
    system("clear");
    printf("Intializing CPU...\n");
    printCPU();


    int stepwise = 0;
    printf("Do you want to go step-wise? (0/1)\n>>> ");
    scanf("%d", &stepwise);
    system("clear");


    while (state == CONTINUE)
    {
        if (next == 'c')
        {
            stepwise = 0;
            system("clear");
        }
        
        if (stepwise)
            scanf("%c", &next);

        inst = getInstruction(fd);
        state = performInstruction(inst);
        
        if(stepwise)
        {
            system("clear");
            if (inst.type == BYTES0)
                printf("instruction:  %s\n", opcodes[inst.opcode]);
            else if (inst.type == BYTES1)
                printf("instruction:  %s  %02xH\n", opcodes[inst.opcode], inst.bytes.one);
            else if (inst.type == BYTES2)
                printf("instruction:  %s  %04xH\n", opcodes[inst.opcode], inst.bytes.two);
            
            printCPU();
            printf("------------------------------------------\n");
            // scanf("%c", &next);
        }
        
        prog_cntr++;
    }

    if (!stepwise)
        printCPU();

    printf("Final State...\n");

    strAddr[0] = "";
    while (strcmp("q", strAddr))
    {
        system("clear");
        printCPU();
        
        hexAddr = toHex(strAddr);
        printf("%04xH : %02x\n\n", hexAddr, memory[hexAddr]);

        printf("Enter address\n>>> ");
        scanf("%s", strAddr);
    }
    
    free(memory);
    close(fd);
    return 0;
}
