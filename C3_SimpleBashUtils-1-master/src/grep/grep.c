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

int parsConfig (int argc, char *argv[], options *config);

int main (int argc, char *argv[]) {
    options config = {0};
    
    if (parsConfig(argc, argv, &config)){
      if (config.err == 0) {
        printf("cat21: enter file path!\n");
      } else {
        printf("cat21: unknown option : %s\n", config.err);
    } else { 
    
    }    
    return 0;
}

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
