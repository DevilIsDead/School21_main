#include "grep.h"

int main (int argc, char *argv[]) {
    options config = {0};
    if (parsConfig(argc, argv, &config)){
      if (config.err == 0) {
        printf("grep21: enter file path!\n");
      } else {
        printf("grep21: unknown option : %s\n", config.err);
      }
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
    if (config.err == NULL) freeMem(&config);
    return 0;
}
