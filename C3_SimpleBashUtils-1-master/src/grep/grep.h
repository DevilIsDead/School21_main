#ifndef SRC_GREP_GREP_H_
#define SRC_GREP_GREP_H_

#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  char **template;
  char **files;
  int templateNum;
  int argsNum;
  int pathNum;
  int lineCount;
  int goodLineCount;
  char *err;
} options;

int parsConfig(int argc, char *argv[], options *config);
int grep(char *filepath, options config);
void freeMem(options *config);

#endif  // SRC_GREP_GREP_H_
