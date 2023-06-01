#include "grep.h"

int main(int argc, char *argv[]) {

    options config;
    config.e = 0;
    config.firstTempl = 0;
    config.i = 0;
    config.v = 0;
    config.c = 0;
    config.l = 0;
    config.n = 0;
    config.h = 0;
    config.template = NULL;
    config.files = NULL;
    config.templateNum = 0;
    config.argsNum = 0;
    config.pathNum = 0;
    config.lineCount = 0;
    config.goodLineCount = 0;
    config.err = NULL;

    int res = parsConfig(argc, argv, &config);

  if (res == 1) {
      printf("grep21: unknown option : %s\n", config.err);
  } else if (res == 2) {
      printf("grep21: wrong usage of flag -e!\n");
  } else if (res == 3){
      printf("grep21: file path is not provided!\n");
  } else {
    if (config.e) {
      for (int i = 0; i < config.pathNum; i++) {
        grep(config.files[i], config);
      }
    } else {
      for (int i = 1; i < config.pathNum; i++) {
        grep(config.files[i], config);
      }
    }
  }
  freeMem(&config);
  return 0;
}

void freeMem(options *config) {
    if (config->files != NULL) {
      free(config->files);
    }
    if (config->template != NULL) {
      free(config->template);
    }
}


int grep(char *filepath, options config) {
  int err = 0;
  int vFlag = 0;
  int check = 0;
  size_t len = 0;
  regex_t regex;
  char *line = NULL;
  FILE *file = fopen(filepath, "rt");
  if (file == NULL) {
    config.err = filepath;
    printf("grep21: %s: No such file or directory\n", filepath);
  } else {
    while (!feof(file)) {
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
          k = config.templateNum;
          if (!config.c && !config.l) {
            if ((config.pathNum - config.firstTempl) >= 2) printf("%s:", filepath);
            if (config.n) printf("%d:", config.lineCount);
                printf("%s", line);
            if (line[strlen(line) - 1] != '\n') {
                printf("\n");
            }
          }
        } else if (config.v && check) {
          vFlag++;
          if (vFlag == config.templateNum) {
            config.goodLineCount++;
            k = config.templateNum;
            vFlag = 0;
            if (!config.c && !config.l && !feof(file)) {
              if ((config.pathNum - config.firstTempl) >= 2) printf("%s:", filepath);
              if (config.n) printf("%d:", config.lineCount);
              printf("%s", line);
              if (line[strlen(line) - 1] != '\n') {
                printf("\n");
              }
            }
          }
        } else if (config.v && !check) {
          vFlag = 0;
        }
      }
    }
    if ((!config.v && config.l && config.goodLineCount > 0) || (config.v && config.l && config.goodLineCount == config.lineCount)) {
        printf("%s\n", filepath);
    } 
    if (config.c && !config.l) printf("%s:%d\n", filepath, config.goodLineCount);
    config.lineCount = 0;
    config.goodLineCount = 0;
    free(line);
    fclose(file);
  }
  return err;
}

int parsConfig(int argc, char *argv[], options *config) {
  int res = 0;
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
      if (!strcmp(argv[i], "-e")) {
        config->e = 1;
        config->argsNum++;
        if (i < argc - 1) {
          config->templateNum++;
          config->template = (char **) realloc(config->template, sizeof(char *) * (config->templateNum));
          config->template[config->templateNum - 1] = (char *) argv[i + 1];
          i++;
        } else {
          res = 2;
        }
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
        res = 1;
      }
    } else {
      config->pathNum++;
      config->files = (char **) realloc(config->files, sizeof(char *) * (config->pathNum));
      config->files[config->pathNum - 1] = argv[i]; 
    }
  }

  if (config->pathNum == 0 && res == 0){
    res = 3;
  }

  if (!config->templateNum) {
    config->template = (char **) malloc(sizeof(char *));
    config->template[0] = config->files[0];
    config->templateNum = 1;
    config->firstTempl = 1;
  }

  return res;
}
