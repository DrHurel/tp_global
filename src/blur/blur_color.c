#include "../../include/image_pm.h"
#include "../../include/lib.h"
#include "../../include/utils.h"
#include <stdio.h>

int blur_color(int radius, int width, int height, OCTET *ImgIn, OCTET *ImgOut) {

  for (int i = 0; i < width; i++) {

    for (int j = 0; j < height; j++) {

      int mean = 0;
      int count = 0;
      for (int x = -radius; x <= radius; x++) {
        for (int y = -radius; y <= radius; y++) {
          if (i + x > 0 && y + j > 0) {
          }
          RGB_Pixel temp = getPixel(ImgIn, x, y, width);
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