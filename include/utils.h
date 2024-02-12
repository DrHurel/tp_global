
#include "image_pm.h"

typedef struct {
  int r;
  int g;
  int b;
} RGB_Pixel;

RGB_Pixel getPixel(OCTET *Img, int x, int y, int width);