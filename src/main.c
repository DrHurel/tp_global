#include "../include/lib.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  printf("Hello World!\n");

  UI_CONFIG config = Load(argc, argv);

  switch (config.job) {
  case THRESHOLD:
    threshold_pgm(config, argc, argv);
    break;
  case HIGHLIGHT:
    break;
  case SELECT:
    break;
  case ERODE:
    break;
  case DILATE:
    break;
  default:
    printf("NO JOB CORRESPONDING\n");
    exit(1);
    break;
  }

  return 0;
}
