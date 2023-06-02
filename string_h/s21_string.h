#ifndef S21_STRING_H_
#define S21_STRING_H_

typedef unsigned long s21_size_t;
#define S21_NULL ((void *)0)

s21_size_t s21_strlen(const char *str);
s21_size_t s21_strspn(const char *str1, const char *str2);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, s21_size_t n);

#endif // S21_STRING_H_