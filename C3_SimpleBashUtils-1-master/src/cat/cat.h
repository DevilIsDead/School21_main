#ifndef SRC_CAT_CAT_H_
#define SRC_CAT_CAT_H_

typedef struct {
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
  int lastFile;
  char *err;
  char **files;
} options;

int printFile(char *filePath, options *config);
int parsConfig(int argc, char *argv[], options *config);

#endif  // SRC_CAT_CAT_H_