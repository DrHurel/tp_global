#include "../../include/image_pm.h"
#include "../../include/utils.h"

RGB_Pixel getPixel(OCTET *Img, int x, int y, int width) {
  return (RGB_Pixel){Img[3 * (x + y * width)], Img[3 * (x + y * width) + 1],
                     Img[3 * (x + y * width) + 2]};
}