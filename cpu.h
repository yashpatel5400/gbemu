//x
// Created by root on 8/26/17.
//

#ifndef GBEMU_CPU_H
#define GBEMU_CPU_H

class Cpu {
private:
    // The Z80 is an 8-bit chip, so all the internal workings operate on one byte at a time;
    // The memory interface can address up to 65,536 bytes (a 16-bit address bus);

    // $FFFF	    Interrupt Enable Flag
    // $FF80-$FFFE	Zero Page - 127 bytes
    // $FF00-$FF7F	Hardware I/O Registers
    // $FEA0-$FEFF	Unusable Memory
    // $FE00-$FE9F	OAM - Object Attribute Memory
    // $E000-$FDFF	Echo RAM - Reserved, Do Not Use
    // $D000-$DFFF	Internal RAM - Bank 1-7 (switchable - CGB only)
    // $C000-$CFFF	Internal RAM - Bank 0 (fixed)
    // $A000-$BFFF	Cartridge RAM (If Available)
    // $9C00-$9FFF	BG Map Data 2
    // $9800-$9BFF	BG Map Data 1
    // $8000-$97FF	Character RAM
    // $4000-$7FFF	Cartridge ROM - Switchable Banks 1-xx
    // $0150-$3FFF	Cartridge ROM - Bank 0 (fixed)
    // $0100-$014F	Cartridge Header Area
    // $0000-$00FF	Restart and Interrupt Vectors
    unsigned char m_memory[65536];

    // Programs are accessed through the same address bus as normal memory;
    // An instruction can be anywhere between one and three bytes.
    struct instruction {
        const char* opcodeDesriptor; // description of the opcode
        unsigned int opcodeArgc;     // number of arguments the opcode takes
        void* opcodeHandler;         // function used to handle that opcode
    };

    // Registers: A, B, C, D, E, H, and L. Each of them is one byte, so each one can hold a
    // value from 0 to 255.
    struct cpuRegisters {
        // each of the registers must EITHER occur separately (i.e. each of b,c has own value)
        // or combined into effectively a "single register" for holding 16-bit values
        struct {
            union {
                struct {
                    unsigned char a;
                    unsigned char f;
                };
                unsigned short af;
            };
        };

        struct {
            union {
                struct {
                    unsigned char b;
                    unsigned char c;
                };
                unsigned short bc;
            };
        };

        struct {
            union {
                struct {
                    unsigned char d;
                    unsigned char e;
                };
                unsigned short de;
            };
        };

        struct {
            union {
                struct {
                    unsigned char h;
                    unsigned char l;
                };
                unsigned short hl;
            };
        };

        unsigned short pc, sp;                        // 16-bit registers
    };
    cpuRegisters m_registers;

    // returns function pointer used to handle the opcode in question
    void* handleOpcode(unsigned char opcode);
    void* handleCbOpcode(unsigned char opcode);

    // "h_" prefix is intended to signal "helper," meaning that these should only be called within
    // the context of the opcodes rather than in independent contexts

    // general (1-byte) opcodes: non-CB
    void h_ld(); // 8-bit address store

    void h_inc();
    void h_dec();
    void h_rlc();

    void h_add();
    void h_sub();

    void h_and();
    void h_or();
    void h_xor();

    void h_push();
    void h_pop();

    void h_jp();
    void h_call();
    void h_ret();

    void h_adc();
    void h_sbc();



public:
    Cpu();
    ~Cpu();

    void loadGame(const char* filename);
    void step();

