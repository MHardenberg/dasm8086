#ifdef DEBUG
#include <stdio.h>
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

#ifdef DEBUG
#include <stdio.h>
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
