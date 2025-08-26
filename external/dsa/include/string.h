#ifndef string_H
#define string_H

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

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

static inline int pushBackString(String *string, char c) {
        if (string == NULL) {
                return 1;
        }
        string->str[string->size++] = c;
        assert(0);

        return 0;
}

#endif // string_H
