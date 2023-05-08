#ifndef SRC_CAT_CAT_H_
#define SRC_CAT_CAT_H_

#include <stdio.h>
#include <string.h>

typedef struct 
{
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
  int argsNum;
  int pathNum;
  int strCount;
  int strCountB;
  int flag;
  char *err;
} options;

int printFile(char *filePath, options *config);
int parsConfig (int argc, char *argv[], options *config);

int parsConfig (int argc, char *argv[], options *config) {
  int tmp = 0;
  int argCount = 0;
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
      if (!strcmp(argv[i], "-b") || !strcmp(argv[i], "--number-nonblank")) {
        if (!config->n)config->b = 1;
        argCount++;
      } else if (!strcmp(argv[i], "-e")) {
        config->e = 1;
        config->v = 1;
        argCount++;
      } else if (!strcmp(argv[i], "-E")) {
        config->e = 1;
        argCount++;
      } else if (!strcmp(argv[i], "-n") || !strcmp(argv[i], "--number")) {
        config->n = 1;
        config->b = 0;
        argCount++;
      } else if (!strcmp(argv[i], "-s") || !strcmp(argv[i], "--squeeze-blank")) {
        config->s = 1;
        argCount++;
      } else if (!strcmp(argv[i], "-t")) {
        config->t = 1;
        config->v = 1;
        argCount++;
      } else if (!strcmp(argv[i], "-T")) {
        config->t = 1;
        argCount++;
      } else if (!strcmp(argv[i], "-v")) {
        config->v = 1;
        argCount++;
      } else {
        config->err = argv[i];
        tmp = 1;
      }
    } else {
        continue;
    }
  }
  config->argsNum = argCount;
  config->pathNum = argc - argCount - 1;
  if (config->pathNum < 1) {
    tmp = 1;
  }
  return tmp;
}
 
int printFile(char *filePath, options *config) {
  int err = 0;
  int firstSym = 1;
  int emptyLine = 0;
  FILE *file = fopen(filePath, "rt");
  char ch;
  char chh;
  if (file == NULL) {
    err = 1;
  } else {
    while ((ch = getc(file)) != EOF) {
      chh = getc(file);
      ungetc(chh, file);
      if (config->b && firstSym == 1 && ch == '\n') {
        printf("      \t");
      } else if (firstSym == 1 && config->n) {
        printf("%6d\t", config->strCount++);
      } else if (firstSym == 1 && config->b) {
        printf("%6d\t", config->strCountB++);
      }

      if (config->e && ch == '\n') { 
        printf("$");
      } 
      if (config->t && ch == '\t') { 
        printf("^I");
      } 
      if (config->v && !(ch >= 32 && ch < 127) && ch != '\n' && ch != '\t') {
          if (ch == 127) {
            printf("^");
            ch -= 64;
          } else if (ch < 32 && ch >= 0) {
            printf("^");
            ch += 64;
          }
      } 
      
      if (config->s && ch == '\n' && (chh == '\n') && emptyLine == 0) { 
        emptyLine = 1;
        if (firstSym != 1) printf("\n");
        if ((config->n) && firstSym != 1) printf("%6d\t", config->strCount++);
        if ((config->b) && firstSym != 1) printf("      \t");
      } else if (config->s && ch == '\n' && chh != '\n' && chh != EOF && emptyLine == 1) {
        if (firstSym != 1) printf("\n");
        emptyLine = 0;
      } else if (config->s && ch == '\n' && emptyLine == 1) {
        continue;
      } else {
        putchar(ch);
        emptyLine = 0;
      }

      if (config->n && ch == '\n' && chh != EOF && emptyLine == 0) { 
        printf("%6d\t", config->strCount++); 
      }
      if (config->b && config->s && ch == '\n' && chh != EOF && emptyLine == 0){
        printf("%6d\t", config->strCountB++);
      } else if (config->b && !config->s && ch == '\n' && chh != '\n' && chh != EOF && emptyLine == 0) {
        printf("%6d\t", config->strCountB++);
      } else if (config->b && ch == '\n' && chh == '\n' && emptyLine == 0) {
        printf("      \t");
      } 
      firstSym = 0;
    }
  }
  fclose(file);
  return err;
}

#endif  // SRC_CAT_CAT_H_