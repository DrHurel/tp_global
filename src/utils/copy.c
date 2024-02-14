#include "../../include/lib.h"

int copy(OCTET *ImgIn, OCTET *ImgOut, int nTaille) {
  for (int i = 0; i < nTaille; i++) {
    ImgOut[i] = ImgIn[i];
  }
  return 1;
}