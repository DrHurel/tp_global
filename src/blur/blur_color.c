#include "../../include/image_pm.h"
#include "../../include/lib.h"
#include "../../include/utils.h"
#include <stdio.h>

int setPixel(OCTET *ImgOut, int i, int j, int r, int g, int b, int width) {
  ImgOut[i * 3 + j * width * 3] = r;
  ImgOut[i * 3 + j * width * 3 + 1] = g;
  ImgOut[i * 3 + j * width * 3 + 2] = b;
  return 0;
}

int blur_color(int radius, int width, int height, OCTET *ImgIn, OCTET *ImgOut) {

  for (int i = 0; i < width; i++) {

    for (int j = 0; j < height; j++) {

      int meanR = 0;
      int meanG = 0;
      int meanB = 0;
      int count = 0;
      for (int x = -radius; x <= radius; x++) {
        for (int y = -radius; y <= radius; y++) {
          if (i + x > 0 && y + j > 0 && x + i < height && y + j < width) {

            RGB_Pixel temp = getPixel(ImgIn, i + x, j + y, width);
            meanB += temp.b;
            meanG += temp.g;
            meanR += temp.r;
            count++;
          }
        }
      }
      if (count != 0) {
        meanB /= count;
        meanG /= count;
        meanR /= count;

        setPixel(ImgOut, i, j, meanR, meanG, meanB, width);
      } else {
        printf("Error: count is 0\n");
        setPixel(ImgOut, i, j, 0, 0, 0, width);
      }
    }
  }
  printf("%d %d\n", width, height);

  return 0;
}