    // we have two types of opcodes:
    // - 1 bytes (regular opcodes)
    void opcode_0x00() {} // 0, NOP
    void opcode_0x01(unsigned short nn) {} // 2, LD BC,nn
    void opcode_0x02() {} // 0, LD (BC),A
    void opcode_0x03() {} // 0, INC BC
    void opcode_0x04() {} // 0, INC B
    void opcode_0x05() {} // 0, DEC B
    void opcode_0x06(unsigned char n) {} // 1, LD B,n
    void opcode_0x07() {} // 0, RLC A
    void opcode_0x08(unsigned short nn) {} // 2, LD (nn),SP
    void opcode_0x09() {} // 0, ADD HL,BC
    void opcode_0x0A() {} // 0, LD A,(BC)
    void opcode_0x0B() {} // 0, DEC BC
    void opcode_0x0C() {} // 0, INC C
    void opcode_0x0D() {} // 0, DEC C
    void opcode_0x0E(unsigned char n) {} // 1, LD C,n
    void opcode_0x0F() {} // 0, RRC A
    void opcode_0x10(unsigned char n) {} // 1, STOP
    void opcode_0x11(unsigned short nn) {} // 2, LD DE,nn
    void opcode_0x12() {} // 0, LD (DE),A
    void opcode_0x13() {} // 0, INC DE
    void opcode_0x14() {} // 0, INC D
    void opcode_0x15() {} // 0, DEC D
    void opcode_0x16(unsigned char n) {} // 1, LD D,n
    void opcode_0x17() {} // 0, RL A
    void opcode_0x18(unsigned char n) {} // 1, JR n
    void opcode_0x19() {} // 0, ADD HL,DE
    void opcode_0x1A() {} // 0, LD A,(DE)
    void opcode_0x1B() {} // 0, DEC DE
    void opcode_0x1C() {} // 0, INC E
    void opcode_0x1D() {} // 0, DEC E
    void opcode_0x1E(unsigned char n) {} // 1, LD E,n
    void opcode_0x1F() {} // 0, RR A
    void opcode_0x20(unsigned char n) {} // 1, JR NZ,n
    void opcode_0x21(unsigned short nn) {} // 2, LD HL,nn
    void opcode_0x22() {} // 0, LDI (HL),A
    void opcode_0x23() {} // 0, INC HL
    void opcode_0x24() {} // 0, INC H
    void opcode_0x25() {} // 0, DEC H
    void opcode_0x26(unsigned char n) {} // 1, LD H,n
    void opcode_0x27() {} // 0, DAA
    void opcode_0x28(unsigned char n) {} // 1, JR Z,n
    void opcode_0x29() {} // 0, ADD HL,HL
    void opcode_0x2A() {} // 0, LDI A,(HL)
    void opcode_0x2B() {} // 0, DEC HL
    void opcode_0x2C() {} // 0, INC L
    void opcode_0x2D() {} // 0, DEC L
    void opcode_0x2E(unsigned char n) {} // 1, LD L,n
    void opcode_0x2F() {} // 0, CPL
    void opcode_0x30(unsigned char n) {} // 1, JR NC,n
    void opcode_0x31(unsigned short nn) {} // 2, LD SP,nn
    void opcode_0x32() {} // 0, LDD (HL),A
    void opcode_0x33() {} // 0, INC SP
    void opcode_0x34() {} // 0, INC (HL)
    void opcode_0x35() {} // 0, DEC (HL)
    void opcode_0x36(unsigned char n) {} // 1, LD (HL),n
    void opcode_0x37() {} // 0, SCF
    void opcode_0x38(unsigned char n) {} // 1, JR C,n
    void opcode_0x39() {} // 0, ADD HL,SP
    void opcode_0x3A() {} // 0, LDD A,(HL)
    void opcode_0x3B() {} // 0, DEC SP
    void opcode_0x3C() {} // 0, INC A
    void opcode_0x3D() {} // 0, DEC A
    void opcode_0x3E(unsigned char n) {} // 1, LD A,n
    void opcode_0x3F() {} // 0, CCF
    void opcode_0x40() {} // 0, LD B,B
    void opcode_0x41() {} // 0, LD B,C
    void opcode_0x42() {} // 0, LD B,D
    void opcode_0x43() {} // 0, LD B,E
    void opcode_0x44() {} // 0, LD B,H
    void opcode_0x45() {} // 0, LD B,L
    void opcode_0x46() {} // 0, LD B,(HL)
    void opcode_0x47() {} // 0, LD B,A
    void opcode_0x48() {} // 0, LD C,B
    void opcode_0x49() {} // 0, LD C,C
    void opcode_0x4A() {} // 0, LD C,D
    void opcode_0x4B() {} // 0, LD C,E
    void opcode_0x4C() {} // 0, LD C,H
    void opcode_0x4D() {} // 0, LD C,L
    void opcode_0x4E() {} // 0, LD C,(HL)
    void opcode_0x4F() {} // 0, LD C,A
    void opcode_0x50() {} // 0, LD D,B
    void opcode_0x51() {} // 0, LD D,C
    void opcode_0x52() {} // 0, LD D,D
    void opcode_0x53() {} // 0, LD D,E
    void opcode_0x54() {} // 0, LD D,H
    void opcode_0x55() {} // 0, LD D,L
    void opcode_0x56() {} // 0, LD D,(HL)
    void opcode_0x57() {} // 0, LD D,A
    void opcode_0x58() {} // 0, LD E,B
    void opcode_0x59() {} // 0, LD E,C
    void opcode_0x5A() {} // 0, LD E,D
    void opcode_0x5B() {} // 0, LD E,E
    void opcode_0x5C() {} // 0, LD E,H
    void opcode_0x5D() {} // 0, LD E,L
    void opcode_0x5E() {} // 0, LD E,(HL)
    void opcode_0x5F() {} // 0, LD E,A
    void opcode_0x60() {} // 0, LD H,B
    void opcode_0x61() {} // 0, LD H,C
    void opcode_0x62() {} // 0, LD H,D
    void opcode_0x63() {} // 0, LD H,E
    void opcode_0x64() {} // 0, LD H,H
    void opcode_0x65() {} // 0, LD H,L
    void opcode_0x66() {} // 0, LD H,(HL)
    void opcode_0x67() {} // 0, LD H,A
    void opcode_0x68() {} // 0, LD L,B
    void opcode_0x69() {} // 0, LD L,C
    void opcode_0x6A() {} // 0, LD L,D
    void opcode_0x6B() {} // 0, LD L,E
    void opcode_0x6C() {} // 0, LD L,H
    void opcode_0x6D() {} // 0, LD L,L
    void opcode_0x6E() {} // 0, LD L,(HL)
    void opcode_0x6F() {} // 0, LD L,A
    void opcode_0x70() {} // 0, LD (HL),B
    void opcode_0x71() {} // 0, LD (HL),C
    void opcode_0x72() {} // 0, LD (HL),D
    void opcode_0x73() {} // 0, LD (HL),E
    void opcode_0x74() {} // 0, LD (HL),H
    void opcode_0x75() {} // 0, LD (HL),L
    void opcode_0x76() {} // 0, HALT
    void opcode_0x77() {} // 0, LD (HL),A
    void opcode_0x78() {} // 0, LD A,B
    void opcode_0x79() {} // 0, LD A,C
    void opcode_0x7A() {} // 0, LD A,D
    void opcode_0x7B() {} // 0, LD A,E
    void opcode_0x7C() {} // 0, LD A,H
    void opcode_0x7D() {} // 0, LD A,L
    void opcode_0x7E() {} // 0, LD A,(HL)
    void opcode_0x7F() {} // 0, LD A,A
    void opcode_0x80() {} // 0, ADD A,B
    void opcode_0x81() {} // 0, ADD A,C
    void opcode_0x82() {} // 0, ADD A,D
    void opcode_0x83() {} // 0, ADD A,E
    void opcode_0x84() {} // 0, ADD A,H
    void opcode_0x85() {} // 0, ADD A,L
    void opcode_0x86() {} // 0, ADD A,(HL)
    void opcode_0x87() {} // 0, ADD A,A
    void opcode_0x88() {} // 0, ADC A,B
    void opcode_0x89() {} // 0, ADC A,C
    void opcode_0x8A() {} // 0, ADC A,D
    void opcode_0x8B() {} // 0, ADC A,E
    void opcode_0x8C() {} // 0, ADC A,H
    void opcode_0x8D() {} // 0, ADC A,L
    void opcode_0x8E() {} // 0, ADC A,(HL)
    void opcode_0x8F() {} // 0, ADC A,A
    void opcode_0x90() {} // 0, SUB A,B
    void opcode_0x91() {} // 0, SUB A,C
    void opcode_0x92() {} // 0, SUB A,D
    void opcode_0x93() {} // 0, SUB A,E
    void opcode_0x94() {} // 0, SUB A,H
    void opcode_0x95() {} // 0, SUB A,L
    void opcode_0x96() {} // 0, SUB A,(HL)
    void opcode_0x97() {} // 0, SUB A,A
    void opcode_0x98() {} // 0, SBC A,B
    void opcode_0x99() {} // 0, SBC A,C
    void opcode_0x9A() {} // 0, SBC A,D
    void opcode_0x9B() {} // 0, SBC A,E
    void opcode_0x9C() {} // 0, SBC A,H
    void opcode_0x9D() {} // 0, SBC A,L
    void opcode_0x9E() {} // 0, SBC A,(HL)
    void opcode_0x9F() {} // 0, SBC A,A
    void opcode_0xA0() {} // 0, AND B
    void opcode_0xA1() {} // 0, AND C
    void opcode_0xA2() {} // 0, AND D
    void opcode_0xA3() {} // 0, AND E
    void opcode_0xA4() {} // 0, AND H
    void opcode_0xA5() {} // 0, AND L
    void opcode_0xA6() {} // 0, AND (HL)
    void opcode_0xA7() {} // 0, AND A
    void opcode_0xA8() {} // 0, XOR B
    void opcode_0xA9() {} // 0, XOR C
    void opcode_0xAA() {} // 0, XOR D
    void opcode_0xAB() {} // 0, XOR E
    void opcode_0xAC() {} // 0, XOR H
    void opcode_0xAD() {} // 0, XOR L
    void opcode_0xAE() {} // 0, XOR (HL)
    void opcode_0xAF() {} // 0, XOR A
    void opcode_0xB0() {} // 0, OR B
    void opcode_0xB1() {} // 0, OR C
    void opcode_0xB2() {} // 0, OR D
    void opcode_0xB3() {} // 0, OR E
    void opcode_0xB4() {} // 0, OR H
    void opcode_0xB5() {} // 0, OR L
    void opcode_0xB6() {} // 0, OR (HL)
    void opcode_0xB7() {} // 0, OR A
    void opcode_0xB8() {} // 0, CP B
    void opcode_0xB9() {} // 0, CP C
    void opcode_0xBA() {} // 0, CP D
    void opcode_0xBB() {} // 0, CP E
    void opcode_0xBC() {} // 0, CP H
    void opcode_0xBD() {} // 0, CP L
    void opcode_0xBE() {} // 0, CP (HL)
    void opcode_0xBF() {} // 0, CP A
    void opcode_0xC0() {} // 0, RET NZ
    void opcode_0xC1() {} // 0, POP BC
    void opcode_0xC2(unsigned short nn) {} // 2, JP NZ,nn
    void opcode_0xC3(unsigned short nn) {} // 2, JP nn
    void opcode_0xC4(unsigned short nn) {} // 2, CALL NZ,nn
    void opcode_0xC5() {} // 0, PUSH BC
    void opcode_0xC6(unsigned char n) {} // 1, ADD A,n
    void opcode_0xC7() {} // 0, RST 0
    void opcode_0xC8() {} // 0, RET Z
    void opcode_0xC9() {} // 0, RET
    void opcode_0xCA(unsigned short nn) {} // 2, JP Z,nn
    void opcode_0xCB(unsigned char n) {} // 1, Ext ops
    void opcode_0xCC(unsigned short nn) {} // 2, CALL Z,nn
    void opcode_0xCD(unsigned short nn) {} // 2, CALL nn
    void opcode_0xCE(unsigned char n) {} // 1, ADC A,n
    void opcode_0xCF() {} // 0, RST 8
    void opcode_0xD0() {} // 0, RET NC
    void opcode_0xD1() {} // 0, POP DE
    void opcode_0xD2(unsigned short nn) {} // 2, JP NC,nn
    void opcode_0xD3() {} // 0, XX
    void opcode_0xD4(unsigned short nn) {} // 2, CALL NC,nn
    void opcode_0xD5() {} // 0, PUSH DE
    void opcode_0xD6(unsigned char n) {} // 1, SUB A,n
    void opcode_0xD7() {} // 0, RST 10
    void opcode_0xD8() {} // 0, RET C
    void opcode_0xD9() {} // 0, RETI
    void opcode_0xDA(unsigned short nn) {} // 2, JP C,nn
    void opcode_0xDB() {} // 0, XX
    void opcode_0xDC(unsigned short nn) {} // 2, CALL C,nn
    void opcode_0xDD() {} // 0, XX
    void opcode_0xDE(unsigned char n) {} // 1, SBC A,n
    void opcode_0xDF() {} // 0, RST 18
    void opcode_0xE0(unsigned char n) {} // 1, LDH (n),A
    void opcode_0xE1() {} // 0, POP HL
    void opcode_0xE2() {} // 0, LDH (C),A
    void opcode_0xE3() {} // 0, XX
    void opcode_0xE4() {} // 0, XX
    void opcode_0xE5() {} // 0, PUSH HL
    void opcode_0xE6(unsigned char n) {} // 1, AND n
    void opcode_0xE7() {} // 0, RST 20
    void opcode_0xE8(unsigned char n) {} // 1, ADD SP,d
    void opcode_0xE9() {} // 0, JP (HL)
    void opcode_0xEA(unsigned short nn) {} // 2, LD (nn),A
    void opcode_0xEB() {} // 0, XX
    void opcode_0xEC() {} // 0, XX
    void opcode_0xED() {} // 0, XX
    void opcode_0xEE(unsigned char n) {} // 1, XOR n
    void opcode_0xEF() {} // 0, RST 28
    void opcode_0xF0(unsigned char n) {} // 1, LDH A,(n)
    void opcode_0xF1() {} // 0, POP AF
    void opcode_0xF2() {} // 0, XX
    void opcode_0xF3() {} // 0, DI
    void opcode_0xF4() {} // 0, XX
    void opcode_0xF5() {} // 0, PUSH AF
    void opcode_0xF6(unsigned char n) {} // 1, OR n
    void opcode_0xF7() {} // 0, RST 30
    void opcode_0xF8(unsigned char n) {} // 1, LDHL SP,d
    void opcode_0xF9() {} // 0, LD SP,HL
    void opcode_0xFA(unsigned short nn) {} // 2, LD A,(nn)
    void opcode_0xFB() {} // 0, EI
    void opcode_0xFC() {} // 0, XX
    void opcode_0xFD() {} // 0, XX
    void opcode_0xFE(unsigned char n) {} // 1, CP n
    void opcode_0xFF() {} // 0, RST 38

