#ifndef string_H
#define string_H
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define STRING_GROWTH_FAC 2

typedef struct {
        size_t size;
        size_t cap;
        char *str;
} String;

int createString(String *string, size_t prealloc) {
        if (string == NULL) {
                return 1;
        }
        string->size = 0;
        string->cap = prealloc;
        string->str = malloc(sizeof(char) * string->cap);
        if (string->str == NULL) {
                return 1;
        }

        return 0;
}

int growString(String *string, size_t growthFactor) {
        if (string == NULL) {
                return 1;
        }
        if (growthFactor < 2) {
                return 1;
        }

        size_t newCap = string->cap * growthFactor;
        char *newStr = malloc(newCap);
        if (newStr == NULL) {
                return 1;
        }

        // copy data
        assert(newCap > string->size);
        memcpy(newStr, string->str, string->size);

        free(string->str);
        string->str = newStr;
        string->cap = newCap;

        return 0;
}

static inline char *const stringIndex(String *const string, size_t i) {
        if (string == NULL) {
                return NULL;
        }

        return (string->str + i);
}

#define stringPushBack(string, x) (_Generic((x),\
        char: stringPushBack_c(string, x),\
        const char: stringPushBack_c(string, x),\
        char*: stringPushBack_cstr(string, x),\
        const char*: stringPushBack_cstr(string, x),\
        String*: stringPushBack_string(string, x),\
        const String*: stringPushBack_string(string, x))

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

        for (size_t i = 0; i < source->size; ++i) {
                char *d = string->str + i + string->size;
                char *s = source->str + i;
                if (d == NULL || s == NULL) {
                        return 1;
                }
                *d = *s;
        }

        return 0;
}

static inline int stringPushBack_cstr(String *const string, const char *s) {
        if (string == NULL) {
                return 1;
        }

        size_t len = strlen(s);
        if (string->size + len == string->cap) {
                if (growString(string, STRING_GROWTH_FAC)) {
                        return 1;
                }
        }

        for (size_t i = 0; i < len; ++i) {
                char *d = stringIndex(string, i);
                if (d == NULL) {
                        return 1;
                }
                *d = s[i];
        }

        return 0;
}

static inline int stringPushBack_c(String *const string, const char c) {
        if (string == NULL) {
                return 1;
        }

        if (string->size + 1 == string->cap) {
                if (growString(string, STRING_GROWTH_FAC)) {
                        return 1;
                }
        }

        string->str[string->size++] = c;

        return 0;
}

void destroyString(String *string) {
        if (string && string->str) {
                free(string->str);
                string->str = NULL;
                string->size = 0;
                string->cap = 0;
        }
}

#endif // string_H
