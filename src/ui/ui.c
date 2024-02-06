#include "../../include/lib.h"
#include <stdio.h>
#include <stdlib.h>

UI_CONFIG Load(const int argc, char **argv) {
  UI_CONFIG *res;

  if (argc < 4) {
    printf("usage : %s [target_file] [output_file] [job]\n", argv[0]);
    exit(1);
  }

  res->job = atoi(argv[3]);

  sscanf(argv[1], "%s", res->target);
  sscanf(argv[2], "%s", res->output);
  return *res;
}