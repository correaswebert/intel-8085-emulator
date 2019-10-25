#include "instruction_struct.h"

/* int can be:
 *      1. File Descriptor
 *      2. Alias for stdin
 */
instruction getOpcode(int);

/* check for datatype of 1 byte opcode */
enum datatype getDatatype(char);