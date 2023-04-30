#include <string.h>

#include "cpu.h"





GBCPU::GBCPU() {
    // Zero out registers
    memset(&registers, 0, sizeof(gb_cpu_registers));

}

void GBCPU::set_pc(short int pc) {
    registers.pc = pc;
}

void GBCPU::run() {
    ;
}


// CPU Methods

bool GBCPU::is_zero() {
    return (registers.f & (1 << 5)) != 0;
}

bool GBCPU::is_subtraction() {
    return (registers.f & (1 << 4)) != 0;
}

bool GBCPU::is_half_carry() {
    return (registers.f & (1 << 3)) != 0;
}

bool GBCPU::is_carry() {
    return (registers.f & (1 << 2)) != 0;
}


void GBCPU::set_flag_zero(bool s) {
    if (s) {
        registers.f = registers.f | (1 << 5);
    }
    else {
        registers.f = registers.f & ~(1 << 5);
    }

}
void GBCPU::set_flag_subtraction(bool s) {
    if (s) {
        registers.f = registers.f | (1 << 4);
    }
    else {
        registers.f = registers.f & ~(1 << 4);
    }

}
void GBCPU::set_flag_half_carry(bool s) {
    if (s) {
        registers.f = registers.f | (1 << 3);
    }
    else {
        registers.f = registers.f & ~(1 << 3);
    }

}
void GBCPU::set_flag_carry(bool s) {
    if (s) {
        registers.f = registers.f | (1 << 2);
    }
    else {
        registers.f = registers.f & ~(1 << 2);
    }
}


cycles GBCPU::execute_opcode(uint16_t opcode) {
    ;
}
