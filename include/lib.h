
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

int threshold_pgm(OCTET *ImgIn, int S, int nH, int nW, int nTaille);
typedef enum { CIRCULAR, RECTANGULAR } BrushShape;

typedef struct {
  int radius;
  BrushShape shape;
  int nuance;

} Brush;

int erode(OCTET *ImgIn, int nH, int nW, int nTaille);

int dilate(OCTET *ImgIn, int nH, int nW, int nTaille);
#endif // THRESHOLD_H