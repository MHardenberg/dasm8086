#include<instructionList.h>


InstructionList *createInstructionList(size_t prealloc) {
        InstructionList *list = malloc(sizeof(InstructionList));
        list->cap = prealloc;
        list->size = 0;

        list->data = malloc(list->cap * sizeof(Instruction));
        return list;
}

void destroyInstructionList(InstructionList *list) {
        free(list->data);
        free(list);
}

int reallocInstructionList(InstructionList * const list, const unsigned int growthFac) {
        if (growthFac < 2) {
                return 1;
        }

        Instruction *newData = malloc(growthFac * list->cap * sizeof(Instruction));
        if (newData == NULL) {
                return 1;
        }

        list->cap *= growthFac;
        memcpy(newData, list->data, sizeof(Instruction) * list->size);
        free(list->data);
        list->data = newData;
        return 0;
}

int pushBackInstructionList(InstructionList *list, Instruction *item) {
        if (list == NULL && item == NULL) {
                return 1;
        }

        // check cap
        if (list->size == list->cap) {
                if (reallocInstructionList(list, 2)) {
                        return 1;
                }
        }

        // append item
        list->data[list->size] = *item;
        list->size++;
        return 0;
}


