#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
    char *res = S21_NULL;
    int len1 = s21_strlen(haystack);
    int len2 = s21_strlen(needle);
    if (len1 >= len2) {
        for (int i = 0; i <= len1 - len2; i++) {
            int found = 0;
            for (int j = i, k = 0; needle[k]; k++, j++) {
                if (haystack[j] == needle[k]) {
                    found = 1;
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