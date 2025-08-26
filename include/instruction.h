#ifndef instruction_H
#define instruction_H
#include <stddef.h>

enum OpFlag { DEFAULT_OP = 0, MOV_OP };

typedef struct {
        enum OpFlag op;
        unsigned char direction;
        unsigned char width;
        unsigned char reg;
        unsigned char rm;
} Instruction;

#endif // instruction_H
