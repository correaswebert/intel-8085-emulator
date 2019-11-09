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
    
    uint8_t opcode = 0, type, one;
    uint16_t two;

    while (
        opcode != 0x76 &&   /* HLT */
        opcode != 0xC9 &&   /* RET */
        opcode != 0xC0 &&   /* RNZ */
        opcode != 0xC8 &&   /* RZ  */
        opcode != 0xD0 &&   /* RNC */
        opcode != 0xD8 &&   /* RC  */
        opcode != 0xE8 &&   /* RPE */
        opcode != 0xE0 &&   /* RPO */
        opcode != 0xF0 &&   /* RP  */
        opcode != 0xF8      /* RM  */
    )
    {
        /* read opcode (1byte) */
        read(fd, &opcode, 1);
        memory[prog_addr++] = opcode;
        printf("%02x ", opcode);

        /* if opcode is invalid, set type to ERR */
        type = numberBytesToRead(opcode);

        /* according to datatype, read 1 or 2 bytes */
        switch (type)
        {
            case BYTES1:
                read(fd, &one, 1);
                memory[prog_addr++] = one;
                printf("%02x ", one);
                break;
            
            case BYTES2:
                read(fd, &two, 2);
                memory[prog_addr++] = two >> 8;
                memory[prog_addr++] = two;
                printf("%02x ", two);
                break;
            
            /* BYTES0 and ERR do nothing */
            default:
                break;
        }

        printf("\n");
    }
}