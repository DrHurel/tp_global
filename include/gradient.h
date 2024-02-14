
#ifndef GRADIENT_H
#define GRADIENT_H

#include "image_pm.h"

int threshold_gradient(OCTET *ImgIn, OCTET *ImgOut, int width, int height,
                       int threshold);
int map_gradient(OCTET *ImgIn, OCTET *ImgOut, int width, int height);
int threshold_gradient_hys(OCTET *ImgIn, OCTET *ImgOut, int width, int height,
                           int threshold_high, int threshold_down, int radius);
#endif // GRADIENT_H
