
#ifndef LIB_H
#define LIB_H

#include "image_pm.h"
typedef enum {
  THRESHOLD,
  HIGHLIGHT,
  SELECT,
  ERODE,
  DILATE,
  BLUR,
  BLUR_2,
  INVERSE,
  BLUR_COLOR,
  DISTRIB,
  PROFIL
} APP_JOB;

typedef enum { LINE, COLUMN } PROFIL_MODE;

typedef struct {
  APP_JOB job;
  char *output;
  char *target;
} UI_CONFIG;

UI_CONFIG Load(const int argc, char **argv);

int threshold_pgm(OCTET *ImgIn, int S, int nH, int nW);
typedef enum { CIRCULAR, RECTANGULAR } BrushShape;

typedef struct {
  int radius;
  BrushShape shape;
  int nuance;

} Brush;

int negate(int n, OCTET *ImgIn, OCTET *ImgOut);

int erode(OCTET *ImgIn, OCTET *ImgOut, int nH, int nW);

int dilate(OCTET *ImgIn, OCTET *ImgOut, int nH, int nW);
int blur_1(int radius, int width, int height, OCTET *ImgIn, OCTET *ImgOut);
int blur_2(int radius, int width, int height, OCTET *ImgIn, OCTET *ImgOut);
int blur_color(int radius, int width, int height, OCTET *ImgIn, OCTET *ImgOut);

int selection(OCTET *ImgIn, OCTET *ImgOut, int nH, int nW);

int ecrire_histo(char *nom_image, int *occurence, int n);
int get_distrib(int nbOccurence[256], OCTET *ImgIn, int nW, int nH);
int get_profil(PROFIL_MODE mode, OCTET *ImgIn, int *nbOccurence, int n,
               int index, int width);
#endif // THRESHOLD_H
