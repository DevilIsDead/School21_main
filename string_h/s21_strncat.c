#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
    char *ptr = dest;
    s21_size_t i = 0;
    while (*ptr) {
        ptr++;
    }
    while (*src && i < n) {
        i++;
        *(ptr++) = *(src++);
    }
    *ptr = '\0';
    return dest;
}