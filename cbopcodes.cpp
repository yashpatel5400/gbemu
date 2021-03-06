//
// Created by root on 8/28/17.
//

#include "cpu.h"

void Cpu::opcode_cb0x00() {} // RLC B
void Cpu::opcode_cb0x01() {} // RLC C
void Cpu::opcode_cb0x02() {} // RLC D
void Cpu::opcode_cb0x03() {} // RLC E
void Cpu::opcode_cb0x04() {} // RLC H
void Cpu::opcode_cb0x05() {} // RLC L
void Cpu::opcode_cb0x06() {} // RLC (HL)
void Cpu::opcode_cb0x07() {} // RLC A
void Cpu::opcode_cb0x08() {} // RRC B
void Cpu::opcode_cb0x09() {} // RRC C
void Cpu::opcode_cb0x0A() {} // RRC D
void Cpu::opcode_cb0x0B() {} // RRC E
void Cpu::opcode_cb0x0C() {} // RRC H
void Cpu::opcode_cb0x0D() {} // RRC L
void Cpu::opcode_cb0x0E() {} // RRC (HL)
void Cpu::opcode_cb0x0F() {} // RRC A
void Cpu::opcode_cb0x10() {} // RL B
void Cpu::opcode_cb0x11() {} // RL C
void Cpu::opcode_cb0x12() {} // RL D
void Cpu::opcode_cb0x13() {} // RL E
void Cpu::opcode_cb0x14() {} // RL H
void Cpu::opcode_cb0x15() {} // RL L
void Cpu::opcode_cb0x16() {} // RL (HL)
void Cpu::opcode_cb0x17() {} // RL A
void Cpu::opcode_cb0x18() {} // RR B
void Cpu::opcode_cb0x19() {} // RR C
void Cpu::opcode_cb0x1A() {} // RR D
void Cpu::opcode_cb0x1B() {} // RR E
void Cpu::opcode_cb0x1C() {} // RR H
void Cpu::opcode_cb0x1D() {} // RR L
void Cpu::opcode_cb0x1E() {} // RR (HL)
void Cpu::opcode_cb0x1F() {} // RR A
void Cpu::opcode_cb0x20() {} // SLA B
void Cpu::opcode_cb0x21() {} // SLA C
void Cpu::opcode_cb0x22() {} // SLA D
void Cpu::opcode_cb0x23() {} // SLA E
void Cpu::opcode_cb0x24() {} // SLA H
void Cpu::opcode_cb0x25() {} // SLA L
void Cpu::opcode_cb0x26() {} // SLA (HL)
void Cpu::opcode_cb0x27() {} // SLA A
void Cpu::opcode_cb0x28() {} // SRA B
void Cpu::opcode_cb0x29() {} // SRA C
void Cpu::opcode_cb0x2A() {} // SRA D
void Cpu::opcode_cb0x2B() {} // SRA E
void Cpu::opcode_cb0x2C() {} // SRA H
void Cpu::opcode_cb0x2D() {} // SRA L
void Cpu::opcode_cb0x2E() {} // SRA (HL)
void Cpu::opcode_cb0x2F() {} // SRA A
void Cpu::opcode_cb0x30() {} // SWAP B
void Cpu::opcode_cb0x31() {} // SWAP C
void Cpu::opcode_cb0x32() {} // SWAP D
void Cpu::opcode_cb0x33() {} // SWAP E
void Cpu::opcode_cb0x34() {} // SWAP H
void Cpu::opcode_cb0x35() {} // SWAP L
void Cpu::opcode_cb0x36() {} // SWAP (HL)
void Cpu::opcode_cb0x37() {} // SWAP A
void Cpu::opcode_cb0x38() {} // SRL B
void Cpu::opcode_cb0x39() {} // SRL C
void Cpu::opcode_cb0x3A() {} // SRL D
void Cpu::opcode_cb0x3B() {} // SRL E
void Cpu::opcode_cb0x3C() {} // SRL H
void Cpu::opcode_cb0x3D() {} // SRL L
void Cpu::opcode_cb0x3E() {} // SRL (HL)
void Cpu::opcode_cb0x3F() {} // SRL A
void Cpu::opcode_cb0x40() {} // BIT 0,B
void Cpu::opcode_cb0x41() {} // BIT 0,C
void Cpu::opcode_cb0x42() {} // BIT 0,D
void Cpu::opcode_cb0x43() {} // BIT 0,E
void Cpu::opcode_cb0x44() {} // BIT 0,H
void Cpu::opcode_cb0x45() {} // BIT 0,L
void Cpu::opcode_cb0x46() {} // BIT 0,(HL)
void Cpu::opcode_cb0x47() {} // BIT 0,A
void Cpu::opcode_cb0x48() {} // BIT 1,B
void Cpu::opcode_cb0x49() {} // BIT 1,C
void Cpu::opcode_cb0x4A() {} // BIT 1,D
void Cpu::opcode_cb0x4B() {} // BIT 1,E
void Cpu::opcode_cb0x4C() {} // BIT 1,H
void Cpu::opcode_cb0x4D() {} // BIT 1,L
void Cpu::opcode_cb0x4E() {} // BIT 1,(HL)
void Cpu::opcode_cb0x4F() {} // BIT 1,A
void Cpu::opcode_cb0x50() {} // BIT 2,B
void Cpu::opcode_cb0x51() {} // BIT 2,C
void Cpu::opcode_cb0x52() {} // BIT 2,D
void Cpu::opcode_cb0x53() {} // BIT 2,E
void Cpu::opcode_cb0x54() {} // BIT 2,H
void Cpu::opcode_cb0x55() {} // BIT 2,L
void Cpu::opcode_cb0x56() {} // BIT 2,(HL)
void Cpu::opcode_cb0x57() {} // BIT 2,A
void Cpu::opcode_cb0x58() {} // BIT 3,B
void Cpu::opcode_cb0x59() {} // BIT 3,C
void Cpu::opcode_cb0x5A() {} // BIT 3,D
void Cpu::opcode_cb0x5B() {} // BIT 3,E
void Cpu::opcode_cb0x5C() {} // BIT 3,H
void Cpu::opcode_cb0x5D() {} // BIT 3,L
void Cpu::opcode_cb0x5E() {} // BIT 3,(HL)
void Cpu::opcode_cb0x5F() {} // BIT 3,A
void Cpu::opcode_cb0x60() {} // BIT 4,B
void Cpu::opcode_cb0x61() {} // BIT 4,C
void Cpu::opcode_cb0x62() {} // BIT 4,D
void Cpu::opcode_cb0x63() {} // BIT 4,E
void Cpu::opcode_cb0x64() {} // BIT 4,H
void Cpu::opcode_cb0x65() {} // BIT 4,L
void Cpu::opcode_cb0x66() {} // BIT 4,(HL)
void Cpu::opcode_cb0x67() {} // BIT 4,A
void Cpu::opcode_cb0x68() {} // BIT 5,B
void Cpu::opcode_cb0x69() {} // BIT 5,C
void Cpu::opcode_cb0x6A() {} // BIT 5,D
void Cpu::opcode_cb0x6B() {} // BIT 5,E
void Cpu::opcode_cb0x6C() {} // BIT 5,H
void Cpu::opcode_cb0x6D() {} // BIT 5,L
void Cpu::opcode_cb0x6E() {} // BIT 5,(HL)
void Cpu::opcode_cb0x6F() {} // BIT 5,A
void Cpu::opcode_cb0x70() {} // BIT 6,B
void Cpu::opcode_cb0x71() {} // BIT 6,C
void Cpu::opcode_cb0x72() {} // BIT 6,D
void Cpu::opcode_cb0x73() {} // BIT 6,E
void Cpu::opcode_cb0x74() {} // BIT 6,H
void Cpu::opcode_cb0x75() {} // BIT 6,L
void Cpu::opcode_cb0x76() {} // BIT 6,(HL)
void Cpu::opcode_cb0x77() {} // BIT 6,A
void Cpu::opcode_cb0x78() {} // BIT 7,B
void Cpu::opcode_cb0x79() {} // BIT 7,C
void Cpu::opcode_cb0x7A() {} // BIT 7,D
void Cpu::opcode_cb0x7B() {} // BIT 7,E
void Cpu::opcode_cb0x7C() {} // BIT 7,H
void Cpu::opcode_cb0x7D() {} // BIT 7,L
void Cpu::opcode_cb0x7E() {} // BIT 7,(HL)
void Cpu::opcode_cb0x7F() {} // BIT 7,A
void Cpu::opcode_cb0x80() {} // RES 0,B
void Cpu::opcode_cb0x81() {} // RES 0,C
void Cpu::opcode_cb0x82() {} // RES 0,D
void Cpu::opcode_cb0x83() {} // RES 0,E
void Cpu::opcode_cb0x84() {} // RES 0,H
void Cpu::opcode_cb0x85() {} // RES 0,L
void Cpu::opcode_cb0x86() {} // RES 0,(HL)
void Cpu::opcode_cb0x87() {} // RES 0,A
void Cpu::opcode_cb0x88() {} // RES 1,B
void Cpu::opcode_cb0x89() {} // RES 1,C
void Cpu::opcode_cb0x8A() {} // RES 1,D
void Cpu::opcode_cb0x8B() {} // RES 1,E
void Cpu::opcode_cb0x8C() {} // RES 1,H
void Cpu::opcode_cb0x8D() {} // RES 1,L
void Cpu::opcode_cb0x8E() {} // RES 1,(HL)
void Cpu::opcode_cb0x8F() {} // RES 1,A
void Cpu::opcode_cb0x90() {} // RES 2,B
void Cpu::opcode_cb0x91() {} // RES 2,C
void Cpu::opcode_cb0x92() {} // RES 2,D
void Cpu::opcode_cb0x93() {} // RES 2,E
void Cpu::opcode_cb0x94() {} // RES 2,H
void Cpu::opcode_cb0x95() {} // RES 2,L
void Cpu::opcode_cb0x96() {} // RES 2,(HL)
void Cpu::opcode_cb0x97() {} // RES 2,A
void Cpu::opcode_cb0x98() {} // RES 3,B
void Cpu::opcode_cb0x99() {} // RES 3,C
void Cpu::opcode_cb0x9A() {} // RES 3,D
void Cpu::opcode_cb0x9B() {} // RES 3,E
void Cpu::opcode_cb0x9C() {} // RES 3,H
void Cpu::opcode_cb0x9D() {} // RES 3,L
void Cpu::opcode_cb0x9E() {} // RES 3,(HL)
void Cpu::opcode_cb0x9F() {} // RES 3,A
void Cpu::opcode_cb0xA0() {} // RES 4,B
void Cpu::opcode_cb0xA1() {} // RES 4,C
void Cpu::opcode_cb0xA2() {} // RES 4,D
void Cpu::opcode_cb0xA3() {} // RES 4,E
void Cpu::opcode_cb0xA4() {} // RES 4,H
void Cpu::opcode_cb0xA5() {} // RES 4,L
void Cpu::opcode_cb0xA6() {} // RES 4,(HL)
void Cpu::opcode_cb0xA7() {} // RES 4,A
void Cpu::opcode_cb0xA8() {} // RES 5,B
void Cpu::opcode_cb0xA9() {} // RES 5,C
void Cpu::opcode_cb0xAA() {} // RES 5,D
void Cpu::opcode_cb0xAB() {} // RES 5,E
void Cpu::opcode_cb0xAC() {} // RES 5,H
void Cpu::opcode_cb0xAD() {} // RES 5,L
void Cpu::opcode_cb0xAE() {} // RES 5,(HL)
void Cpu::opcode_cb0xAF() {} // RES 5,A
void Cpu::opcode_cb0xB0() {} // RES 6,B
void Cpu::opcode_cb0xB1() {} // RES 6,C
void Cpu::opcode_cb0xB2() {} // RES 6,D
void Cpu::opcode_cb0xB3() {} // RES 6,E
void Cpu::opcode_cb0xB4() {} // RES 6,H
void Cpu::opcode_cb0xB5() {} // RES 6,L
void Cpu::opcode_cb0xB6() {} // RES 6,(HL)
void Cpu::opcode_cb0xB7() {} // RES 6,A
void Cpu::opcode_cb0xB8() {} // RES 7,B
void Cpu::opcode_cb0xB9() {} // RES 7,C
void Cpu::opcode_cb0xBA() {} // RES 7,D
void Cpu::opcode_cb0xBB() {} // RES 7,E
void Cpu::opcode_cb0xBC() {} // RES 7,H
void Cpu::opcode_cb0xBD() {} // RES 7,L
void Cpu::opcode_cb0xBE() {} // RES 7,(HL)
void Cpu::opcode_cb0xBF() {} // RES 7,A
void Cpu::opcode_cb0xC0() {} // SET 0,B
void Cpu::opcode_cb0xC1() {} // SET 0,C
void Cpu::opcode_cb0xC2() {} // SET 0,D
void Cpu::opcode_cb0xC3() {} // SET 0,E
void Cpu::opcode_cb0xC4() {} // SET 0,H
void Cpu::opcode_cb0xC5() {} // SET 0,L
void Cpu::opcode_cb0xC6() {} // SET 0,(HL)
void Cpu::opcode_cb0xC7() {} // SET 0,A
void Cpu::opcode_cb0xC8() {} // SET 1,B
void Cpu::opcode_cb0xC9() {} // SET 1,C
void Cpu::opcode_cb0xCA() {} // SET 1,D
void Cpu::opcode_cb0xCB() {} // SET 1,E
void Cpu::opcode_cb0xCC() {} // SET 1,H
void Cpu::opcode_cb0xCD() {} // SET 1,L
void Cpu::opcode_cb0xCE() {} // SET 1,(HL)
void Cpu::opcode_cb0xCF() {} // SET 1,A
void Cpu::opcode_cb0xD0() {} // SET 2,B
void Cpu::opcode_cb0xD1() {} // SET 2,C
void Cpu::opcode_cb0xD2() {} // SET 2,D
void Cpu::opcode_cb0xD3() {} // SET 2,E
void Cpu::opcode_cb0xD4() {} // SET 2,H
void Cpu::opcode_cb0xD5() {} // SET 2,L
void Cpu::opcode_cb0xD6() {} // SET 2,(HL)
void Cpu::opcode_cb0xD7() {} // SET 2,A
void Cpu::opcode_cb0xD8() {} // SET 3,B
void Cpu::opcode_cb0xD9() {} // SET 3,C
void Cpu::opcode_cb0xDA() {} // SET 3,D
void Cpu::opcode_cb0xDB() {} // SET 3,E
void Cpu::opcode_cb0xDC() {} // SET 3,H
void Cpu::opcode_cb0xDD() {} // SET 3,L
void Cpu::opcode_cb0xDE() {} // SET 3,(HL)
void Cpu::opcode_cb0xDF() {} // SET 3,A
void Cpu::opcode_cb0xE0() {} // SET 4,B
void Cpu::opcode_cb0xE1() {} // SET 4,C
void Cpu::opcode_cb0xE2() {} // SET 4,D
void Cpu::opcode_cb0xE3() {} // SET 4,E
void Cpu::opcode_cb0xE4() {} // SET 4,H
void Cpu::opcode_cb0xE5() {} // SET 4,L
void Cpu::opcode_cb0xE6() {} // SET 4,(HL)
void Cpu::opcode_cb0xE7() {} // SET 4,A
void Cpu::opcode_cb0xE8() {} // SET 5,B
void Cpu::opcode_cb0xE9() {} // SET 5,C
void Cpu::opcode_cb0xEA() {} // SET 5,D
void Cpu::opcode_cb0xEB() {} // SET 5,E
void Cpu::opcode_cb0xEC() {} // SET 5,H
void Cpu::opcode_cb0xED() {} // SET 5,L
void Cpu::opcode_cb0xEE() {} // SET 5,(HL)
void Cpu::opcode_cb0xEF() {} // SET 5,A
void Cpu::opcode_cb0xF0() {} // SET 6,B
void Cpu::opcode_cb0xF1() {} // SET 6,C
void Cpu::opcode_cb0xF2() {} // SET 6,D
void Cpu::opcode_cb0xF3() {} // SET 6,E
void Cpu::opcode_cb0xF4() {} // SET 6,H
void Cpu::opcode_cb0xF5() {} // SET 6,L
void Cpu::opcode_cb0xF6() {} // SET 6,(HL)
void Cpu::opcode_cb0xF7() {} // SET 6,A
void Cpu::opcode_cb0xF8() {} // SET 7,B
void Cpu::opcode_cb0xF9() {} // SET 7,C
void Cpu::opcode_cb0xFA() {} // SET 7,D
void Cpu::opcode_cb0xFB() {} // SET 7,E
void Cpu::opcode_cb0xFC() {} // SET 7,H
void Cpu::opcode_cb0xFD() {} // SET 7,L
void Cpu::opcode_cb0xFE() {} // SET 7,(HL)
void Cpu::opcode_cb0xFF() {} // SET 7,A