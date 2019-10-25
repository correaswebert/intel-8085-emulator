switch (inst.opcode)
{
    // ADD reg.
    case 135:
        add(A, 0);
        break;
    case 128:
        add(B, 0);
        break;
    case 129:
        add(C, 0);
        break;
    case 130:
        add(D, 0);
        break;
    case 131:
        add(E, 0);
        break;
    case 132:
        add(H, 0);
        break;
    case 133:
        add(L, 0);
        break;
    case 134:
        char M;     // obtain data from HL location here
        add(M, 0);
        break;

    // ADC reg.
    case 143:
        add(A, 1);
        break;
    case 136:
        add(B, 1);
        break;
    case 137:
        add(C, 1);
        break;
    case 138:
        add(D, 1);
        break;
    case 139:
        add(E, 1);
        break;
    case 140:
        add(H, 1);
        break;
    case 141:
        add(L, 1);
        break;
    case 142:
        char M;     // obtain data from HL location here
        add(M, 1);
        break;
    
    // ADI data
    case 198:
        add(inst.bytes.one, 0);
        break;

    // ACI data
    case 206:
        add(inst.bytes.one, 1);
        break;
    

    // SUB reg.
    case 151:
        sub(A, 0);
        break;
    case 144:
        sub(B, 0);
        break;
    case 145:
        sub(C, 0);
        break;
    case 146:
        sub(D, 0);
        break;
    case 147:
        sub(E, 0);
        break;
    case 148:
        sub(H, 0);
        break;
    case 149:
        sub(L, 0);
        break;
    case 150:
        char M;     // obtain data from HL location here
        sub(M, 0);
        break;

    // SBB reg.
    case 159:
        sub(A, 1);
        break;
    case 152:
        sub(B, 1);
        break;
    case 153:
        sub(C, 1);
        break;
    case 154:
        sub(D, 1);
        break;
    case 155:
        sub(E, 1);
        break;
    case 156:
        sub(H, 1);
        break;
    case 157:
        sub(L, 1);
        break;
    case 158:
        char M;     // obtain data from HL location here
        sub(M, 1);
        break;
    
    // SUI data
    case 214:
        sub(inst.bytes.one, 0);
        break;

    // SBI data
    case 222:
        sub(inst.bytes.one, 1);
        break;

    default:
        break;
}