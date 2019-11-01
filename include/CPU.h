#ifndef CPU
#define CPU

#include <stdint.h>

/* registers
 * pairs -> BC DE HL
 * A(ccumulator) F(lag)
 * psw -> A higher, F lower
 */
uint8_t A, B, C, D, E, F, H, L;

/* Flag -> |  S |  Z |  X | AC |  X |  P |  X | CY |
 * Sign
 *  - S = 0 => Plus
 *  - S = 1 => Minus
 * Zero
 *  - Z = 0 => Not Zero
 *  - Z = 1 => Zero
 * Auxilary Carry
 *  - AC = 0 => No carry from A3 to A4
 *  - AC = 0 => Carry from A3 to A4
 * Parity
 *  - P = 0 => Odd
 *  - P = 1 => Even
 * Carry
 *  - CY = 0 => No Carry
 *  - CY = 1 => Carry
 */

/* stack pointer 
 * it points to the top of the stack, where data exists
 * hence the top of the stack always has meaningless data initially
 * 8085 has a reverse stack, hence SP starts at 0xFFFF
 */
uint16_t stack_ptr = 0xffff;

/* program counter
 * this register stores the address of current instruction (opcode)
 * on completion of instruction, it auto-increments
 */
uint16_t prog_cntr;

// Masks to extract the respective bit
const uint8_t CY_MASK = 0x01; // 00000001;
const uint8_t P_MASK  = 0x04; // 00000100;
const uint8_t AC_MASK = 0x10; // 00010000;
const uint8_t Z_MASK  = 0x40; // 01000000;
const uint8_t S_MASK  = 0x80; // 10000000;

#endif // CPU
