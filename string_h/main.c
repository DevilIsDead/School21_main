#include "s21_string.h"
#include <stdio.h>
#include <string.h>

int main () {
    int err = 0;
    char *str1 = "012345 At the time of Stephen Wolfram's release announcement for Mathematica 13, there were 2,259 functions contributed as Resource Functions.";
    char *str2 = "At the time of 6Stephen Wolfram's release announcement for Mathematica 13, there were 2,259 functions contributed as Resource Functions.";
    char *str3 = "0123456789";
    char str4[50] = {'\0'};
    printf("str1 len = %ld\n", s21_strlen(str1));
    printf("str2 len = %ld\n", s21_strlen(str2));
    printf("str3 len = %ld\n", s21_strlen(str3));
    printf("strspn : %ld\n", s21_strspn(str1, str3));
    printf("strcspn : %ld\n", s21_strcspn(str2, str3));
    char *res = s21_strcat(str4, str3);
    printf("str1 + str3 : %s\n", res);
    res = s21_strncat(str4, str3, 5);
    printf("str1 + str3 5 syms : %s\n", res);

    return err;
}