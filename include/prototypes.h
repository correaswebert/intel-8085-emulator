#ifndef PROTOTYPES
#define PROTOTYPES

#include <stdlib.h>

#include "CPU.h"
#include "instruction_struct.h"

#define CONTINUE 0
#define STOP 1
#define ERROR 2

// pointer to 2^16 bytes storage
uint8_t *memory;

/* load user code in the memory, starting from the given address */
void loadCode(int, uint16_t);

/* arg int can be:
 * - File Descriptor
 * - Alias for stdin
 */
instruction getInstruction(int);

/* check for datatype of 1 byte opcode */
enum datatype numberBytesToRead(uint8_t);

// Functions
void add(uint8_t, uint8_t);
void subtract(uint8_t, uint8_t);
void increment(uint8_t *, uint8_t *);
void decrement(uint8_t *, uint8_t *);
void decimalAdjustAcc();
void doubleAdd(uint8_t, uint8_t);

void loadAcc(uint8_t, uint8_t);
void storeAcc(uint8_t, uint8_t);

void bitwiseAnd(uint8_t);
void bitwiseOr(uint8_t);
void bitwiseXor(uint8_t);

void rotateLeft(uint8_t);
void rotateRight(uint8_t);

void compareWithAcc(uint8_t);

void updateFlags(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
void adjustFlags(uint8_t, uint8_t);

uint8_t checkAuxCarry(uint8_t, uint8_t);
uint8_t checkParity();

void pushToStack(uint8_t, uint8_t);
void popFromStack(uint8_t *, uint8_t *);

void callSubroutine(uint16_t);
void returnToMain(void);

void swap(uint8_t *, uint8_t *);

#endif // PROTOTYPES