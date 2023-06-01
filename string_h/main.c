#include "s21_string.h"
#include <stdio.h>

int main () {
    int err = 0;
    char *str1 = "012345 At the time of Stephen Wolfram's release announcement for Mathematica 13, there were 2,259 functions contributed as Resource Functions.";
    char *str2 = "At the time of 6Stephen Wolfram's release announcement for Mathematica 13, there were 2,259 functions contributed as Resource Functions.";
    char *str3 = "0123456789";
    printf("str1 len = %d\n", s21_strlen(str1));
    printf("str2 len = %d\n", s21_strlen(str2));
    printf("strspn : %d\n", s21_strspn(str1, str3));
    printf("strcspn : %d\n", s21_strcspn(str2, str3));
    printf("str1 + str3 : %d\n", s21_strcat(str1, str3));
    printf("str1 + str3 5 syms : %d\n", s21_strncat(str1, str3, 5));

    return err;
}