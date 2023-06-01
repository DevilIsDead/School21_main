#include "s21_string.h"
#include <stdio.h>

int main () {
    int err = 0;
    char *str = "123456789";
    int len = s21_strlen(str);
    printf("%d", len);


    return err;
}