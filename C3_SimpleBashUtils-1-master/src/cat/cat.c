#include "cat.h"

int main (int argc, char *argv[]) {
  options config = {0};
  config.strCount = 1;
  config.strCountB = 1;
    if (parsConfig(argc, argv, &config)){
      if (config.err == 0) {
        printf("cat21: enter file path!\n");
      } else {
        printf("cat21: unknown option : %s\n", config.err);
    }
    } else {
      for (int i = 1; i < argc; i++ ) {
        if (argv[i][0] != '-') {
            if (printFile(argv[i], &config)) {
            printf("cat21: %s: No such file or directory\n", argv[i]);
            } else {
            continue;
            }
        } else {
            continue;
        }
      }
    }
  return 0;
}