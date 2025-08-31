#include <defs.h>
#include <stdio.h>
#include <instruction.h>
#include <instructionList.h>
#include <dsaString.h>

int main(int argc, char **argv) {
        if (argv[1] == NULL) {
                LOGERROR("failed to open file. Aborting..");
        }

        FILE *binFile = fopen(argv[1], "rb");

        if (binFile == NULL) {
                LOGERROR("failed to open file. Aborting..");
                return 1;
        }

        InstructionList *instructions = createInstructionList(10);
        Instruction inst;
        InstructionBin instBin;
        String stringBuff;
        if (createString(&stringBuff, 4096)) {
                return 1;
        }

        while (fread(&instBin, sizeof(char), 2, binFile)) {
                LOG("%x", instBin.word);
                decodeInstruction(&inst, instBin);
                encodeInstruction(&stringBuff, &inst);

                LOG(stringBuff.cstr);

                if (pushBackInstructionList(instructions, &inst)) {
                        LOGERROR("Failed to append to list");
                }
        };

        fclose(binFile);
        destroyInstructionList(instructions);
        destroyString(&stringBuff);
        return 0;
}
