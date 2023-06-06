#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
    char *res = S21_NULL;
    int len1 = s21_strlen(haystack);
    int len2 = s21_strlen(needle);
    if (len1 >= len2) {
        for (int i = 0; i <= len1 - len2; i++) {
            int found = 1;
            for (int k = 0; k < len2; k++) {
                if (haystack[i+k] != needle[k]) {
                    found = 0;
                    break;
                }
            }
            if (found) {
                res = (char *)haystack + i;
                break;
            }
        }
    }
    return res;
}