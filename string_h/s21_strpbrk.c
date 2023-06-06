#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
    char *res = S21_NULL;
    int len1 = s21_strlen(str1);
    int len2 = s21_strlen(str2);
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            if (str1[i] == str2[j]) {
                res = &str1[i];
                break;
            }
        }
        if (res) {
            break;
        }
    }
    return res;
}
