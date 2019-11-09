#include "compilation.c"


void printCPU()
{
    printf("A: 0x%02x    B: 0x%02x    D: 0x%02x    H: 0x%02x\n", A, B, D, H);
    printf("F: 0x%02x    C: 0x%02x    E: 0x%02x    L: 0x%02x\n", F, C, E, L);
    printf("\n");

    printf("PC: 0x%04x\n", prog_cntr);
    printf("SP: 0x%04x\n", stack_ptr);
    printf("\n");

    // if flag is set, display in bold yellow color
    printf("%sS\t",  (F & S_MASK)  ? "\e[1;33m" : "\e[00m");
    printf("%sZ\t",  (F & Z_MASK)  ? "\e[1;33m" : "\e[00m");
    printf("%sAC\t", (F & AC_MASK) ? "\e[1;33m" : "\e[00m");
    printf("%sP\t",  (F & P_MASK)  ? "\e[1;33m" : "\e[00m");
    printf("%sCY\n", (F & CY_MASK) ? "\e[1;33m" : "\e[00m");

    // reset the colors back
    printf("\e[00m\n");
}


int main(int argc, char const *argv[])
{
    // every argument of form : ... codeX addrX ...
    if ((argc - 1) % 2 != 0)
    {
        errno = EINVAL;
        perror("invalid arguments!");
        return errno;
    }
    
    // ---------------------- Initialize variables needed ----------------------

    // temporary variable for self added breakpoints
    char next;

    instruction inst;
    uint16_t prog_cntr;

    // state after each instruction
    uint8_t state = CONTINUE;

    // memory of 2^16 bytes
    memory = (uint8_t *) malloc(65536);

    // data, address holders
    char strAddr[5], strData[3];
    uint16_t hexAddr;

    // for breaking code run into steps
    int stepwise = 0;



    // -------------------- Load all given files in memory --------------------
    int fd, num_files = (argc - 1) / 2, i = 1;
    while (i <= num_files)
    {
        printf("Loading %s @ %s...\n", argv[2*i - 1], argv[2*i]);

        if (!strstr(argv[2*i - 1], ".mc"))
        {
            errno = EINVAL;
            printf("invalid file type - %s\n", argv[2*i - 1]);
            return errno;
        }
        if (strlen(argv[2*i]) > 4)
        {
            errno = EINVAL;
            printf("invalid address - %s\n", argv[2*i]);
            return errno;
        }

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
    scanf("%c", &next);
    
    

    // --------------------- Manually load data in memory ---------------------
    system("clear");
    printf("Enter ADDR <ENTER> DATA\n");
    while (1)
    {
        system("clear");
        printf("%04xH : %02x\n\n", hexAddr, memory[hexAddr]);

        // print usage hints
        printf("Enter (ADDR = p) for prev addr\n");
        printf("Enter (ADDR = n) for next addr\n");
        printf("Enter (ADDR = q) to quit\n\n");

        printf("addr >>> ");
        scanf("%s", strAddr);

        if (!strcmp("q", strAddr))
            break;
        
        // relative address given
        else if (!strcmp("p", strAddr))
            hexAddr--;
        else if (!strcmp("n", strAddr))
            hexAddr++;
        
        // absolute address given
        else
            hexAddr = toHex(strAddr);
        
        printf("data >>> ");
        scanf("%s", strData);

        // enter the given data in memory at given address
        memory[hexAddr] = toHex(strData);
    }
    

    system("clear");
    printf("Intializing CPU...\n");
    printCPU();



    // ------------------------------- Run code -------------------------------
    printf("Do you want to go step-wise? (0/1)\n>>> ");
    scanf("%d", &stepwise);
    system("clear");


    while (state == CONTINUE)
    {
        // continue the remaining code without stepwise iteration
        if (next == 'c')
        {
            stepwise = 0;
            system("clear");
        }
        
        if (stepwise)
            scanf("%c", &next);

        inst = getInstruction(fd);
        state = performInstruction(inst);
        
        // print current instruction CPU state
        if(stepwise)
        {
            system("clear");

            // check type of instruction, and print accrdingly
            if (inst.type == BYTES0)
                printf("instruction:  %s\n", opcodes[inst.opcode]);
            else if (inst.type == BYTES1)
                printf("instruction:  %s  %02xH\n", opcodes[inst.opcode], inst.bytes.one);
            else if (inst.type == BYTES2)
                printf("instruction:  %s  %04xH\n", opcodes[inst.opcode], inst.bytes.two);
            
            printCPU();
        }
        
        // goto the next instruction
        prog_cntr++;
    }

    if (!stepwise)
        printCPU();
    printf("Final State...\n");



    // ----------------------------- Check memory -----------------------------
    strAddr[0] = '\0';      // reset the string (for while loop condition)
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
