#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

typedef struct 
{
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

int parsConfig (int argc, char *argv[], options *config);
void printVars (options config);
int grep (char *filepath, options config);
void freeMem (options *config);

int main (int argc, char *argv[]) {
    options config = {0};
    
    if (parsConfig(argc, argv, &config)){
      if (config.err == 0) {
        printf("cat21: enter file path!\n");
      } else {
        printf("cat21: unknown option : %s\n", config.err);
      }
    } else { 
        printVars(config);
        for (int i = 0; i < config.pathNum; i++) {
          grep(config.files[i], config);
          printf("\n");
        }
    }
    freeMem(&config);
    return 0;
}

void freeMem (options *config) {
  free(config->files);
  free(config->template);
}



int grep (char *filepath, options config) {
  int err = 0;
  int vFlag = 0;
  int check = 0;
  size_t len = 0;
  regex_t regex;
  char *line = NULL;
  FILE *file = fopen(filepath, "rt");
  if (file == NULL) {
    printf("cat21: %s: No such file or directory\n", filepath);
  } else {
    while (!feof(file))
    {
      getline(&line, &len, file);
      config.lineCount++; 

      
      for (int k = 0; k < config.templateNum; k++) {
        if (config.i) {
          regcomp(&regex, config.template[k], REG_ICASE);
        } else {
          regcomp(&regex, config.template[k], 0);
        }
        check = regexec(&regex, line, 0, NULL, 0);
        regfree(&regex);
        if (!config.v && !check) {
          config.goodLineCount++;
          if (!config.c && !config.l) {
            if (!config.h) printf("%s:", filepath);
            if (config.n) printf("%6d  ", config.lineCount);
            printf("%s", line);
            k = config.templateNum;
          }
        } else if (config.v && check) {


          for (int c = 0; c < config.templateNum; c++) {
            if (config.i) {
              regcomp(&regex, config.template[c], REG_ICASE);
            } else {
              regcomp(&regex, config.template[c], 0);
            }

            if(regexec(&regex, line, 0, NULL, 0)) {
              vFlag++;
            } else {
              
              c = config.templateNum;
            }
            regfree(&regex);
          }


          if (vFlag == config.templateNum) {
            config.goodLineCount++;
            if (!config.c && !config.l) {
              if (!config.h) printf("%s:", filepath);
              if (config.n) printf("%6d  ", config.lineCount);
              printf("%s", line);
            }
          }
        }
      }
      vFlag = 0;
    }
    if (config.c) printf("%d\n", config.goodLineCount);
    if (config.l) printf("%s", filepath);
  }
  free(line);
  fclose(file);
  return err;
}

void printVars (options config) {
  printf("e i v c l n\n");
  printf("%d %d %d %d %d %d\n", config.e, config.i, config.v, config.c, config.l, config.n);
  printf("templates : ");
  for (int j = 0; j < config.templateNum; j++) {
    printf("%s ", config.template[j]);
  }
  printf("\nfiles : ");
  for (int i = 0; i < config.pathNum; i++) {
    printf("%s ", config.files[i]);
  }
  printf("\n");
}

int parsConfig (int argc, char *argv[], options *config) {
  int tmp = 0;
  config->template = malloc(sizeof(char*));
  config->files = malloc(sizeof(char*));
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
      if (!strcmp(argv[i], "-e")) {
        config->e = 1;
        config->template = realloc(config->template, sizeof(char*) * (config->templateNum + 1));
        config->template[config->templateNum] = argv[i + 1];
        config->templateNum++;
        config->argsNum++;
        i++;
      } else if (!strcmp(argv[i], "-i")) {
        config->i = 1;
        config->argsNum++;
      } else if (!strcmp(argv[i], "-v")) {
        config->v = 1;
        config->argsNum++;
      } else if (!strcmp(argv[i], "-c")) {
        config->c = 1;
        config->argsNum++;
      } else if (!strcmp(argv[i], "-l")) {
        config->l = 1;
        config->argsNum++;
      } else if (!strcmp(argv[i], "-h")) {
        config->h = 1;
        config->argsNum++;
      } else if (!strcmp(argv[i], "-n")) {
        config->n = 1;
        config->argsNum++;
      } else {
        config->err = argv[i];
        tmp = 1;
      }
    } else {
        if (config->templateNum == 0 && !config->e) {
          config->template = realloc(config->template, sizeof(char*) * (config->templateNum + 1));
          config->template[config->templateNum] = argv[i];
          config->templateNum++;
        } else {
          config->files = realloc(config->files, sizeof(char*) * (config->pathNum + 1));
          config->files[config->pathNum] = argv[i];
          config->pathNum++;
        }
    }
  }
  return tmp;
}
