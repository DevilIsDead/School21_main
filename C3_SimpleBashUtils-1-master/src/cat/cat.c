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
  int flag;
} options;

int printFile(char *filePath, options *config);
int scanConfig (int argc, char *argv[], options *config);

int main (int argc, char *argv[]) {
  options config = {0};
  if (argc <= 4){
    if (scanConfig(argc, argv, &config)){
      printf("Wrong flags\n");
    } else {
      if (printFile(argv[argc-1], &config)) {
        printf("No such file or directory\n");
      }
    }
  } else {
    printf("Wrong promt\n");
  }
  return 0;
}

int scanConfig (int argc, char *argv[], options *config) {
  int tmp = 0;
  for (int i = 1; i <= argc - 2; i++) {
    printf("argv[%d] = %s\n", i, argv[i]);
    if (!strcmp(argv[i], "-b")) {
      config->b = 1;
    } else if (!strcmp(argv[i], "-e")) {
      config->e = 1;
      config->v = 1;
    } else if (!strcmp(argv[i], "-n")) {
      config->n = 1;
    } else if (!strcmp(argv[i], "-s")) {
      config->s = 1;
    } else if (!strcmp(argv[i], "-t")) {
      config->t = 1;
      config->v = 1;
    } else if (!strcmp(argv[i], "-v")) {
      config->v = 1;
    } else {
      tmp = 1;
    }
  }
  return tmp;
}
 
int printFile(char *filePath, options *config) {
  int tmp = 0;
  FILE *file = fopen(filePath, "rt");
  char ch;
  if (file == NULL) {
    tmp = 1;
  } else {
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
  }
  fclose(file);
  return tmp;
}