#ifndef string_H
#define string_H
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_GROWTH_FAC 2

typedef struct {
        size_t size;
        size_t cap;
        char *cstr;
} String;

int createString(String *string, size_t prealloc);

int growString(String *string, const size_t growthFactor);

static inline char *const stringIdx(String *const string, size_t i) {
        if (string == NULL) {
                return NULL;
        }
        if (string->cstr == NULL || i >= string->size) {
                return NULL;
        }

        return (string->cstr + i);
}

#define stringPushBack(string, x)                                              \
        _Generic((x),                                                          \
            char: (stringPushBack_c),                                          \
            char *: (stringPushBack_cstr),                                     \
            const char *: (stringPushBack_cstr),                               \
            String *: (stringPushBack_string),                                 \
            const String *: (stringPushBack_string))(string, x)

static inline int stringPushBack_string(String *const string,
                                        const String *const source) {
        if (string == NULL || source == NULL) {
                return 1;
        }

        if (string->size + source->size == string->cap) {
                size_t sizeFac = (string->size + source->size) / string->size;
                if (sizeFac < STRING_GROWTH_FAC
                        ? growString(string, STRING_GROWTH_FAC)
                        : growString(string, sizeFac)) {
                        return 1;
                }
        }

        memcpy(string->cstr + string->size, source->cstr, source->size);
        string->size += source->size;
        string->cstr[string->size] = '\0';
        return 0;
}

static inline int stringPushBack_cstr(String *const string, const char *s) {
        if (string == NULL) {
                return 1;
        }

        size_t len = strlen(s);
        if (string->size + len >= string->cap) {
                if (growString(string, STRING_GROWTH_FAC)) {
                        return 1;
                }
        }

        memcpy(string->cstr + string->size, s, len);
        string->size += len;
        string->cstr[string->size] = '\0';
        return 0;
}

static inline int stringPushBack_c(String *const string, const char c) {
        if (string == NULL) {
                return 1;
        }

        if (string->size + 1 >= string->cap) {
                if (growString(string, STRING_GROWTH_FAC)) {
                        return 1;
                }
        }

        string->cstr[string->size++] = c;
        string->cstr[string->size] = '\0';
        return 0;
}

void destroyString(String *string);

#endif // string_H
