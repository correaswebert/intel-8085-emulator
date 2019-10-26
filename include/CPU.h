#include <stdint.h>

/* registers
 * pairs -> BC DE HL
 * A(ccumulator) F(lag)
 */
uint8_t A, B, C, D, E, F, H, L;
// psw => A higher, F lower

/* Flag -> |  S |  Z |  X | AC |  X |  P |  X | CY |
 * Sign
 *  - S = 0 => Plus
 *  - S = 1 => Minus
 * Zero
 *  - Z = 0 => Not Zero
 *  - Z = 1 => Zero
 * Auxilary Carry
 *  - 
 *  - 
 * Parity
 *  - P = 0 => Odd
 *  - P = 1 => Even
 * Carry
 *  - CY = 0 => No Carry
 *  - CY = 1 => Carry
 */

/* ???: how is recursion handled
 * SP stores only one address location of return at a time
 * in case of recursion, multiple return locations are to be saved
 */

/* stack pointer 
 * if subroutine called, then
 * Main program's current instruction location is saved here
 * so that on return it can resume the Main program
 */
uint16_t stack_ptr;

/* program counter
 * this register stores the address of current instruction (opcode)
 * on completion of instruction, it auto-increments
 */
uint16_t prog_cntr;

const unint8_t CY_MASK = 00000001;
const unint8_t P_MASK  = 00000100;
const unint8_t AC_MASK = 00010000;
const unint8_t Z_MASK  = 01000000;
const unint8_t S_MASK  = 10000000;
