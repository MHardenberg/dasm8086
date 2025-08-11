#include "../external/theImperialArena/include/arena.h"
#include <stdio.h>

#ifdef DEBUG
#define LOG(...)                                                               \
        do {                                                                   \
                fprintf(stderr, __VA_ARGS__);                                  \
                fprintf(stderr, "\n");                                         \
        } while (0)

#define LOGERROR(...)                                                          \
        do {                                                                   \
                fprintf(stderr, "Error: <%s on line %d>\n\t", __FILE__,        \
                        __LINE__);                                             \
                LOG(__VA_ARGS__);                                              \
        } while (0)
#else
#define LOG(fmt, ...)                                                          \
        do {                                                                   \
        } while (0)
#define LOGERROR(fmt, ...)                                                     \
        do {                                                                   \
        } while (0)
#endif

int main(int argc, char **argv) {
        assert(argc >= 2);

        Arena textBuff;
        if (ArenaInit(&textBuff)) {
                LOGERROR("failed to create arena. Anorting..");
                return 1;
        }


        FILE *asmFile;
        fopen(argv[1], "rb");

        return 0;
}
