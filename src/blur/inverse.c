#include "../../include/image_pm.h"
#include "../../include/lib.h"

int negate(int n, OCTET *ImgIn, OCTET *ImgOut) {

  for (int i = 0; i < n; i++) {
    ImgOut[i] = 255 - ImgIn[i];
  }

  return 0;
}