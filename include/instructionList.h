#ifndef instructionList_H
#define instructionList_H
#include <defs.h>
#include <instruction.h>

typedef struct {
        size_t size;
        size_t cap;
        Instruction *data;
} InstructionList;

InstructionList *createInstructionList(size_t prealloc);

void destroyInstructionList(InstructionList *list);

int reallocInstructionList(InstructionList *const list,
                           const unsigned int growthFac);

int pushBackInstructionList(InstructionList *list, Instruction *item);
#endif // instructionList_H
