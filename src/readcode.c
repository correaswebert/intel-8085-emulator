#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#include <unistd.h>

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "getNumberOfBytes.c"
#include "hex2mneumonic.h"
#include "instruction_struct.h"
#include "toHex.c"


int printInstruction(int fd, int prog_addr)
{
    instruction inst;
    int next;

    while (1)
    {
        /* read opcode (1byte) */
        next = read(fd, &inst.opcode, 1);
        if (next == 0)
            return 0;

        printf("%04x : ", prog_addr);
        prog_addr++;

        /* if opcode is invalid, set type to ERR */
        inst.type = numberBytesToRead(inst.opcode);

        /* according to datatype, read 1 or 2 bytes */
        switch (inst.type)
        {
            case BYTES1:
                read(fd, &inst.bytes.one, 1);
                prog_addr++;
                break;
            
            case BYTES2:
                read(fd, &inst.bytes.two, 2);
                prog_addr += 2;
                break;
            
            /* BYTES0 and ERR do nothing */
            default:
                break;
        }

        if (inst.type == BYTES0)
            printf("%s\n", opcodes[inst.opcode]);
        else if (inst.type == BYTES1)
            printf("%s %02xH\n", opcodes[inst.opcode], inst.bytes.one);
        else if (inst.type == BYTES2)
            printf("%s %04xH\n", opcodes[inst.opcode], inst.bytes.two);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2)
    {
        errno = EINVAL;
        perror("bad arguments");
        return errno;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open failed");
        return errno;
    }

    unsigned char ch;
    while(read(fd, &ch, 1))
        printf("%02x ", ch);
    printf("\n\n");

    lseek(fd, 0, SEEK_SET);
    
    // if address provided, start from there, else from 0000H
    if (argc == 3)
        printInstruction(fd, toHex(argv[2]));
    else
        printInstruction(fd, 0);
    
    close(fd);
    return 0;
}
