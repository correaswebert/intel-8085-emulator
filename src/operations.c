#include "prototypes.h"

#define M memory[((uint16_t) H << 8) | L]

uint8_t performInstruction(instruction inst)
{
    switch (inst.opcode)
    {
        // ----------------------------------------------------------------- //
        // ---------------------- Data Transfer Group ---------------------- //
        // ----------------------------------------------------------------- //
        // MVI
        case 0x3E:
            A = inst.bytes.one;
            adjustFlags(-1, -1);
            break;
        case 0x06:
            B = inst.bytes.one;
            break;
        case 0x0E:
            C = inst.bytes.one;
            break;
        case 0x16:
            D = inst.bytes.one;
            break;
        case 0x1E:
            E = inst.bytes.one;
            break;
        case 0x26:
            H = inst.bytes.one;
            break;
        case 0x2E:
            L = inst.bytes.one;
            break;
        case 0x36:
            M = inst.bytes.one;
            break;

        // MOV A, R
        case 0x7F:
            A = A;
            adjustFlags(-1, -1);
            break;
        case 0x78:
            A = B;
            adjustFlags(-1, -1);
            break;
        case 0x79:
            A = C;
            adjustFlags(-1, -1);
            break;
        case 0x7A:
            A = D;
            adjustFlags(-1, -1);
            break;
        case 0x7B:
            A = E;
            adjustFlags(-1, -1);
            break;
        case 0x7C:
            A = H;
            adjustFlags(-1, -1);
            break;
        case 0x7D:
            A = L;
            adjustFlags(-1, -1);
            break;
        case 0x7E:
            A = M;
            adjustFlags(-1, -1);
            break;

        // MOV B, R
        case 0x47:
            B = A;
            break;
        case 0x40:
            B = B;
            break;
        case 0x41:
            B = C;
            break;
        case 0x42:
            B = D;
            break;
        case 0x43:
            B = E;
            break;
        case 0x44:
            B = H;
            break;
        case 0x45:
            B = L;
            break;
        case 0x46:
            B = M;
            break;

        // MOV C, R
        case 0x4F:
            C = A;
            break;
        case 0x48:
            C = B;
            break;
        case 0x49:
            C = C;
            break;
        case 0x4A:
            C = D;
            break;
        case 0x4B:
            C = E;
            break;
        case 0x4C:
            C = H;
            break;
        case 0x4D:
            C = L;
            break;
        case 0x4E:
            C = M;
            break;

        // MOV D, R
        case 0x57:
            D = A;
            break;
        case 0x50:
            D = B;
            break;
        case 0x51:
            D = C;
            break;
        case 0x52:
            D = D;
            break;
        case 0x53:
            D = E;
            break;
        case 0x54:
            D = H;
            break;
        case 0x55:
            D = L;
            break;
        case 0x56:
            D = M;
            break;

        // MOV E, R
        case 0x5F:
            E = A;
            break;
        case 0x58:
            E = B;
            break;
        case 0x59:
            E = C;
            break;
        case 0x5A:
            E = D;
            break;
        case 0x5B:
            E = E;
            break;
        case 0x5C:
            E = H;
            break;
        case 0x5D:
            E = L;
            break;
        case 0x5E:
            E = M;
            break;

        // MOV H, R
        case 0x67:
            H = A;
            break;
        case 0x60:
            H = B;
            break;
        case 0x61:
            H = C;
            break;
        case 0x62:
            H = D;
            break;
        case 0x63:
            H = E;
            break;
        case 0x64:
            H = H;
            break;
        case 0x65:
            H = L;
            break;
        case 0x66:
            H = M;
            break;

        // MOV L, R
        case 0x6F:
            L = A;
            break;
        case 0x68:
            L = B;
            break;
        case 0x69:
            L = C;
            break;
        case 0x6A:
            L = D;
            break;
        case 0x6B:
            L = E;
            break;
        case 0x6C:
            L = H;
            break;
        case 0x6D:
            L = L;
            break;
        case 0x6E:
            L = M;
            break;

        // MOV M, R
        case 0x77:
            M = A;
            break;
        case 0x70:
            M = B;
            break;
        case 0x71:
            M = C;
            break;
        case 0x72:
            M = D;
            break;
        case 0x73:
            M = E;
            break;
        case 0x74:
            M = H;
            break;
        case 0x75:
            M = L;
            break;

        // LXI reg. pair
        case 0x01:
            C = inst.bytes.two;
            inst.bytes.two >>= 8;
            B = inst.bytes.two;
            break;
        
        case 0x11:
            E = inst.bytes.two;
            inst.bytes.two >>= 8;
            D = inst.bytes.two;
            break;
        
        case 0x21:
            L = inst.bytes.two;
            inst.bytes.two >>= 8;
            H = inst.bytes.two;
            break;
        
        case 0x31:
            stack_ptr = inst.bytes.two;
            break;

        // load accumulator
        case 0x0A:
            loadAcc(B, C);
            break;
        case 0x1A:
            loadAcc(B, C);
            break;
        case 0x3A:
            loadAcc(inst.bytes.two << 8, inst.bytes.two);
            break;

        // store accumulator
        case 0x32:
            storeAcc(inst.bytes.two << 8, inst.bytes.two);
            break;
        case 0x02:
            storeAcc(B, C);
            break;
        case 0x12:
            storeAcc(D, E);
            break;

        // LHLD
        case 0x2A:
            L = memory[inst.bytes.two++];
            H = memory[inst.bytes.two];
            break;

        // SHLD
        case 0x22:
            memory[inst.bytes.two++] = L;
            memory[inst.bytes.two] = H;
            break;

        // XCHG
        case 0xEB:
            swap(&D, &H);
            swap(&E, &L);
            break;

        // ----------------------------------------------------------------- //
        // ----------------------- Arithematic Group ----------------------- //
        // ----------------------------------------------------------------- //
        // ADD reg.
        case 0x87:
            add(A, 0);
            break;
        case 0x80:
            add(B, 0);
            break;
        case 0x81:
            add(C, 0);
            break;
        case 0x82:
            add(D, 0);
            break;
        case 0x83:
            add(E, 0);
            break;
        case 0x84:
            add(H, 0);
            break;
        case 0x85:
            add(L, 0);
            break;
        case 0x86:
            add(M, 0);
            break;

        // ADC reg.
        case 0x8F:
            add(A, 1);
            break;
        case 0x88:
            add(B, 1);
            break;
        case 0x89:
            add(C, 1);
            break;
        case 0x8A:
            add(D, 1);
            break;
        case 0x8B:
            add(E, 1);
            break;
        case 0x8C:
            add(H, 1);
            break;
        case 0x8D:
            add(L, 1);
            break;
        case 0x8E:
            add(M, 1);
            break;
        
        // ADI data
        case 0xC6:
            add(inst.bytes.one, 0);
            break;

        // ACI data
        case 0xCE:
            add(inst.bytes.one, 1);
            break;
        

        // SUB reg.
        case 0x97:
            subtract(A, 0);
            break;
        case 0x90:
            subtract(B, 0);
            break;
        case 0x91:
            subtract(C, 0);
            break;
        case 0x92:
            subtract(D, 0);
            break;
        case 0x93:
            subtract(E, 0);
            break;
        case 0x94:
            subtract(H, 0);
            break;
        case 0x95:
            subtract(L, 0);
            break;
        case 0x96:
            subtract(M, 0);
            break;

        // SBB reg.
        case 0x9F:
            subtract(A, 1);
            break;
        case 0x98:
            subtract(B, 1);
            break;
        case 0x99:
            subtract(C, 1);
            break;
        case 0x9A:
            subtract(D, 1);
            break;
        case 0x9B:
            subtract(E, 1);
            break;
        case 0x9C:
            subtract(H, 1);
            break;
        case 0x9D:
            subtract(L, 1);
            break;
        case 0x9E:
            subtract(M, 1);
            break;
        
        // SUI data
        case 0xD6:
            subtract(inst.bytes.one, 0);
            break;

        // SBI data
        case 0xDE:
            subtract(inst.bytes.one, 1);
            break;

        // INR reg.
        case 0x3C:
            increment(&A, NULL);
            break;
        case 0x04:
            increment(&B, NULL);
            break;
        case 0x0C:
            increment(&C, NULL);
            break;
        case 0x14:
            increment(&D, NULL);
            break;
        case 0x1C:
            increment(&E, NULL);
            break;
        case 0x24:
            increment(&H, NULL);
            break;
        case 0x2C:
            increment(&L, NULL);
            break;
        case 0x34:
            increment(&M, NULL);
            break;

        case 0x03:
            increment(&B, &C);
            break;
        case 0x13:
            increment(&D, &E);
            break;
        case 0x23:
            increment(&H, &L);
            break;
        case 0x33:
            stack_ptr = stack_ptr + 1;
            break;

        // DCR reg.
        case 0x3D:
            decrement(&A, NULL);
            break;
        case 0x05:
            decrement(&B, NULL);
            break;
        case 0x0D:
            decrement(&C, NULL);
            break;
        case 0x15:
            decrement(&D, NULL);
            break;
        case 0x1D:
            decrement(&E, NULL);
            break;
        case 0x25:
            decrement(&H, NULL);
            break;
        case 0x2D:
            decrement(&L, NULL);
            break;
        case 0x35:
            decrement(&M, NULL);
            break;

        case 0x0B:
            decrement(&B, &C);
            break;
        case 0x1B:
            decrement(&D, &E);
            break;
        case 0x2B:
            decrement(&H, &L);
            break;
        case 0x3B:
            stack_ptr = stack_ptr - 1;
            // update flags
            // FIX: void adjustFlags(uint16_t *reg);
            // if NULL then A
            // cast if single register needed
            break;

        case 0x09:
            doubleAdd(B, C);
            break;
        case 0x19:
            doubleAdd(D, E);
            break;
        case 0x29:
            doubleAdd(H, L);
            break;
        case 0x39:
            doubleAdd(stack_ptr >> 8, stack_ptr);
            break;

        case 0x27:
            decimalAdjustAcc();
            break;


        // ----------------------------------------------------------------- //
        // ------------------------- Logical Group ------------------------- //
        // ----------------------------------------------------------------- //
        case 0xA7:
            bitwiseAnd(A);
            break;
        case 0xA0:
            bitwiseAnd(B);
            break;
        case 0xA1:
            bitwiseAnd(C);
            break;
        case 0xA2:
            bitwiseAnd(D);
            break;
        case 0xA3:
            bitwiseAnd(E);
            break;
        case 0xA4:
            bitwiseAnd(H);
            break;
        case 0xA5:
            bitwiseAnd(L);
            break;
        case 0xA6:
            bitwiseAnd(M);
            break;
        case 0xE6:
            bitwiseAnd(inst.bytes.one);
            break;

        case 0xAF:
            bitwiseXor(A);
            break;
        case 0xA8:
            bitwiseXor(B);
            break;
        case 0xA9:
            bitwiseXor(C);
            break;
        case 0xAA:
            bitwiseXor(D);
            break;
        case 0xAB:
            bitwiseXor(E);
            break;
        case 0xAC:
            bitwiseXor(H);
            break;
        case 0xAD:
            bitwiseXor(L);
            break;
        case 0xAE:
            bitwiseXor(M);
            break;
        case 0xEE:
            bitwiseXor(inst.bytes.one);
            break;

        case 0xB7:
            bitwiseOr(A);
            break;
        case 0xB0:
            bitwiseOr(B);
            break;
        case 0xB1:
            bitwiseOr(C);
            break;
        case 0xB2:
            bitwiseOr(D);
            break;
        case 0xB3:
            bitwiseOr(E);
            break;
        case 0xB4:
            bitwiseOr(H);
            break;
        case 0xB5:
            bitwiseOr(L);
            break;
        case 0xB6:
            bitwiseOr(M);
            break;
        case 0xF6:
            bitwiseOr(inst.bytes.one);
            break;

        case 0xBF:
            compareWithAcc(A);
            break;
        case 0xB8:
            compareWithAcc(B);
            break;
        case 0xB9:
            compareWithAcc(C);
            break;
        case 0xBA:
            compareWithAcc(D);
            break;
        case 0xBB:
            compareWithAcc(E);
            break;
        case 0xBC:
            compareWithAcc(H);
            break;
        case 0xBD:
            compareWithAcc(L);
            break;
        case 0xBE:
            compareWithAcc(M);
            break;
        case 0xFE:
            compareWithAcc(inst.bytes.one);
            break;

        // Rotate Accumulator
        case 0x07:
            rotateLeft(0);  // RLC
            break;
        case 0x17:
            rotateLeft(1);  // RAL
            break;
        case 0x0F:
            rotateRight(0); // RRC
            break;
        case 0x1F:
            rotateRight(1); // RAR
            break;

        // CMA
        case 0x2F:
            A = ~A;
            break;
        
        // CMC
        case 0x3F:
            if (F & CY_MASK)
                updateFlags(-1, -1, -1, -1, 0);
            else
                updateFlags(-1, -1, -1, -1, 1);
            break;
            
        // STC
        case 0x37:
            updateFlags(-1, -1, -1, -1, 1);
            break;
        
        // ------------------------------------------------------------------ //
        // ---------------------- Branch Control Group ---------------------- //
        // ------------------------------------------------------------------ //
        case 0xC3:      /* "JMP" */
            prog_cntr = inst.bytes.two;
            break;
        
        case 0xC2:      /* "JNZ" */
            if (~F & Z_MASK)
                prog_cntr = inst.bytes.two;
            break;
        case 0xCA:      /* "JZ" */
            if (F & Z_MASK)
                prog_cntr = inst.bytes.two;
            break;
        
        case 0xD2:      /* "JNC" */
            if (~F & CY_MASK)
                prog_cntr = inst.bytes.two;
            break;
        case 0xDA:      /* "JC" */
            if (F & CY_MASK)
                prog_cntr = inst.bytes.two;
            break;
        
        case 0xE2:      /* "JPO" */
            if (~F & P_MASK)
                prog_cntr = inst.bytes.two;
            break;
        case 0xEA:      /* "JPE" */
            if (F & P_MASK)
                prog_cntr = inst.bytes.two;
            break;
        
        case 0xF2:      /* "JP" */
            if (~F & S_MASK)
                prog_cntr = inst.bytes.two;
            break;
        case 0xFA:      /* "JM" */
            if (F & S_MASK)
                prog_cntr = inst.bytes.two;
            break;

        case 0xE9:      /* "PCHL" */
            prog_cntr = (H << 8) | L;
            break;

        case 0xCD:      /* "CALL" */
            callSubroutine(inst.bytes.two);
            break;

        case 0xC4:      /* "CNZ" */
            if (~F & Z_MASK)
                callSubroutine(inst.bytes.two);
            break;
        case 0xCC:      /* "CZ" */
            if (F & Z_MASK)
                callSubroutine(inst.bytes.two);
            break;

        case 0xD4:      /* "CNC" */
            if (~F & CY_MASK)
                callSubroutine(inst.bytes.two);
            break;
        case 0xDC:      /* "CC" */
            if (F & CY_MASK)
                callSubroutine(inst.bytes.two);
            break;

        case 0xE4:      /* "CPO" */
            if (~F & P_MASK)
                callSubroutine(inst.bytes.two);
            break;
        case 0xEC:      /* "CPE" */
            if (F & P_MASK)
                callSubroutine(inst.bytes.two);
            break;

        case 0xF4:      /* "CP" */
            if (~F & S_MASK)
                callSubroutine(inst.bytes.two);
            break;
        case 0xFC:      /* "CM" */
            if (F & S_MASK)
                callSubroutine(inst.bytes.two);
            break;

        case 0xC9:      /* "RET" */
            returnToMain();
            break;

        case 0xC0:      /* "RNZ" */
            if (~F & Z_MASK)
                returnToMain();
            break;
        case 0xC8:      /* "RZ" */
            if (F & Z_MASK)
                returnToMain();
            break;

        case 0xD0:      /* "RNC" */
            if (~F & CY_MASK)
                returnToMain();
            break;
        case 0xD8:      /* "RC" */
            if (F & CY_MASK)
                returnToMain();
            break;

        case 0xE0:      /* "RPO" */
            if (~F & P_MASK)
                returnToMain();
            break;
        case 0xE8:      /* "RPE" */
            if (F & P_MASK)
                returnToMain();
            break;

        case 0xF0:      /* "RP" */
            if (~F & S_MASK)
                returnToMain();
            break;
        case 0xF8:      /* "RM" */
            if (F & S_MASK)
                returnToMain();
            break;

        // Software interrupts - 1byte CALL to predefined addresses
        // Vector addresses: 0000, 0008, 0010, 0018, 0020, 0028, 0030, 0038
        case 0xC7:      /* "RST_0" */
            callSubroutine(0x0000);
            break;
        case 0xCF:      /* "RST_1" */
            callSubroutine(0x0008);
            break;
        case 0xD7:      /* "RST_2" */
            callSubroutine(0x0010);
            break;
        case 0xDF:      /* "RST_3" */
            callSubroutine(0x0018);
            break;
        case 0xE7:      /* "RST_4" */
            callSubroutine(0x0020);
            break;
        case 0xEF:      /* "RST_5" */
            callSubroutine(0x0028);
            break;
        case 0xF7:      /* "RST_6" */
            callSubroutine(0x0030);
            break;
        case 0xFF:      /* "RST_7" */
            callSubroutine(0x0038);
            break;


        // ----------------------------------------------------------------- //
        // ----------------- I/O and Machine Control Group ----------------- //
        // ----------------------------------------------------------------- //
        // PUSH
        case 0xC5:
            pushToStack(B, C);
            break;
        case 0xD5:
            pushToStack(D, E);
            break;
        case 0xE5:
            pushToStack(H, L);
            break;
        case 0xF5:
            pushToStack(A, F);
            break;

        // POP
        case 0xC1:
            popFromStack(&B, &C);
            break;
        case 0xD1:
            popFromStack(&D, &E);
            break;
        case 0xE1:
            popFromStack(&H, &L);
            break;
        case 0xF1:
            popFromStack(&A, &F);
            // update the flags
            break;

        // SPHL - HL -> SP
        case 0xF9:
            stack_ptr = H;
            stack_ptr <<= 8;
            stack_ptr |= L;
            break;
        
        // XTHL - HL <-> SP
        case 0xE3:
            swap(&L, &memory[stack_ptr]);
            swap(&H, &memory[stack_ptr + 1]);
            break;

        case 0xD3:
            // "OUT"
            break;
        case 0xDB:
            // "IN"
            break;

        // Enable/Disable interrupts
        case 0xF3:
            // "DI"
            break;
        case 0xFB:
            // "EI"
            break;
        
        // HLT
        case 0x76:
            return STOP;
            break;
        // NOP
        case 0x00:
            break;

        // Read/Set Interrupt Mask (https://www.tutorialspoint.com/sim-and-rim-instructions-in-8085)
        case 0x20:
            // "RIM"
            break;
        case 0x30:
            // "SIM"
            break;

        default:
            return ERROR;
            break;
    }
    return CONTINUE;
}