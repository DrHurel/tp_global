#include "../../include/image_pm.h"
#include "../../include/lib.h"
#include <stdio.h>

int blur_1(int width, int height, OCTET *ImgIn, OCTET *ImgOut) {

  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      int mean = 0;
      int count = 0;
      for (int x = -1; x <= 1; x++) {
        if (i + x >= 0 && i + x < height) {
          mean += (int)ImgIn[(i + x) * width + j];
          count += 1;
        }
        if (j + x >= 0 && j + x < width && x != 0) {
          mean += (int)ImgIn[(i)*width + j + x];
          count += 1;
        }
      }
      if (count != 0) {
        mean = mean / count;
        ImgOut[i * width + j] = mean;
      } else {
        ImgOut[i * width + j] = ImgIn[i * width + j];
      }
    }
  }
  printf("%d %d\n", width, height);

  return 0;
}