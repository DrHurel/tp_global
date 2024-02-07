#include "../../include/image_pm.h"
#include "../../include/lib.h"
#include <stdio.h>

int blur_2(int width, int height, OCTET *ImgIn, OCTET *ImgOut) {

  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      int mean = 0;
      int count = 0;
      for (int x = -1; x <= 1; x++) {
        for (int y = -1; y <= 1; y++) {
          int target = (i + x) * width + j + y;
          if (target > 0 && target < width * height) {
            mean += (int)ImgIn[(i + x) * width + j + y];
            count += 1;
          }
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