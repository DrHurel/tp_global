
#ifndef LIB_H
#define LIB_H

#include "image_pm.h"
typedef enum { THRESHOLD, HIGHLIGHT, SELECT, ERODE, DILATE } APP_JOB;

typedef struct {
  APP_JOB job;
  char *output;
  char *target;
} UI_CONFIG;

UI_CONFIG Load(const int argc, char **argv);

OCTET *threshold_pgm(const UI_CONFIG config, const int argc, char **argv);

typedef enum { CIRCULAR, RECTANGULAR } BrushShape;

typedef struct {
  int radius;
  BrushShape shape;
  int nuance;

} Brush;

int delate(Brush *brush, int pixels[], const int width, const int height);

int erode(Brush *brush, int pixels[], int width, int height);

#endif // THRESHOLD_H