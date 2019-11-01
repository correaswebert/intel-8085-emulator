#ifndef INSTRUCTION_STRUCT
#define INSTRUCTION_STRUCT

#include <stdint.h>

enum datatype {BYTES0, BYTES1, BYTES2, ERR};

/* instruction should contain:
 * - Opcode
 * - Type
 * - Data/Address
 */
typedef struct instruction
{
    uint8_t opcode;
    enum datatype type;
    union bytes
    {
        uint8_t one;
        uint16_t two;
    } bytes;
} instruction;

#endif // INSTRUCTION_SET