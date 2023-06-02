#include "s21_string.h"
#include <stdio.h>
#include <string.h>

int main () {
    int err = 0;
    char str1[143] = "012345 At the time of Stephen Wolfram's release announcement for Mathematica 13, there were 2,259 functions contributed as Resource Functions.";
    char str2[149] = "At the time of 6Stephen for Wolfram's release announcement for Mathematica 13, there were 2,259 for  forfunctions contributed as Resource Functions.";
    char str3[44] = "0123456789|0123456789|0123456789|0123456789";
    char str4[100] = {'\0'};
    char *delim = " ";
    printf("str1 len = %ld\n", s21_strlen(str1));
    printf("str2 len = %ld\n", s21_strlen(str2));
    printf("str3 len = %ld\n", s21_strlen(str3));
    printf("strspn : %ld\n", s21_strspn(str1, str3));
    printf("strcspn : %ld\n", s21_strcspn(str2, str3));
    char *res = s21_strcat(str4, str3);
    printf("str1 + str3 : %s\n", res);
    res = s21_strncat(str4, str3, 5);
    printf("str1 + str3 5 syms : %s\n", res);
    res = strtok(str2, delim);
    while (res != NULL) {
        printf("strtok str3 : %s\n", res);
        res = strtok(NULL, delim);
    }
    return err;
}