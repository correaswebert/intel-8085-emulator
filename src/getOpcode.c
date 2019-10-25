#include "prototypes.h"

/* pass file's fd or stdin as per user request
 *
 * first always read 1byte (opcode)
 * then depending on type,
 * read 0-2 bytes
 */
instruction getInstruction(int fd)
{
    /* index of current location */
    // static int index;        /* not needed as file handling takes care of it */
    instruction inst;

    /* read opcode (1byte) */
    read(fd, &inst.opcode, 1);

    /* if opcode is invalid, set type to ERR */
    inst.type = getDatatype(inst.opcode);

    /* according to datatype, read 1 or 2 bytes */
    switch (inst.type)
    {
        case DATA1:
            read(fd, inst.bytes.one, 1);
            break;
        
        case DATA2:
            read(fd, inst.bytes.two, 2);
            break;
        
        case ADDR:
            read(fd, inst.bytes.two, 2);
            break;
        
        /* VOID and ERR do nothing */
        default:
            break;
    }
    return inst;
}