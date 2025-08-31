#ifndef instruction_H
#define instruction_H
#include <stddef.h>
#include <defs.h>
#include <dsaString.h>

#define MOV_RM_R_BYTE 0b100010
enum OpFlag { DEFAULT_OP = 0, MOV_OP };

typedef struct {
        enum OpFlag op;
        unsigned char direction;
        unsigned char width;
        unsigned char mod;
        unsigned char reg;
        unsigned char rm;
} Instruction;

typedef union {
        uint16_t word;
        struct {
                unsigned char a;
                unsigned char b;
        } bytes;
} InstructionBin;

int decodeInstruction(Instruction *inst, InstructionBin bin);

int encodeInstruction(String *dest, Instruction *inst);

#endif // instruction_H