    // - 2 bytes (CB-prefixed opcodes)
    void opcode_cb0x00();
    void opcode_cb0x01();
    void opcode_cb0x02();
    void opcode_cb0x03();
    void opcode_cb0x04();
    void opcode_cb0x05();
    void opcode_cb0x06();
    void opcode_cb0x07();
    void opcode_cb0x08();
    void opcode_cb0x09();
    void opcode_cb0x0A();
    void opcode_cb0x0B();
    void opcode_cb0x0C();
    void opcode_cb0x0D();
    void opcode_cb0x0E();
    void opcode_cb0x0F();
    void opcode_cb0x10();
    void opcode_cb0x11();
    void opcode_cb0x12();
    void opcode_cb0x13();
    void opcode_cb0x14();
    void opcode_cb0x15();
    void opcode_cb0x16();
    void opcode_cb0x17();
    void opcode_cb0x18();
    void opcode_cb0x19();
    void opcode_cb0x1A();
    void opcode_cb0x1B();
    void opcode_cb0x1C();
    void opcode_cb0x1D();
    void opcode_cb0x1E();
    void opcode_cb0x1F();
    void opcode_cb0x20();
    void opcode_cb0x21();
    void opcode_cb0x22();
    void opcode_cb0x23();
    void opcode_cb0x24();
    void opcode_cb0x25();
    void opcode_cb0x26();
    void opcode_cb0x27();
    void opcode_cb0x28();
    void opcode_cb0x29();
    void opcode_cb0x2A();
    void opcode_cb0x2B();
    void opcode_cb0x2C();
    void opcode_cb0x2D();
    void opcode_cb0x2E();
    void opcode_cb0x2F();
    void opcode_cb0x30();
    void opcode_cb0x31();
    void opcode_cb0x32();
    void opcode_cb0x33();
    void opcode_cb0x34();
    void opcode_cb0x35();
    void opcode_cb0x36();
    void opcode_cb0x37();
    void opcode_cb0x38();
    void opcode_cb0x39();
    void opcode_cb0x3A();
    void opcode_cb0x3B();
    void opcode_cb0x3C();
    void opcode_cb0x3D();
    void opcode_cb0x3E();
    void opcode_cb0x3F();
    void opcode_cb0x40();
    void opcode_cb0x41();
    void opcode_cb0x42();
    void opcode_cb0x43();
    void opcode_cb0x44();
    void opcode_cb0x45();
    void opcode_cb0x46();
    void opcode_cb0x47();
    void opcode_cb0x48();
    void opcode_cb0x49();
    void opcode_cb0x4A();
    void opcode_cb0x4B();
    void opcode_cb0x4C();
    void opcode_cb0x4D();
    void opcode_cb0x4E();
    void opcode_cb0x4F();
    void opcode_cb0x50();
    void opcode_cb0x51();
    void opcode_cb0x52();
    void opcode_cb0x53();
    void opcode_cb0x54();
    void opcode_cb0x55();
    void opcode_cb0x56();
    void opcode_cb0x57();
    void opcode_cb0x58();
    void opcode_cb0x59();
    void opcode_cb0x5A();
    void opcode_cb0x5B();
    void opcode_cb0x5C();
    void opcode_cb0x5D();
    void opcode_cb0x5E();
    void opcode_cb0x5F();
    void opcode_cb0x60();
    void opcode_cb0x61();
    void opcode_cb0x62();
    void opcode_cb0x63();
    void opcode_cb0x64();
    void opcode_cb0x65();
    void opcode_cb0x66();
    void opcode_cb0x67();
    void opcode_cb0x68();
    void opcode_cb0x69();
    void opcode_cb0x6A();
    void opcode_cb0x6B();
    void opcode_cb0x6C();
    void opcode_cb0x6D();
    void opcode_cb0x6E();
    void opcode_cb0x6F();
    void opcode_cb0x70();
    void opcode_cb0x71();
    void opcode_cb0x72();
    void opcode_cb0x73();
    void opcode_cb0x74();
    void opcode_cb0x75();
    void opcode_cb0x76();
    void opcode_cb0x77();
    void opcode_cb0x78();
    void opcode_cb0x79();
    void opcode_cb0x7A();
    void opcode_cb0x7B();
    void opcode_cb0x7C();
    void opcode_cb0x7D();
    void opcode_cb0x7E();
    void opcode_cb0x7F();
    void opcode_cb0x80();
    void opcode_cb0x81();
    void opcode_cb0x82();
    void opcode_cb0x83();
    void opcode_cb0x84();
    void opcode_cb0x85();
    void opcode_cb0x86();
    void opcode_cb0x87();
    void opcode_cb0x88();
    void opcode_cb0x89();
    void opcode_cb0x8A();
    void opcode_cb0x8B();
    void opcode_cb0x8C();
    void opcode_cb0x8D();
    void opcode_cb0x8E();
    void opcode_cb0x8F();
    void opcode_cb0x90();
    void opcode_cb0x91();
    void opcode_cb0x92();
    void opcode_cb0x93();
    void opcode_cb0x94();
    void opcode_cb0x95();
    void opcode_cb0x96();
    void opcode_cb0x97();
    void opcode_cb0x98();
    void opcode_cb0x99();
    void opcode_cb0x9A();
    void opcode_cb0x9B();
    void opcode_cb0x9C();
    void opcode_cb0x9D();
    void opcode_cb0x9E();
    void opcode_cb0x9F();
    void opcode_cb0xA0();
    void opcode_cb0xA1();
    void opcode_cb0xA2();
    void opcode_cb0xA3();
    void opcode_cb0xA4();
    void opcode_cb0xA5();
    void opcode_cb0xA6();
    void opcode_cb0xA7();
    void opcode_cb0xA8();
    void opcode_cb0xA9();
    void opcode_cb0xAA();
    void opcode_cb0xAB();
    void opcode_cb0xAC();
    void opcode_cb0xAD();
    void opcode_cb0xAE();
    void opcode_cb0xAF();
    void opcode_cb0xB0();
    void opcode_cb0xB1();
    void opcode_cb0xB2();
    void opcode_cb0xB3();
    void opcode_cb0xB4();
    void opcode_cb0xB5();
    void opcode_cb0xB6();
    void opcode_cb0xB7();
    void opcode_cb0xB8();
    void opcode_cb0xB9();
    void opcode_cb0xBA();
    void opcode_cb0xBB();
    void opcode_cb0xBC();
    void opcode_cb0xBD();
    void opcode_cb0xBE();
    void opcode_cb0xBF();
    void opcode_cb0xC0();
    void opcode_cb0xC1();
    void opcode_cb0xC2();
    void opcode_cb0xC3();
    void opcode_cb0xC4();
    void opcode_cb0xC5();
    void opcode_cb0xC6();
    void opcode_cb0xC7();
    void opcode_cb0xC8();
    void opcode_cb0xC9();
    void opcode_cb0xCA();
    void opcode_cb0xCB();
    void opcode_cb0xCC();
    void opcode_cb0xCD();
    void opcode_cb0xCE();
    void opcode_cb0xCF();
    void opcode_cb0xD0();
    void opcode_cb0xD1();
    void opcode_cb0xD2();
    void opcode_cb0xD3();
    void opcode_cb0xD4();
    void opcode_cb0xD5();
    void opcode_cb0xD6();
    void opcode_cb0xD7();
    void opcode_cb0xD8();
    void opcode_cb0xD9();
    void opcode_cb0xDA();
    void opcode_cb0xDB();
    void opcode_cb0xDC();
    void opcode_cb0xDD();
    void opcode_cb0xDE();
    void opcode_cb0xDF();
    void opcode_cb0xE0();
    void opcode_cb0xE1();
    void opcode_cb0xE2();
    void opcode_cb0xE3();
    void opcode_cb0xE4();
    void opcode_cb0xE5();
    void opcode_cb0xE6();
    void opcode_cb0xE7();
    void opcode_cb0xE8();
    void opcode_cb0xE9();
    void opcode_cb0xEA();
    void opcode_cb0xEB();
    void opcode_cb0xEC();
    void opcode_cb0xED();
    void opcode_cb0xEE();
    void opcode_cb0xEF();
    void opcode_cb0xF0();
    void opcode_cb0xF1();
    void opcode_cb0xF2();
    void opcode_cb0xF3();
    void opcode_cb0xF4();
    void opcode_cb0xF5();
    void opcode_cb0xF6();
    void opcode_cb0xF7();
    void opcode_cb0xF8();
    void opcode_cb0xF9();
    void opcode_cb0xFA();
    void opcode_cb0xFB();
    void opcode_cb0xFC();
    void opcode_cb0xFD();
    void opcode_cb0xFE();
    void opcode_cb0xFF();
};

#endif //GBEMU_CPU_H
