//
// Created by root on 8/27/17.
//

#include <iostream>
#include "cpu.h"

const struct instruction instructions[256] = {
       { &Cpu::opcode_0x00, 0, "NOP"},
       { &Cpu::opcode_0x01, 2, "LD BC,nn"},
       { &Cpu::opcode_0x02, 0, "LD (BC),A"},
       { &Cpu::opcode_0x03, 0, "INC BC"},
       { &Cpu::opcode_0x04, 0, "INC B"},
       { &Cpu::opcode_0x05, 0, "DEC B" },
       { &Cpu::opcode_0x06, 1, "LD B,n" },
       { &Cpu::opcode_0x07, 0, "RLC A" },
       { &Cpu::opcode_0x08, 2, "LD (nn),SP" },
       { &Cpu::opcode_0x09, 0, "ADD HL,BC" },
       { &Cpu::opcode_0x0A, 0, "LD A,(BC)" },
       { &Cpu::opcode_0x0B, 0, "DEC BC" },
       { &Cpu::opcode_0x0C, 0, "INC C" },
       { &Cpu::opcode_0x0D, 0, "DEC C" },
       { &Cpu::opcode_0x0E, 1, "LD C,n" },
       { &Cpu::opcode_0x0F, 0, "RRC A" },
       { &Cpu::opcode_0x10, 1, "STOP" },
       { &Cpu::opcode_0x11, 2, "LD DE,nn" },
       { &Cpu::opcode_0x12, 0, "LD (DE),A" },
       { &Cpu::opcode_0x13, 0, "INC DE" },
       { &Cpu::opcode_0x14, 0, "INC D" },
       { &Cpu::opcode_0x15, 0, "DEC D" },
       { &Cpu::opcode_0x16, 1, "LD D,n" },
       { &Cpu::opcode_0x17, 0, "RL A" },
       { &Cpu::opcode_0x18, 1, "JR n" },
       { &Cpu::opcode_0x19, 0, "ADD HL,DE" },
       { &Cpu::opcode_0x1A, 0, "LD A,(DE)" },
       { &Cpu::opcode_0x1B, 0, "DEC DE" },
       { &Cpu::opcode_0x1C, 0, "INC E" },
       { &Cpu::opcode_0x1D, 0, "DEC E" },
       { &Cpu::opcode_0x1E, 1, "LD E,n" },
       { &Cpu::opcode_0x1F, 0, "RR A" },
       { &Cpu::opcode_0x20, 1, "JR NZ,n" },
       { &Cpu::opcode_0x21, 2, "LD HL,nn" },
       { &Cpu::opcode_0x22, 0, "LDI (HL),A" },
       { &Cpu::opcode_0x23, 0, "INC HL" },
       { &Cpu::opcode_0x24, 0, "INC H" },
       { &Cpu::opcode_0x25, 0, "DEC H" },
       { &Cpu::opcode_0x26, 1, "LD H,n" },
       { &Cpu::opcode_0x27, 0, "DAA" },
       { &Cpu::opcode_0x28, 1, "JR Z,n" },
       { &Cpu::opcode_0x29, 0, "ADD HL,HL" },
       { &Cpu::opcode_0x2A, 0, "LDI A,(HL)" },
       { &Cpu::opcode_0x2B, 0, "DEC HL" },
       { &Cpu::opcode_0x2C, 0, "INC L" },
       { &Cpu::opcode_0x2D, 0, "DEC L" },
       { &Cpu::opcode_0x2E, 1, "LD L,n" },
       { &Cpu::opcode_0x2F, 0, "CPL" },
       { &Cpu::opcode_0x30, 1, "JR NC,n" },
       { &Cpu::opcode_0x31, 2, "LD SP,nn" },
       { &Cpu::opcode_0x32, 0, "LDD (HL),A" },
       { &Cpu::opcode_0x33, 0, "INC SP" },
       { &Cpu::opcode_0x34, 0, "INC (HL)" },
       { &Cpu::opcode_0x35, 0, "DEC (HL)" },
       { &Cpu::opcode_0x36, 1, "LD (HL),n" },
       { &Cpu::opcode_0x37, 0, "SCF" },
       { &Cpu::opcode_0x38, 1, "JR C,n" },
       { &Cpu::opcode_0x39, 0, "ADD HL,SP" },
       { &Cpu::opcode_0x3A, 0, "LDD A,(HL)" },
       { &Cpu::opcode_0x3B, 0, "DEC SP" },
       { &Cpu::opcode_0x3C, 0, "INC A" },
       { &Cpu::opcode_0x3D, 0, "DEC A" },
       { &Cpu::opcode_0x3E, 1, "LD A,n" },
       { &Cpu::opcode_0x3F, 0, "CCF" },
       { &Cpu::opcode_0x40, 0, "LD B,B" },
       { &Cpu::opcode_0x41, 0, "LD B,C" },
       { &Cpu::opcode_0x42, 0, "LD B,D" },
       { &Cpu::opcode_0x43, 0, "LD B,E" },
       { &Cpu::opcode_0x44, 0, "LD B,H" },
       { &Cpu::opcode_0x45, 0, "LD B,L" },
       { &Cpu::opcode_0x46, 0, "LD B,(HL)" },
       { &Cpu::opcode_0x47, 0, "LD B,A" },
       { &Cpu::opcode_0x48, 0, "LD C,B" },
       { &Cpu::opcode_0x49, 0, "LD C,C" },
       { &Cpu::opcode_0x4A, 0, "LD C,D" },
       { &Cpu::opcode_0x4B, 0, "LD C,E" },
       { &Cpu::opcode_0x4C, 0, "LD C,H" },
       { &Cpu::opcode_0x4D, 0, "LD C,L" },
       { &Cpu::opcode_0x4E, 0, "LD C,(HL)" },
       { &Cpu::opcode_0x4F, 0, "LD C,A" },
       { &Cpu::opcode_0x50, 0, "LD D,B" },
       { &Cpu::opcode_0x51, 0, "LD D,C" },
       { &Cpu::opcode_0x52, 0, "LD D,D" },
       { &Cpu::opcode_0x53, 0, "LD D,E" },
       { &Cpu::opcode_0x54, 0, "LD D,H" },
       { &Cpu::opcode_0x55, 0, "LD D,L" },
       { &Cpu::opcode_0x56, 0, "LD D,(HL)" },
       { &Cpu::opcode_0x57, 0, "LD D,A" },
       { &Cpu::opcode_0x58, 0, "LD E,B" },
       { &Cpu::opcode_0x59, 0, "LD E,C" },
       { &Cpu::opcode_0x5A, 0, "LD E,D" },
       { &Cpu::opcode_0x5B, 0, "LD E,E" },
       { &Cpu::opcode_0x5C, 0, "LD E,H" },
       { &Cpu::opcode_0x5D, 0, "LD E,L" },
       { &Cpu::opcode_0x5E, 0, "LD E,(HL)" },
       { &Cpu::opcode_0x5F, 0, "LD E,A" },
       { &Cpu::opcode_0x60, 0, "LD H,B" },
       { &Cpu::opcode_0x61, 0, "LD H,C" },
       { &Cpu::opcode_0x62, 0, "LD H,D" },
       { &Cpu::opcode_0x63, 0, "LD H,E" },
       { &Cpu::opcode_0x64, 0, "LD H,H" },
       { &Cpu::opcode_0x65, 0, "LD H,L" },
       { &Cpu::opcode_0x66, 0, "LD H,(HL)" },
       { &Cpu::opcode_0x67, 0, "LD H,A" },
       { &Cpu::opcode_0x68, 0, "LD L,B" },
       { &Cpu::opcode_0x69, 0, "LD L,C" },
       { &Cpu::opcode_0x6A, 0, "LD L,D" },
       { &Cpu::opcode_0x6B, 0, "LD L,E" },
       { &Cpu::opcode_0x6C, 0, "LD L,H" },
       { &Cpu::opcode_0x6D, 0, "LD L,L" },
       { &Cpu::opcode_0x6E, 0, "LD L,(HL)" },
       { &Cpu::opcode_0x6F, 0, "LD L,A" },
       { &Cpu::opcode_0x70, 0, "LD (HL),B" },
       { &Cpu::opcode_0x71, 0, "LD (HL),C" },
       { &Cpu::opcode_0x72, 0, "LD (HL),D" },
       { &Cpu::opcode_0x73, 0, "LD (HL),E" },
       { &Cpu::opcode_0x74, 0, "LD (HL),H" },
       { &Cpu::opcode_0x75, 0, "LD (HL),L" },
       { &Cpu::opcode_0x76, 0, "HALT" },
       { &Cpu::opcode_0x77, 0, "LD (HL),A" },
       { &Cpu::opcode_0x78, 0, "LD A,B" },
       { &Cpu::opcode_0x79, 0, "LD A,C" },
       { &Cpu::opcode_0x7A, 0, "LD A,D" },
       { &Cpu::opcode_0x7B, 0, "LD A,E" },
       { &Cpu::opcode_0x7C, 0, "LD A,H" },
       { &Cpu::opcode_0x7D, 0, "LD A,L" },
       { &Cpu::opcode_0x7E, 0, "LD A,(HL)" },
       { &Cpu::opcode_0x7F, 0, "LD A,A" },
       { &Cpu::opcode_0x80, 0, "ADD A,B" },
       { &Cpu::opcode_0x81, 0, "ADD A,C" },
       { &Cpu::opcode_0x82, 0, "ADD A,D" },
       { &Cpu::opcode_0x83, 0, "ADD A,E" },
       { &Cpu::opcode_0x84, 0, "ADD A,H" },
       { &Cpu::opcode_0x85, 0, "ADD A,L" },
       { &Cpu::opcode_0x86, 0, "ADD A,(HL)" },
       { &Cpu::opcode_0x87, 0, "ADD A,A" },
       { &Cpu::opcode_0x88, 0, "ADC A,B" },
       { &Cpu::opcode_0x89, 0, "ADC A,C" },
       { &Cpu::opcode_0x8A, 0, "ADC A,D" },
       { &Cpu::opcode_0x8B, 0, "ADC A,E" },
       { &Cpu::opcode_0x8C, 0, "ADC A,H" },
       { &Cpu::opcode_0x8D, 0, "ADC A,L" },
       { &Cpu::opcode_0x8E, 0, "ADC A,(HL)" },
       { &Cpu::opcode_0x8F, 0, "ADC A,A" },
       { &Cpu::opcode_0x90, 0, "SUB A,B" },
       { &Cpu::opcode_0x91, 0, "SUB A,C" },
       { &Cpu::opcode_0x92, 0, "SUB A,D" },
       { &Cpu::opcode_0x93, 0, "SUB A,E" },
       { &Cpu::opcode_0x94, 0, "SUB A,H" },
       { &Cpu::opcode_0x95, 0, "SUB A,L" },
       { &Cpu::opcode_0x96, 0, "SUB A,(HL)" },
       { &Cpu::opcode_0x97, 0, "SUB A,A" },
       { &Cpu::opcode_0x98, 0, "SBC A,B" },
       { &Cpu::opcode_0x99, 0, "SBC A,C" },
       { &Cpu::opcode_0x9A, 0, "SBC A,D" },
       { &Cpu::opcode_0x9B, 0, "SBC A,E" },
       { &Cpu::opcode_0x9C, 0, "SBC A,H" },
       { &Cpu::opcode_0x9D, 0, "SBC A,L" },
       { &Cpu::opcode_0x9E, 0, "SBC A,(HL)" },
       { &Cpu::opcode_0x9F, 0, "SBC A,A" },
       { &Cpu::opcode_0xA0, 0, "AND B" },
       { &Cpu::opcode_0xA1, 0, "AND C" },
       { &Cpu::opcode_0xA2, 0, "AND D" },
       { &Cpu::opcode_0xA3, 0, "AND E" },
       { &Cpu::opcode_0xA4, 0, "AND H" },
       { &Cpu::opcode_0xA5, 0, "AND L" },
       { &Cpu::opcode_0xA6, 0, "AND (HL)" },
       { &Cpu::opcode_0xA7, 0, "AND A" },
       { &Cpu::opcode_0xA8, 0, "XOR B" },
       { &Cpu::opcode_0xA9, 0, "XOR C" },
       { &Cpu::opcode_0xAA, 0, "XOR D" },
       { &Cpu::opcode_0xAB, 0, "XOR E" },
       { &Cpu::opcode_0xAC, 0, "XOR H" },
       { &Cpu::opcode_0xAD, 0, "XOR L" },
       { &Cpu::opcode_0xAE, 0, "XOR (HL)" },
       { &Cpu::opcode_0xAF, 0, "XOR A" },
       { &Cpu::opcode_0xB0, 0, "OR B" },
       { &Cpu::opcode_0xB1, 0, "OR C" },
       { &Cpu::opcode_0xB2, 0, "OR D" },
       { &Cpu::opcode_0xB3, 0, "OR E" },
       { &Cpu::opcode_0xB4, 0, "OR H" },
       { &Cpu::opcode_0xB5, 0, "OR L" },
       { &Cpu::opcode_0xB6, 0, "OR (HL)" },
       { &Cpu::opcode_0xB7, 0, "OR A" },
       { &Cpu::opcode_0xB8, 0, "CP B" },
       { &Cpu::opcode_0xB9, 0, "CP C" },
       { &Cpu::opcode_0xBA, 0, "CP D" },
       { &Cpu::opcode_0xBB, 0, "CP E" },
       { &Cpu::opcode_0xBC, 0, "CP H" },
       { &Cpu::opcode_0xBD, 0, "CP L" },
       { &Cpu::opcode_0xBE, 0, "CP (HL)" },
       { &Cpu::opcode_0xBF, 0, "CP A" },
       { &Cpu::opcode_0xC0, 0, "RET NZ" },
       { &Cpu::opcode_0xC1, 0, "POP BC" },
       { &Cpu::opcode_0xC2, 2, "JP NZ,nn" },
       { &Cpu::opcode_0xC3, 2, "JP nn" },
       { &Cpu::opcode_0xC4, 2, "CALL NZ,nn" },
       { &Cpu::opcode_0xC5, 0, "PUSH BC" },
       { &Cpu::opcode_0xC6, 1, "ADD A,n" },
       { &Cpu::opcode_0xC7, 0, "RST 0" },
       { &Cpu::opcode_0xC8, 0, "RET Z" },
       { &Cpu::opcode_0xC9, 0, "RET" },
       { &Cpu::opcode_0xCA, 2, "JP Z,nn" },
       { &Cpu::opcode_0xCB, 1, "Ext ops" },
       { &Cpu::opcode_0xCC, 2, "CALL Z,nn" },
       { &Cpu::opcode_0xCD, 2, "CALL nn" },
       { &Cpu::opcode_0xCE, 1, "ADC A,n" },
       { &Cpu::opcode_0xCF, 0, "RST 8" },
       { &Cpu::opcode_0xD0, 0, "RET NC" },
       { &Cpu::opcode_0xD1, 0, "POP DE" },
       { &Cpu::opcode_0xD2, 2, "JP NC,nn" },
       { &Cpu::opcode_0xD3, 0, "XX" },
       { &Cpu::opcode_0xD4, 2, "CALL NC,nn" },
       { &Cpu::opcode_0xD5, 0, "PUSH DE" },
       { &Cpu::opcode_0xD6, 1, "SUB A,n" },
       { &Cpu::opcode_0xD7, 0, "RST 10" },
       { &Cpu::opcode_0xD8, 0, "RET C" },
       { &Cpu::opcode_0xD9, 0, "RETI" },
       { &Cpu::opcode_0xDA, 2, "JP C,nn" },
       { &Cpu::opcode_0xDB, 0, "XX" },
       { &Cpu::opcode_0xDC, 2, "CALL C,nn" },
       { &Cpu::opcode_0xDD, 0, "XX" },
       { &Cpu::opcode_0xDE, 1, "SBC A,n" },
       { &Cpu::opcode_0xDF, 0, "RST 18" },
       { &Cpu::opcode_0xE0, 1, "LDH (n),A" },
       { &Cpu::opcode_0xE1, 0, "POP HL" },
       { &Cpu::opcode_0xE2, 0, "LDH (C),A" },
       { &Cpu::opcode_0xE3, 0, "XX" },
       { &Cpu::opcode_0xE4, 0, "XX" },
       { &Cpu::opcode_0xE5, 0, "PUSH HL" },
       { &Cpu::opcode_0xE6, 1, "AND n" },
       { &Cpu::opcode_0xE7, 0, "RST 20" },
       { &Cpu::opcode_0xE8, 1, "ADD SP,d" },
       { &Cpu::opcode_0xE9, 0, "JP (HL)" },
       { &Cpu::opcode_0xEA, 2, "LD (nn),A" },
       { &Cpu::opcode_0xEB, 0, "XX" },
       { &Cpu::opcode_0xEC, 0, "XX" },
       { &Cpu::opcode_0xED, 0, "XX" },
       { &Cpu::opcode_0xEE, 1, "XOR n" },
       { &Cpu::opcode_0xEF, 0, "RST 28" },
       { &Cpu::opcode_0xF0, 1, "LDH A,(n)" },
       { &Cpu::opcode_0xF1, 0, "POP AF" },
       { &Cpu::opcode_0xF2, 0, "XX" },
       { &Cpu::opcode_0xF3, 0, "DI" },
       { &Cpu::opcode_0xF4, 0, "XX" },
       { &Cpu::opcode_0xF5, 0, "PUSH AF" },
       { &Cpu::opcode_0xF6, 1, "OR n" },
       { &Cpu::opcode_0xF7, 0, "RST 30" },
       { &Cpu::opcode_0xF8, 1, "LDHL SP,d" },
       { &Cpu::opcode_0xF9, 0, "LD SP,HL" },
       { &Cpu::opcode_0xFA, 2, "LD A,(nn)" },
       { &Cpu::opcode_0xFB, 0, "EI" },
       { &Cpu::opcode_0xFC, 0, "XX" },
       { &Cpu::opcode_0xFD, 0, "XX" },
       { &Cpu::opcode_0xFE, 1, "CP n" },
       { &Cpu::opcode_0xFF, 0, "RST 38" },
}

