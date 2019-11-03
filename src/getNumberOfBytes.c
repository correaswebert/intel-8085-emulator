#include "prototypes.h"

enum datatype numberBytesToRead(uint8_t opcode)
{
    switch (opcode)
    {
        // Data Transfer Group.
            case 0x3E:      // "MVI_A"
            case 0x06:      // "MVI_B"
            case 0x0E:      // "MVI_C"
            case 0x16:      // "MVI_D"
            case 0x1E:      // "MVI_E"
            case 0x26:      // "MVI_H"
            case 0x2E:      // "MVI_L"
            case 0x36:      // "MVI_M"
                return BYTES1;

            case 0x7F:      // "MOV_A_A"
            case 0x78:      // "MOV_A_B"
            case 0x79:      // "MOV_A_C"
            case 0x7A:      // "MOV_A_D"
            case 0x7B:      // "MOV_A_E"
            case 0x7C:      // "MOV_A_H"
            case 0x7D:      // "MOV_A_L"
            case 0x7E:      // "MOV_A_M"

            case 0x47:      // "MOV_B_A"
            case 0x40:      // "MOV_B_B"
            case 0x41:      // "MOV_B_C"
            case 0x42:      // "MOV_B_D"
            case 0x43:      // "MOV_B_E"
            case 0x44:      // "MOV_B_H"
            case 0x45:      // "MOV_B_L"
            case 0x46:      // "MOV_B_M"

            case 0x4F:      // "MOV_C_A"
            case 0x48:      // "MOV_C_B"
            case 0x49:      // "MOV_C_C"
            case 0x4A:      // "MOV_C_D"
            case 0x4B:      // "MOV_C_E"
            case 0x4C:      // "MOV_C_H"
            case 0x4D:      // "MOV_C_L"
            case 0x4E:      // "MOV_C_M"

            case 0x57:      // "MOV_D_A"
            case 0x50:      // "MOV_D_B"
            case 0x51:      // "MOV_D_C"
            case 0x52:      // "MOV_D_D"
            case 0x53:      // "MOV_D_E"
            case 0x54:      // "MOV_D_H"
            case 0x55:      // "MOV_D_L"
            case 0x56:      // "MOV_D_M"

            case 0x5F:      // "MOV_E_A"
            case 0x58:      // "MOV_E_B"
            case 0x59:      // "MOV_E_C"
            case 0x5A:      // "MOV_E_D"
            case 0x5B:      // "MOV_E_E"
            case 0x5C:      // "MOV_E_H"
            case 0x5D:      // "MOV_E_L"
            case 0x5E:      // "MOV_E_M"

            case 0x67:      // "MOV_H_A"
            case 0x60:      // "MOV_H_B"
            case 0x61:      // "MOV_H_C"
            case 0x62:      // "MOV_H_D"
            case 0x63:      // "MOV_H_E"
            case 0x64:      // "MOV_H_H"
            case 0x65:      // "MOV_H_L"
            case 0x66:      // "MOV_H_M"

            case 0x6F:      // "MOV_L_A"
            case 0x68:      // "MOV_L_B"
            case 0x69:      // "MOV_L_C"
            case 0x6A:      // "MOV_L_D"
            case 0x6B:      // "MOV_L_E"
            case 0x6C:      // "MOV_L_H"
            case 0x6D:      // "MOV_L_L"
            case 0x6E:      // "MOV_L_M"

            case 0x77:      // "MOV_M_A"
            case 0x70:      // "MOV_M_B"
            case 0x71:      // "MOV_M_C"
            case 0x72:      // "MOV_M_D"
            case 0x73:      // "MOV_M_E"
            case 0x74:      // "MOV_M_H"
            case 0x75:      // "MOV_M_L"
                return BYTES0;

            case 0x01:      // "LXI_B"
            case 0x11:      // "LXI_D"
            case 0x21:      // "LXI_H"
            case 0x31:      // "LXI_SP"
                return BYTES2;

            case 0x3A:      // "LDA"
            case 0x32:      // "STA"
                return BYTES2;

            case 0x2A:      // "LHLD"
            case 0x22:      // "SHLD"
                return BYTES2;

            case 0x0A:      // "LDAX_B"
            case 0x1A:      // "LDAX_D"

            case 0x02:      // "STAX_B"
            case 0x12:      // "STAX_D"
                return BYTES0;

            case 0xEB:      // "XCHG"
                return BYTES0;



        // Arithmetic Group.
            case 0x87:      // "ADD_A"
            case 0x80:      // "ADD_B"
            case 0x81:      // "ADD_C"
            case 0x82:      // "ADD_D"
            case 0x83:      // "ADD_E"
            case 0x84:      // "ADD_H"
            case 0x85:      // "ADD_L"
            case 0x86:      // "ADD_M"

            case 0x8F:      // "ADC_A"
            case 0x88:      // "ADC_B"
            case 0x89:      // "ADC_C"
            case 0x8A:      // "ADC_D"
            case 0x8B:      // "ADC_E"
            case 0x8C:      // "ADC_H"
            case 0x8D:      // "ADC_L"
            case 0x8E:      // "ADC_M"
                return BYTES0;

            case 0x97:      // "SUB_A"
            case 0x90:      // "SUB_B"
            case 0x91:      // "SUB_C"
            case 0x92:      // "SUB_D"
            case 0x93:      // "SUB_E"
            case 0x94:      // "SUB_H"
            case 0x95:      // "SUB_L"
            case 0x96:      // "SUB_M"

            case 0x9F:      // "SBB_A"
            case 0x98:      // "SBB_B"
            case 0x99:      // "SBB_C"
            case 0x9A:      // "SBB_D"
            case 0x9B:      // "SBB_E"
            case 0x9C:      // "SBB_H"
            case 0x9D:      // "SBB_L"
            case 0x9E:      // "SBB_M"
                return BYTES0;

            case 0x3C:      // "INR_A"
            case 0x04:      // "INR_B"
            case 0x0C:      // "INR_C"
            case 0x14:      // "INR_D"
            case 0x1C:      // "INR_E"
            case 0x24:      // "INR_H"
            case 0x2C:      // "INR_L"
            case 0x34:      // "INR_M"

            case 0x3D:      // "DCR_A"
            case 0x05:      // "DCR_B"
            case 0x0D:      // "DCR_C"
            case 0x15:      // "DCR_D"
            case 0x1D:      // "DCR_E"
            case 0x25:      // "DCR_H"
            case 0x2D:      // "DCR_L"
            case 0x35:      // "DCR_M"

            case 0x03:      // "INX_B"
            case 0x13:      // "INX_D"
            case 0x23:      // "INX_H"
            case 0x33:      // "INX_SP"

            case 0x0B:      // "DCX_B"
            case 0x1B:      // "DCX_D"
            case 0x2B:      // "DCX_H"
            case 0x3B:      // "DCX_SP"
                return BYTES0;
            
            case 0x09:      // "DAD_B"
            case 0x19:      // "DAD_D"
            case 0x29:      // "DAD_H"
            case 0x39:      // "DAD_SP"
                return BYTES0;

            case 0xC6:      // "ADI"
            case 0xCE:      // "ACI"
            case 0xDE:      // "SBI"
            case 0xD6:      // "SUI"
                return BYTES1;

            case 0x27:      // "DAA"
                return BYTES0;



        // Logical Group.
            case 0xA7:      // "ANA_A"
            case 0xA0:      // "ANA_B"
            case 0xA1:      // "ANA_C"
            case 0xA2:      // "ANA_D"
            case 0xA3:      // "ANA_E"
            case 0xA4:      // "ANA_H"
            case 0xA5:      // "ANA_L"
            case 0xA6:      // "ANA_M"

            case 0xAF:      // "XRA_A"
            case 0xA8:      // "XRA_B"
            case 0xA9:      // "XRA_C"
            case 0xAA:      // "XRA_D"
            case 0xAB:      // "XRA_E"
            case 0xAC:      // "XRA_H"
            case 0xAD:      // "XRA_L"
            case 0xAE:      // "XRA_M"

            case 0xB7:      // "ORA_A"
            case 0xB0:      // "ORA_B"
            case 0xB1:      // "ORA_C"
            case 0xB2:      // "ORA_D"
            case 0xB3:      // "ORA_E"
            case 0xB4:      // "ORA_H"
            case 0xB5:      // "ORA_L"
            case 0xB6:      // "ORA_M"

            case 0xBF:      // "CMP_A"
            case 0xB8:      // "CMP_B"
            case 0xB9:      // "CMP_C"
            case 0xBA:      // "CMP_D"
            case 0xBB:      // "CMP_E"
            case 0xBC:      // "CMP_H"
            case 0xBD:      // "CMP_L"
            case 0xBE:      // "CMP_M"
                return BYTES0;

            case 0xFE:      // "CPI"
            case 0xF6:      // "ORI"
            case 0xEE:      // "XRI"
            case 0xE6:      // "ANI"
                return BYTES1;

            case 0x17:      // "RAL"
            case 0x1F:      // "RAR"
            case 0x07:      // "RLC"
            case 0x0F:      // "RRC"
                return BYTES0;

            case 0x2F:      // "CMA"
            case 0x3F:      // "CMC"
            case 0x37:      // "STC"
                return BYTES0;


        // Branch Control Group.
            case 0xC3:      // "JMP"
            case 0xC2:      // "JNZ"
            case 0xCA:      // "JZ"
            case 0xD2:      // "JNC"
            case 0xDA:      // "JC"
            case 0xEA:      // "JPE"
            case 0xE2:      // "JPO"
            case 0xF2:      // "JP"
            case 0xFA:      // "JM"
                return BYTES2;

            case 0xCD:      // "CALL"
            case 0xC4:      // "CNZ"
            case 0xCC:      // "CZ"
            case 0xD4:      // "CNC"
            case 0xDC:      // "CC"
            case 0xEC:      // "CPE"
            case 0xE4:      // "CPO"
            case 0xF4:      // "CP"
            case 0xFC:      // "CM"
                return BYTES2;

            case 0xC9:      // "RET"
            case 0xC0:      // "RNZ"
            case 0xC8:      // "RZ"
            case 0xD0:      // "RNC"
            case 0xD8:      // "RC"
            case 0xE0:      // "RPO"
            case 0xE8:      // "RPE"
            case 0xF0:      // "RP"
            case 0xF8:      // "RM"
                return BYTES0;

            case 0xC7:      // "RST_0"
            case 0xCF:      // "RST_1"
            case 0xD7:      // "RST_2"
            case 0xDF:      // "RST_3"
            case 0xE7:      // "RST_4"
            case 0xEF:      // "RST_5"
            case 0xF7:      // "RST_6"
            case 0xFF:      // "RST_7"
                return BYTES0;

            case 0xE9:      // "PCHL"
                return BYTES0;



        // I/O and Machine Control Group.
            case 0xC5:      // "PUSH_B"
            case 0xD5:      // "PUSH_D"
            case 0xE5:      // "PUSH_H"
            case 0xF5:      // "PUSH_PSW"

            case 0xC1:      // "POP_B"
            case 0xD1:      // "POP_D"
            case 0xE1:      // "POP_H"
            case 0xF1:      // "POP_PSW"
                return BYTES0;

            case 0xF9:      // "SPHL"
            case 0xE3:      // "XTHL"
                return BYTES0;

            case 0xD3:      // "OUT"
            case 0xDB:      // "IN"
                return BYTES1;

            case 0xF3:      // "DI"
            case 0xFB:      // "EI"
                return BYTES0;
            
            case 0x76:      // "HLT"
            case 0x00:      // "NOP"
                return BYTES0;
            
            case 0x20:      // "RIM"
            case 0x30:      // "SIM"
                return BYTES0;

            default:
                return ERR;
    }
}