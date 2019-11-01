#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

#include "compilation.c"

void printCPU()
{
    printf("PSW: %2x %2x\n", A, F);
    printf("BC:  %2x %2x\n", B, C);
    printf("DE:  %2x %2x\n", D, E);
    printf("HL:  %2x %2x\n", H, L);
    printf("SP:  %4x\n", stack_ptr);
    printf("PC:  %4x\n", prog_cntr);
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

    uint16_t prog_cntr = atoi(argv[2]);
    // if (argv[2][0] == '-')
    //     prog_cntr = 0x0000;
    // else
    //     prog_cntr = atoi(argv[2]);
    
    printf("Loading code...\n");
    loadCode(fd, prog_cntr);
    printf("Code loaded!\n\n");
    char next = 4;

    uint8_t hexcode;
    uint16_t prog_addr = prog_cntr;
    while (next--)
    {
        printf("%x ", memory[prog_addr++]);
        scanf("%d", &next);
    }
    printf("\n");
    

    int stepwise = 0;
    printf("Do you want to go step-wise? (0/1)\n>>> ");
    scanf("%d", &stepwise);


    while (state == CONTINUE)
    {
        if(stepwise)
            scanf("%c", &next);
        
        inst = getInstruction(fd);
        state = performInstruction(inst);
        // printf("state: %d\n", state);
        // printf("code:  %x\n", inst.opcode);
        // printf("type:  %x\n", inst.type);
        // if (inst.type == BYTES1)
        //     printf("bytes: %x\n", inst.bytes.one);
        // else if (inst.type == BYTES2)
        //     printf("bytes: %x\n", inst.bytes.two);
        
        printf("Instruction executed!\n");
        prog_cntr++;
    }

    printCPU();
    
    return 0;
}
