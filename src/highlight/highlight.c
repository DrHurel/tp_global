#include "../../include/highlight.h"
#include "../../include/image_pm.h"
#include "../../include/lib.h"

#include <stdbool.h>

int erode(OCTET *ImgIn, OCTET *ImgOut, int nH, int nW, int nTaille) {

  // erode the image
  for (int i = 0; i < nH; i++) {
    for (int j = 0; j < nW; j++) {
      if (ImgIn[i * nW + j] == 0) { // if the pixel is black
        int max = 0;
        for (int x = -1; x <= 1; x++) {
          for (int y = -1; y <= 1; y++) {
            if (i + x >= 0 && i + x < nH && j + y >= 0 && j + y < nW) {
              max = ImgIn[(i + x) * nW + j + y] > max
                        ? ImgIn[(i + x) * nW + j + y]
                        : max;
            }
          }
        }
        ImgOut[i * nW + j] = max; // set the pixel to the max value
      } else {
        ImgOut[i * nW + j] = 255;
      }
    }
  }

  return 1;
}

int dilate(OCTET *ImgIn, OCTET *ImgOut, int nH, int nW, int nTaille) {

  // dilate the image
  for (int i = 0; i < nH; i++) {
    for (int j = 0; j < nW; j++) {
      if (ImgIn[i * nW + j] == 0) { // if the pixel is black
        int min = 255;
        for (int x = -1; x <= 1; x++) {
          for (int y = -1; y <= 1; y++) {
            if (i + x >= 0 && i + x < nH && j + y >= 0 && j + y < nW) {
              min = ImgIn[(i + x) * nW + j + y] < min
                        ? ImgIn[(i + x) * nW + j + y]
                        : min;
            }
          }
        }
        ImgOut[i * nW + j] = min; // set the pixel to the min value
      } else {
        ImgOut[i * nW + j] = 255;
      }
    }
  }

  return 1;
}

int selection(OCTET *ImgIn, OCTET *ImgOut, int nH, int nW, int nTaille) {
  for (int i = 0; i < nH; i++) {
    for (int j = 0; j < nW; j++) {
      if (ImgIn[i * nW + j] == 0) { // if the pixel is black
        // if all the pixels around are black, set the pixel to white
        bool allBlack = true;
        for (int x = -1; x <= 1; x++) {
          for (int y = -1; y <= 1; y++) {
            if (i + x >= 0 && i + x < nH && j + y >= 0 && j + y < nW) {
              if (ImgIn[(i + x) * nW + j + y] != 0) {
                allBlack = false;
              }
            }
          }
        }
        if (allBlack) {
          ImgOut[i * nW + j] = 255;
        }
      }
    }
  }
  return 1;
}