#include <instruction.h>



int stringifyInstruction(char *const dest, const Instruction *inst) {
        if (dest == NULL) {
                return 1;
        }
        if (inst == NULL) {
                return 1;
        }

        return 0;
}

int parseInstruction(Instruction *inst, InstructionBin bin) {
        if (inst == NULL) {
                return 1;
        }

        unsigned char pattern = bin.bytes.a;
        unsigned char data = bin.bytes.b;
        // compare 8bit wide ops
        // .. none yet ..

        // compare 7bit wide ops
        // .. none yet ..

        // compare 6bit wide ops

        switch (pattern >> 2) {
        case MOV_RM_R_BYTE: {
                inst->op = MOV_OP;
                inst->width = 0b1 & pattern;
                inst->direction = 0b10 & pattern;

                inst->mod = (0b11000000 & data) >> 6;
                inst->reg = (0b00111000 & data) >> 3;
                inst->rm = 0b00000111 & data;
                break;
        }
        }

        return 0;
}
