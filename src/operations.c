#include "prototypes.h"

switch (inst.opcode)
{
    // --------------------------------------------------------------------- //
    // ------------------------ Data Transfer Group ------------------------ //
    // --------------------------------------------------------------------- //
    // MVI
    case 0x3E:
        move(&A, NULL, inst.bytes.one);
        break;
    case 0x06:
        move(&B, NULL, inst.bytes.one);
        break;
    case 0x0E:
        move(&C, NULL, inst.bytes.one);
        break;
    case 0x16:
        move(&D, NULL, inst.bytes.one);
        break;
    case 0x1E:
        move(&E, NULL, inst.bytes.one);
        break;
    case 0x26:
        move(&H, NULL, inst.bytes.one);
        break;
    case 0x2E:
        move(&L, NULL, inst.bytes.one);
        break;
    case 0x36:
        move(&M, NULL, inst.bytes.one);
        break;

    // MOV A, R
    case 0x7F:
        move(&A, &A, 0);
        break;
    case 0x78:
        move(&A, &B, 0);
        break;
    case 0x79:
        move(&A, &C, 0);
        break;
    case 0x7A:
        move(&A, &D, 0);
        break;
    case 0x7B:
        move(&A, &E, 0);
        break;
    case 0x7C:
        move(&A, &H, 0);
        break;
    case 0x7D:
        move(&A, &L, 0);
        break;
    case 0x7E:
        move(&A, &M, 0);
        break;

    // MOV B, R
    case 0x47:
        move(&B, &A, 0);
        break;
    case 0x40:
        move(&B, &B, 0);
        break;
    case 0x41:
        move(&B, &C, 0);
        break;
    case 0x42:
        move(&B, &D, 0);
        break;
    case 0x43:
        move(&B, &E, 0);
        break;
    case 0x44:
        move(&B, &H, 0);
        break;
    case 0x45:
        move(&B, &L, 0);
        break;
    case 0x46:
        move(&B, &M, 0);
        break;

    // MOV C, R
    case 0x4F:
        move(&C, &A, 0);
        break;
    case 0x48:
        move(&C, &B, 0);
        break;
    case 0x49:
        move(&C, &C, 0);
        break;
    case 0x4A:
        move(&C, &D, 0);
        break;
    case 0x4B:
        move(&C, &E, 0);
        break;
    case 0x4C:
        move(&C, &H, 0);
        break;
    case 0x4D:
        move(&C, &L, 0);
        break;
    case 0x4E:
        move(&C, &M, 0);
        break;

    // MOV D, R
    case 0x57:
        move(&D, &A, 0);
        break;
    case 0x50:
        move(&D, &B, 0);
        break;
    case 0x51:
        move(&D, &C, 0);
        break;
    case 0x52:
        move(&D, &D, 0);
        break;
    case 0x53:
        move(&D, &E, 0);
        break;
    case 0x54:
        move(&D, &H, 0);
        break;
    case 0x55:
        move(&D, &L, 0);
        break;
    case 0x56:
        move(&D, &M, 0);
        break;

    // MOV E, R
    case 0x5F:
        move(&E, &A, 0);
        break;
    case 0x58:
        move(&E, &B, 0);
        break;
    case 0x59:
        move(&E, &C, 0);
        break;
    case 0x5A:
        move(&E, &D, 0);
        break;
    case 0x5B:
        move(&E, &E, 0);
        break;
    case 0x5C:
        move(&E, &H, 0);
        break;
    case 0x5D:
        move(&E, &L, 0);
        break;
    case 0x5E:
        move(&E, &M, 0);
        break;

    // MOV H, R
    case 0x67:
        move(&H, &A, 0);
        break;
    case 0x60:
        move(&H, &B, 0);
        break;
    case 0x61:
        move(&H, &C, 0);
        break;
    case 0x62:
        move(&H, &D, 0);
        break;
    case 0x63:
        move(&H, &E, 0);
        break;
    case 0x64:
        move(&H, &H, 0);
        break;
    case 0x65:
        move(&H, &L, 0);
        break;
    case 0x66:
        move(&H, &M, 0);
        break;

    // MOV L, R
    case 0x6F:
        move(&L, &A, 0);
        break;
    case 0x68:
        move(&L, &B, 0);
        break;
    case 0x69:
        move(&L, &C, 0);
        break;
    case 0x6A:
        move(&L, &D, 0);
        break;
    case 0x6B:
        move(&L, &E, 0);
        break;
    case 0x6C:
        move(&L, &H, 0);
        break;
    case 0x6D:
        move(&L, &L, 0);
        break;
    case 0x6E:
        move(&L, &M, 0);
        break;

    // MOV M, R
    case 0x77:
        move(&M, &A, 0);
        break;
    case 0x70:
        move(&M, &B, 0);
        break;
    case 0x71:
        move(&M, &C, 0);
        break;
    case 0x72:
        move(&M, &D, 0);
        break;
    case 0x73:
        move(&M, &E, 0);
        break;
    case 0x74:
        move(&M, &H, 0);
        break;
    case 0x75:
        move(&M, &L, 0);
        break;

    1,      /* 01 */    "LXI_B",
    17,     /* 11 */    "LXI_D",
    33,     /* 21 */    "LXI_H",
    49,     /* 31 */    "LXI_SP",

    58,     /* 3A */    "LDA",
    50,     /* 32 */    "STA",

    42,     /* 2A */    "LHLD",
    34,     /* 22 */    "SHLD",

    10,     /* 0A */    "LDAX_B",
    26,     /* 1A */    "LDAX_D",

    2,      /* 02 */    "STAX_B",
    18,     /* 12 */    "STAX_D",

    235,    /* EB */    "XCHG"

    // --------------------------------------------------------------------- //
    // ------------------------- Arithematic Group ------------------------- //
    // --------------------------------------------------------------------- //
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
        char M;     // obtain data from HL location here
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
        char M;     // obtain data from HL location here
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
        sub(A, 0);
        break;
    case 0x90:
        sub(B, 0);
        break;
    case 0x91:
        sub(C, 0);
        break;
    case 0x92:
        sub(D, 0);
        break;
    case 0x93:
        sub(E, 0);
        break;
    case 0x94:
        sub(H, 0);
        break;
    case 0x95:
        sub(L, 0);
        break;
    case 0x96:
        char M;     // obtain data from HL location here
        sub(M, 0);
        break;

    // SBB reg.
    case 0x9F:
        sub(A, 1);
        break;
    case 0x98:
        sub(B, 1);
        break;
    case 0x99:
        sub(C, 1);
        break;
    case 0x9A:
        sub(D, 1);
        break;
    case 0x9B:
        sub(E, 1);
        break;
    case 0x9C:
        sub(H, 1);
        break;
    case 0x9D:
        sub(L, 1);
        break;
    case 0x9E:
        char M;     // obtain data from HL location here
        sub(M, 1);
        break;
    
    // SUI data
    case 0xD6:
        sub(inst.bytes.one, 0);
        break;

    // SBI data
    case 0xDE:
        sub(inst.bytes.one, 1);
        break;

    // INR reg.
    case 0x3C:
        inc(&A, NULL);
        break;
    case 0x04:
        inc(&B, NULL);
        break;
    case 0x0C:
        inc(&C, NULL);
        break;
    case 0x14:
        inc(&D, NULL);
        break;
    case 0x1C:
        inc(&E, NULL);
        break;
    case 0x24:
        inc(&H, NULL);
        break;
    case 0x2C:
        inc(&L, NULL);
        break;
    case 0x34:
        inc(&M, NULL);
        break;

    case 0x03:
        inc(&B, &C);
        break;
    case 0x13:
        inc(&D, &E);
        break;
    case 0x23:
        inc(&H, &L);
        break;
    case 0x33:
        // can't directly pass SP... what to do??
        inc(&, &);
        break;

    // DCR reg.
    case 0x3D:
        dec(&, NULL);
        break;
    case 0x05:
        dec(&, NULL);
        break;
    case 0x0D:
        dec(&, NULL);
        break;
    case 0x15:
        dec(&, NULL);
        break;
    case 0x1D:
        dec(&, NULL);
        break;
    case 0x25:
        dec(&, NULL);
        break;
    case 0x2D:
        dec(&, NULL);
        break;
    case 0x35:
        dec(&, NULL);
        break;

    case 0x0B:
        dec(&B, &C);
        break;
    case 0x1B:
        dec(&D, &E);
        break;
    case 0x2B:
        dec(&H, &L);
        break;
    case 0x3B:
        dec(&, &);
        break;

    9,      /* 09 */    "DAD_B",
    25,     /* 19 */    "DAD_D",
    41,     /* 29 */    "DAD_H",
    57,     /* 39 */    "DAD_SP",
    39,     /* 27 */    "DAA",


    // --------------------------------------------------------------------- //
    // --------------------------- Logical Group --------------------------- //
    // --------------------------------------------------------------------- //
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
        bitwiseNot(A);
        break;
    case 0xB8:
        bitwiseNot(B);
        break;
    case 0xB9:
        bitwiseNot(C);
        break;
    case 0xBA:
        bitwiseNot(D);
        break;
    case 0xBB:
        bitwiseNot(E);
        break;
    case 0xBC:
        bitwiseNot(H);
        break;
    case 0xBD:
        bitwiseNot(L);
        break;
    case 0xBE:
        bitwiseNot(M);
        break;
    case 0xFE:
        bitwiseNot(inst.bytes.one);
        break;

    23,     /* 17 */    "RAL",
    31,     /* 1F */    "RAR",
    7,      /* 07 */    "RLC",
    15,     /* 0F */    "RRC",

    47,     /* 2F */    "CMA",
    63,     /* 3F */    "CMC",
    55,     /* 37 */    "STC",
    
    // ---------------------------------------------------------------------- //
    // ------------------------ Branch Control Group ------------------------ //
    // ---------------------------------------------------------------------- //
    195,    /* C3 */    "JMP",
    194,    /* C2 */    "JNZ",
    202,    /* CA */    "JZ",
    210,    /* D2 */    "JNC",
    218,    /* DA */    "JC",
    234,    /* EA */    "JPE",
    226,    /* E2 */    "JPO",
    242,    /* F2 */    "JP",
    250,    /* FA */    "JM",

    233,    /* E9 */    "PCHL",

    205,    /* CD */    "CALL",
    196,    /* C4 */    "CNZ",
    204,    /* CC */    "CZ",
    212,    /* D4 */    "CNC",
    220,    /* DC */    "CC",
    236,    /* EC */    "CPE",
    228,    /* E4 */    "CPO",
    244,    /* F4 */    "CP",
    252,    /* FC */    "CM",

    201,    /* C9 */    "RET",
    192,    /* C0 */    "RNZ",
    200,    /* C8 */    "RZ",
    208,    /* D0 */    "RNC",
    216,    /* D8 */    "RC",
    224,    /* E0 */    "RPO",
    232,    /* E8 */    "RPE",
    240,    /* F0 */    "RP",
    248,    /* F8 */    "RM",

    199,    /* C7 */    "RST_0",
    207,    /* CF */    "RST_1",
    215,    /* D7 */    "RST_2",
    223,    /* DF */    "RST_3",
    231,    /* E7 */    "RST_4",
    239,    /* EF */    "RST_5",
    247,    /* F7 */    "RST_6",
    255,    /* FF */    "RST_7",


    // --------------------------------------------------------------------- //
    // ------------------- I/O and Machine Control Group ------------------- //
    // --------------------------------------------------------------------- //
    197,    /* C5 */    "PUSH_B",
    213,    /* D5 */    "PUSH_D",
    229,    /* E5 */    "PUSH_H",
    245,    /* F5 */    "PUSH_PSW",

    193,    /* C1 */    "POP_B",
    209,    /* D1 */    "POP_D",
    225,    /* E1 */    "POP_H",
    241,    /* F1 */    "POP_PSW",

    249,    /* F9 */    "SPHL",
    227     /* E3 */    "XTHL",

    211,    /* D3 */    "OUT",
    219,    /* DB */    "IN",

    243,    /* F3 */    "DI",
    251,    /* FB */    "EI",
    
    118,    /* 76 */    "HLT",
    0,      /* 00 */    "NOP",

    32,     /* 20 */    "RIM",
    48,     /* 30 */    "SIM",    

    default:
        break;
}