#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
    char *res = S21_NULL;
    for (int i = 0; i < s21_strlen(str1); i++) {
        for (int j = 0; j < s21_strlen(str2); j++) {
            if (str1[i] == str2[j]) {
                res = (char*)str1[i];
                break;
            }
        }
        if (res) {
            break;
        }
    }
    return res;
}
