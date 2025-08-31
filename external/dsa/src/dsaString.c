#include "../include/dsaString.h"

int createString(String *string, size_t prealloc) {
        if (string == NULL) {
                return 1;
        }
        string->size = 0;
        string->cap = prealloc;
        string->cstr = malloc(sizeof(char) * (string->cap + 1)); // for \0
        if (string->cstr == NULL) {
                return 1;
        }

        string->cstr[0] = '\0';
        return 0;
}

int growString(String *string, const size_t growthFactor) {
        if (string == NULL) {
                return 1;
        }
        if (growthFactor < 2) {
                return 1;
        }

        size_t newCap = string->cap * growthFactor;
        char *newCstr = malloc((sizeof(char)) * (newCap + 1)); // for \0
        if (newCstr == NULL) {
                return 1;
        }

        // copy data
        strncpy(newCstr, string->cstr, string->size);
        string->cstr[0] = '\0';

        free(string->cstr);
        string->cstr = newCstr;
        string->cap = newCap;

        return 0;
}

void destroyString(String *string) {
        if (string && string->cstr) {
                free(string->cstr);
                string->cstr = NULL;
                string->size = 0;
                string->cap = 0;
        }
}
