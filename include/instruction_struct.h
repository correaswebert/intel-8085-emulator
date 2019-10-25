/* ???
 * how to handle 2 byte data
 * FIX
 * 1. create a flag for addr to be treated as data
 * 2. create new datatype -> long data
 */

/* VOID for 0 byte data
 * DATA1 for 1 byte data
 * DATA2 for 2 byte data
 * ADDR for 2 bytes
 * ERR if opcode invalid
 */
enum datatype {VOID, DATA1, DATA2, ADDR, ERR};

/* instruction should contain:
 *      1. Opcode
 *      2. Data/Address
 */
typedef struct instruction
{
    char opcode;
    enum datatype type;
    union bytes
    {
        char one;
        short int two;
    } bytes;
} instruction;