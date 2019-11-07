#include "prototypes.h"

/* pass file's fd or stdin as per user request
 *
 * first always read 1byte (opcode)
 * then depending on type,
 * read 0-2 bytes
 */
instruction getInstruction(int fd)
{
    instruction inst;

    /* read opcode (1byte) */
    // read(fd, &inst.opcode, 1);
    inst.opcode = memory[prog_cntr++];

    /* if opcode is invalid, set type to ERR */
    inst.type = numberBytesToRead(inst.opcode);

    /* according to datatype, read 1 or 2 bytes */
    switch (inst.type)
    {
        case BYTES1:
            // read(fd, inst.bytes.one, 1);
            inst.bytes.one = memory[prog_cntr++];
            break;
        
        case BYTES2:
            // read(fd, inst.bytes.two, 2);
            inst.bytes.two = (memory[prog_cntr++] << 8) | memory[prog_cntr++];
            break;
        
        /* BYTES0 and ERR do nothing */
        default:
            break;
    }
    
    return inst;
}


void loadCode(int fd, uint16_t prog_addr)
{
    prog_cntr = prog_addr;
    
    uint8_t opcode, type, one;
    uint16_t two;


    char next;
    while (opcode != 0x76)
    {
        /* read opcode (1byte) */
        read(fd, &opcode, 1);
        memory[prog_addr++] = opcode;

        /* if opcode is invalid, set type to ERR */
        type = numberBytesToRead(opcode);

        /* according to datatype, read 1 or 2 bytes */
        switch (type)
        {
            case BYTES1:
                read(fd, &one, 1);
                memory[prog_addr++] = one;
                break;
            
            case BYTES2:
                read(fd, &two, 2);
                memory[prog_addr++] = two >> 8;
                memory[prog_addr++] = two;
                break;
            
            /* BYTES0 and ERR do nothing */
            default:
                break;
        }

        // display the instruction being loaded...
        if (type == BYTES0)
            printf("\t0x%04x:  %02x\n", prog_addr - 1, opcode);
        else if (type == BYTES1)
            printf("\t0x%04x:  %02x  %02x\n", prog_addr - 2, opcode, one);
        else if (type == BYTES2)
            printf("\t0x%04x:  %02x  %02x  %02x\n", prog_addr - 3, opcode, two & 0xff, (two >> 8) & 0xff);
        scanf("%c", &next);
    }
}