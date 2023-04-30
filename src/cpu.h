#pragma once

#include <stdint.h>

#define cycles int  // return type to track number of cycles passed

struct gb_cpu_registers{
    uint8_t a;         //Accumulator
    uint8_t f;         //Flags
    uint16_t bc;
    uint16_t de;
    uint16_t hl;
    uint16_t sp;       // Stack Pointer
    uint16_t pc;       // Program Counter
};

class GBCPU {
    public:
        // Constructor
        GBCPU();

        // Member functions
        void set_pc(short int pc);
        void run();

        // CPU methods
        bool is_zero();
        bool is_subtraction();
        bool is_half_carry();
        bool is_carry();
        void set_flag_zero(bool s);
        void set_flag_subtraction(bool s);
        void set_flag_half_carry(bool s);
        void set_flag_carry(bool s);

        cycles execute_opcode(uint16_t opcode);

    private:
        gb_cpu_registers registers;
        char flags;
};