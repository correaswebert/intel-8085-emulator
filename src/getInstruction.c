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
    read(fd, &inst.opcode, 1);

    /* if opcode is invalid, set type to ERR */
    inst.type = numberBytesToRead(inst.opcode);

    /* according to datatype, read 1 or 2 bytes */
    switch (inst.type)
    {
        case BYTES1:
            read(fd, inst.bytes.one, 1);
            break;
        
        case BYTES2:
            read(fd, inst.bytes.two, 2);
            break;
        
        /* BYTES0 and ERR do nothing */
        default:
            break;
    }
    
    return inst;
}