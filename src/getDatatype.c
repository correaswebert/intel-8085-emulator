#include "prototypes.h"

/* make three arrays (of ints)
 * one for data type
 * second for address type
 * third for long data type
 * and check in which array does opcode lie in
 */
enum datatype getDatatype(char opcode)
{
    int index = searchInOpcodes(opcode);
    int mode = mode_group[index][0];
    int group = mode_group[index][1];
}