void Cpu::opcode_0x00() {} // NOP
void Cpu::opcode_0x01() {} // LD BC,nn
void Cpu::opcode_0x02() {} // LD (BC),A
void Cpu::opcode_0x03() {} // INC BC
void Cpu::opcode_0x04() {} // INC B
void Cpu::opcode_0x05() {} // DEC B
void Cpu::opcode_0x06() {} // LD B,n
void Cpu::opcode_0x07() {} // RLC A
void Cpu::opcode_0x08() {} // LD (nn),SP
void Cpu::opcode_0x09() {} // ADD HL,BC
void Cpu::opcode_0x0A() {} // LD A,(BC)
void Cpu::opcode_0x0B() {} // DEC BC
void Cpu::opcode_0x0C() {} // INC C
void Cpu::opcode_0x0D() {} // DEC C
void Cpu::opcode_0x0E() {} // LD C,n
void Cpu::opcode_0x0F() {} // RRC A
void Cpu::opcode_0x10() {} // STOP
void Cpu::opcode_0x11() {} // LD DE,nn
void Cpu::opcode_0x12() {} // LD (DE),A
void Cpu::opcode_0x13() {} // INC DE
void Cpu::opcode_0x14() {} // INC D
void Cpu::opcode_0x15() {} // DEC D
void Cpu::opcode_0x16() {} // LD D,n
void Cpu::opcode_0x17() {} // RL A
void Cpu::opcode_0x18() {} // JR n
void Cpu::opcode_0x19() {} // ADD HL,DE
void Cpu::opcode_0x1A() {} // LD A,(DE)
void Cpu::opcode_0x1B() {} // DEC DE
void Cpu::opcode_0x1C() {} // INC E
void Cpu::opcode_0x1D() {} // DEC E
void Cpu::opcode_0x1E() {} // LD E,n
void Cpu::opcode_0x1F() {} // RR A
void Cpu::opcode_0x20() {} // JR NZ,n
void Cpu::opcode_0x21() {} // LD HL,nn
void Cpu::opcode_0x22() {} // LDI (HL),A
void Cpu::opcode_0x23() {} // INC HL
void Cpu::opcode_0x24() {} // INC H
void Cpu::opcode_0x25() {} // DEC H
void Cpu::opcode_0x26() {} // LD H,n
void Cpu::opcode_0x27() {} // DAA
void Cpu::opcode_0x28() {} // JR Z,n
void Cpu::opcode_0x29() {} // ADD HL,HL
void Cpu::opcode_0x2A() {} // LDI A,(HL)
void Cpu::opcode_0x2B() {} // DEC HL
void Cpu::opcode_0x2C() {} // INC L
void Cpu::opcode_0x2D() {} // DEC L
void Cpu::opcode_0x2E() {} // LD L,n
void Cpu::opcode_0x2F() {} // CPL
void Cpu::opcode_0x30() {} // JR NC,n
void Cpu::opcode_0x31() {} // LD SP,nn
void Cpu::opcode_0x32() {} // LDD (HL),A
void Cpu::opcode_0x33() {} // INC SP
void Cpu::opcode_0x34() {} // INC (HL)
void Cpu::opcode_0x35() {} // DEC (HL)
void Cpu::opcode_0x36() {} // LD (HL),n
void Cpu::opcode_0x37() {} // SCF
void Cpu::opcode_0x38() {} // JR C,n
void Cpu::opcode_0x39() {} // ADD HL,SP
void Cpu::opcode_0x3A() {} // LDD A,(HL)
void Cpu::opcode_0x3B() {} // DEC SP
void Cpu::opcode_0x3C() {} // INC A
void Cpu::opcode_0x3D() {} // DEC A
void Cpu::opcode_0x3E() {} // LD A,n
void Cpu::opcode_0x3F() {} // CCF
void Cpu::opcode_0x40() {} // LD B,B
void Cpu::opcode_0x41() {} // LD B,C
void Cpu::opcode_0x42() {} // LD B,D
void Cpu::opcode_0x43() {} // LD B,E
void Cpu::opcode_0x44() {} // LD B,H
void Cpu::opcode_0x45() {} // LD B,L
void Cpu::opcode_0x46() {} // LD B,(HL)
void Cpu::opcode_0x47() {} // LD B,A
void Cpu::opcode_0x48() {} // LD C,B
void Cpu::opcode_0x49() {} // LD C,C
void Cpu::opcode_0x4A() {} // LD C,D
void Cpu::opcode_0x4B() {} // LD C,E
void Cpu::opcode_0x4C() {} // LD C,H
void Cpu::opcode_0x4D() {} // LD C,L
void Cpu::opcode_0x4E() {} // LD C,(HL)
void Cpu::opcode_0x4F() {} // LD C,A
void Cpu::opcode_0x50() {} // LD D,B
void Cpu::opcode_0x51() {} // LD D,C
void Cpu::opcode_0x52() {} // LD D,D
void Cpu::opcode_0x53() {} // LD D,E
void Cpu::opcode_0x54() {} // LD D,H
void Cpu::opcode_0x55() {} // LD D,L
void Cpu::opcode_0x56() {} // LD D,(HL)
void Cpu::opcode_0x57() {} // LD D,A
void Cpu::opcode_0x58() {} // LD E,B
void Cpu::opcode_0x59() {} // LD E,C
void Cpu::opcode_0x5A() {} // LD E,D
void Cpu::opcode_0x5B() {} // LD E,E
void Cpu::opcode_0x5C() {} // LD E,H
void Cpu::opcode_0x5D() {} // LD E,L
void Cpu::opcode_0x5E() {} // LD E,(HL)
void Cpu::opcode_0x5F() {} // LD E,A
void Cpu::opcode_0x60() {} // LD H,B
void Cpu::opcode_0x61() {} // LD H,C
void Cpu::opcode_0x62() {} // LD H,D
void Cpu::opcode_0x63() {} // LD H,E
void Cpu::opcode_0x64() {} // LD H,H
void Cpu::opcode_0x65() {} // LD H,L
void Cpu::opcode_0x66() {} // LD H,(HL)
void Cpu::opcode_0x67() {} // LD H,A
void Cpu::opcode_0x68() {} // LD L,B
void Cpu::opcode_0x69() {} // LD L,C
void Cpu::opcode_0x6A() {} // LD L,D
void Cpu::opcode_0x6B() {} // LD L,E
void Cpu::opcode_0x6C() {} // LD L,H
void Cpu::opcode_0x6D() {} // LD L,L
void Cpu::opcode_0x6E() {} // LD L,(HL)
void Cpu::opcode_0x6F() {} // LD L,A
void Cpu::opcode_0x70() {} // LD (HL),B
void Cpu::opcode_0x71() {} // LD (HL),C
void Cpu::opcode_0x72() {} // LD (HL),D
void Cpu::opcode_0x73() {} // LD (HL),E
void Cpu::opcode_0x74() {} // LD (HL),H
void Cpu::opcode_0x75() {} // LD (HL),L
void Cpu::opcode_0x76() {} // HALT
void Cpu::opcode_0x77() {} // LD (HL),A
void Cpu::opcode_0x78() {} // LD A,B
void Cpu::opcode_0x79() {} // LD A,C
void Cpu::opcode_0x7A() {} // LD A,D
void Cpu::opcode_0x7B() {} // LD A,E
void Cpu::opcode_0x7C() {} // LD A,H
void Cpu::opcode_0x7D() {} // LD A,L
void Cpu::opcode_0x7E() {} // LD A,(HL)
void Cpu::opcode_0x7F() {} // LD A,A
void Cpu::opcode_0x80() {} // ADD A,B
void Cpu::opcode_0x81() {} // ADD A,C
void Cpu::opcode_0x82() {} // ADD A,D
void Cpu::opcode_0x83() {} // ADD A,E
void Cpu::opcode_0x84() {} // ADD A,H
void Cpu::opcode_0x85() {} // ADD A,L
void Cpu::opcode_0x86() {} // ADD A,(HL)
void Cpu::opcode_0x87() {} // ADD A,A
void Cpu::opcode_0x88() {} // ADC A,B
void Cpu::opcode_0x89() {} // ADC A,C
void Cpu::opcode_0x8A() {} // ADC A,D
void Cpu::opcode_0x8B() {} // ADC A,E
void Cpu::opcode_0x8C() {} // ADC A,H
void Cpu::opcode_0x8D() {} // ADC A,L
void Cpu::opcode_0x8E() {} // ADC A,(HL)
void Cpu::opcode_0x8F() {} // ADC A,A
void Cpu::opcode_0x90() {} // SUB A,B
void Cpu::opcode_0x91() {} // SUB A,C
void Cpu::opcode_0x92() {} // SUB A,D
void Cpu::opcode_0x93() {} // SUB A,E
void Cpu::opcode_0x94() {} // SUB A,H
void Cpu::opcode_0x95() {} // SUB A,L
void Cpu::opcode_0x96() {} // SUB A,(HL)
void Cpu::opcode_0x97() {} // SUB A,A
void Cpu::opcode_0x98() {} // SBC A,B
void Cpu::opcode_0x99() {} // SBC A,C
void Cpu::opcode_0x9A() {} // SBC A,D
void Cpu::opcode_0x9B() {} // SBC A,E
void Cpu::opcode_0x9C() {} // SBC A,H
void Cpu::opcode_0x9D() {} // SBC A,L
void Cpu::opcode_0x9E() {} // SBC A,(HL)
void Cpu::opcode_0x9F() {} // SBC A,A
void Cpu::opcode_0xA0() {} // AND B
void Cpu::opcode_0xA1() {} // AND C
void Cpu::opcode_0xA2() {} // AND D
void Cpu::opcode_0xA3() {} // AND E
void Cpu::opcode_0xA4() {} // AND H
void Cpu::opcode_0xA5() {} // AND L
void Cpu::opcode_0xA6() {} // AND (HL)
void Cpu::opcode_0xA7() {} // AND A
void Cpu::opcode_0xA8() {} // XOR B
void Cpu::opcode_0xA9() {} // XOR C
void Cpu::opcode_0xAA() {} // XOR D
void Cpu::opcode_0xAB() {} // XOR E
void Cpu::opcode_0xAC() {} // XOR H
void Cpu::opcode_0xAD() {} // XOR L
void Cpu::opcode_0xAE() {} // XOR (HL)
void Cpu::opcode_0xAF() {} // XOR A
void Cpu::opcode_0xB0() {} // OR B
void Cpu::opcode_0xB1() {} // OR C
void Cpu::opcode_0xB2() {} // OR D
void Cpu::opcode_0xB3() {} // OR E
void Cpu::opcode_0xB4() {} // OR H
void Cpu::opcode_0xB5() {} // OR L
void Cpu::opcode_0xB6() {} // OR (HL)
void Cpu::opcode_0xB7() {} // OR A
void Cpu::opcode_0xB8() {} // CP B
void Cpu::opcode_0xB9() {} // CP C
void Cpu::opcode_0xBA() {} // CP D
void Cpu::opcode_0xBB() {} // CP E
void Cpu::opcode_0xBC() {} // CP H
void Cpu::opcode_0xBD() {} // CP L
void Cpu::opcode_0xBE() {} // CP (HL)
void Cpu::opcode_0xBF() {} // CP A
void Cpu::opcode_0xC0() {} // RET NZ
void Cpu::opcode_0xC1() {} // POP BC
void Cpu::opcode_0xC2() {} // JP NZ,nn
void Cpu::opcode_0xC3() {} // JP nn
void Cpu::opcode_0xC4() {} // CALL NZ,nn
void Cpu::opcode_0xC5() {} // PUSH BC
void Cpu::opcode_0xC6() {} // ADD A,n
void Cpu::opcode_0xC7() {} // RST 0
void Cpu::opcode_0xC8() {} // RET Z
void Cpu::opcode_0xC9() {} // RET
void Cpu::opcode_0xCA() {} // JP Z,nn
void Cpu::opcode_0xCB() {} // Ext ops
void Cpu::opcode_0xCC() {} // CALL Z,nn
void Cpu::opcode_0xCD() {} // CALL nn
void Cpu::opcode_0xCE() {} // ADC A,n
void Cpu::opcode_0xCF() {} // RST 8
void Cpu::opcode_0xD0() {} // RET NC
void Cpu::opcode_0xD1() {} // POP DE
void Cpu::opcode_0xD2() {} // JP NC,nn
void Cpu::opcode_0xD3() { std::cout << "Removed op" << std::endl; return; } // XX
void Cpu::opcode_0xD4() {} // CALL NC,nn
void Cpu::opcode_0xD5() {} // PUSH DE
void Cpu::opcode_0xD6() {} // SUB A,n
void Cpu::opcode_0xD7() {} // RST 10
void Cpu::opcode_0xD8() {} // RET C
void Cpu::opcode_0xD9() {} // RETI
void Cpu::opcode_0xDA() {} // JP C,nn
void Cpu::opcode_0xDB() { std::cout << "Removed op" << std::endl; return; } // XX
void Cpu::opcode_0xDC() {} // CALL C,nn
void Cpu::opcode_0xDD() { std::cout << "Removed op" << std::endl; return; } // XX
void Cpu::opcode_0xDE() {} // SBC A,n
void Cpu::opcode_0xDF() {} // RST 18
void Cpu::opcode_0xE0() {} // LDH (n),A
void Cpu::opcode_0xE1() {} // POP HL
void Cpu::opcode_0xE2() {} // LDH (C),A
void Cpu::opcode_0xE3() { std::cout << "Removed op" << std::endl; return; } // XX
void Cpu::opcode_0xE4() { std::cout << "Removed op" << std::endl; return; } // XX
void Cpu::opcode_0xE5() {} // PUSH HL
void Cpu::opcode_0xE6() {} // AND n
void Cpu::opcode_0xE7() {} // RST 20
void Cpu::opcode_0xE8() {} // ADD SP,d
void Cpu::opcode_0xE9() {} // JP (HL)
void Cpu::opcode_0xEA() {} // LD (nn),A
void Cpu::opcode_0xEB() { std::cout << "Removed op" << std::endl; return; } // XX
void Cpu::opcode_0xEC() { std::cout << "Removed op" << std::endl; return; } // XX
void Cpu::opcode_0xED() { std::cout << "Removed op" << std::endl; return; } // XX
void Cpu::opcode_0xEE() {} // XOR n
void Cpu::opcode_0xEF() {} // RST 28
void Cpu::opcode_0xF0() {} // LDH A,(n)
void Cpu::opcode_0xF1() {} // POP AF
void Cpu::opcode_0xF2() { std::cout << "Removed op" << std::endl; return; } // XX
void Cpu::opcode_0xF3() {} // DI
void Cpu::opcode_0xF4() { std::cout << "Removed op" << std::endl; return; } // XX
void Cpu::opcode_0xF5() {} // PUSH AF
void Cpu::opcode_0xF6() {} // OR n
void Cpu::opcode_0xF7() {} // RST 30
void Cpu::opcode_0xF8() {} // LDHL SP,d
void Cpu::opcode_0xF9() {} // LD SP,HL
void Cpu::opcode_0xFA() {} // LD A,(nn)
void Cpu::opcode_0xFB() {} // EI
void Cpu::opcode_0xFC() { std::cout << "Removed op" << std::endl; return; } // XX
void Cpu::opcode_0xFD() { std::cout << "Removed op" << std::endl; return; } // XX
void Cpu::opcode_0xFE() {} // CP n
void Cpu::opcode_0xFF() {} // RST 38