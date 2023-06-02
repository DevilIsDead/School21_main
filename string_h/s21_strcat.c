#include "s21_string.h"

char *s21_strcat(char *dest, const char *src) {
    char *ptr = dest;
    while (*ptr) {
        ptr++;
    }
    while (*src) {
        *(ptr++) = *(src++);
    }
    *ptr = '\0';
    return dest;
}