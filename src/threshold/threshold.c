#include "../../include/image_pm.h"
#include "../../include/lib.h"

static int intCompare(const void *p1, const void *p2) {
  int int_a = *((int *)p1);
  int int_b = *((int *)p2);

  if (int_a == int_b)
    return 0;
  else if (int_a < int_b)
    return -1;
  else
    return 1;
}

int threshold_pgm(OCTET *ImgIn, int S, int nH, int nW) {

  for (int i = 0; i < nH; i++)
    for (int j = 0; j < nW; j++) {
      if (ImgIn[i * nW + j] < S)
        ImgIn[i * nW + j] = 255;
      else
        ImgIn[i * nW + j] = 0;
    }

  return 1;
}
