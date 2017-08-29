//
// Created by root on 8/27/17.
//

#include <iostream>
#include "cpu.h"

void Cpu::opcode_0x00() { return; } // NOP
void Cpu::opcode_0x01() { h_ld(); } // LD BC,nn
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