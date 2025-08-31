#include <instruction.h>
#include "debug.h"

int decodeInstruction(Instruction *inst, InstructionBin bin) {
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

int encodeInstruction(String *dest, Instruction *inst) {
        if (dest == NULL || inst == NULL) {
                return 1;
        }

        switch (inst->op) {
        case MOV_OP: {
                const char operationCode[] = "mov ";
                stringPushBack(dest, operationCode);
                break;
        }

        case DEFAULT_OP: {
                LOGERROR("Invalid function");
        }
        }

        return 0;
}
