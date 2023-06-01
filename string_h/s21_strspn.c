#include "s21_string.h"

s21_size_t s21_strspn(const char *str1, const char *str2) {
    s21_size_t counter = 0;
    for (int i = 0; i < s21_strlen(str1); i++) {
        int was = 0;
        for (int j = 0; j < s21_strlen(str2); j++) {
            if (str1[i] == str2[j]) {
                counter++;
                was = 1;
                break;
            }
        }
        if (!was)
            break;
    }
    return counter;
}