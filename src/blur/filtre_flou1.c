#include "../../include/image_pm.h"
#include "../../include/lib.h"
#include <stdio.h>

int blur_1(int radius, int width, int height, OCTET *ImgIn, OCTET *ImgOut) {
  int mean = 0;
  int count = 0;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      mean = 0;
      count = 0;
      for (int x = -radius; x <= radius; x++) {
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
      }
      if (count == 0) {
        printf("%d", ImgIn[i * width + j]);
        ImgOut[i * width + j] = ImgIn[i * width + j];
      }
    }
  }
  printf("%d %d\n", width, height);

  return 0;
}