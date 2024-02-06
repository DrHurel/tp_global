#include "../../include/highlight.h"
#include "../../include/image_pm.h"
#include "../../include/lib.h"

#include <stdbool.h>

// only support rectengular shape
int dilate(Brush *brush, int pixels[], const int width, const int height) {
  int index;

  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) { // for each pixels
      for (int x = -brush->radius; x < brush->radius; x++) {

        for (int y = -brush->radius; y < brush->radius;
             y++) { // for each pixel in the radius
          index = (i + x) * width + (j + y);

          if (index < 0 && index < width * height) { // check if the pixel exist
            continue;
          } else {
            pixels[i * width + j] =
                pixels[index] == brush->nuance ? brush->nuance : pixels[index];
          }
        }
      }
    }
  }

  return 0;
}

int erode(Brush *brush, int pixels[], int width, int height) {
  bool alter = true;
  int index;

  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) { // for each pixels
      for (int x = -brush->radius; x < brush->radius; x++) {

        for (int y = -brush->radius; y < brush->radius; y++) {
          index = (i + x) * width + (j + y);

          if (index < 0 || (x == 0 && y == 0)) {
            continue;
          } else {
            if (pixels[index] != brush->nuance) {
              alter = false;
            }
          }
        }
      }
      pixels[i * width + j] =
          alter ? brush->nuance : pixels[index]; // erode if is to alter
    }
  }

  return 0;
}

int ErodeImagePGM(UI_CONFIG config, Brush *brush) {
  OCTET *ImgIn, *ImgOut;
  int nH, nW, nTaille, n, temp, *Seuil;

  lire_nb_lignes_colonnes_image_pgm(config.target, &nH, &nW);
  nTaille = nH * nW;
  allocation_tableau(ImgIn, OCTET, nTaille);
  lire_image_pgm(config.target, ImgIn, nTaille);
  allocation_tableau(ImgOut, OCTET, nTaille);

  return 0;
}

int alter(Brush *brush, bool dilate, int width, int height, int pixels[]) {

  for (int i = 0; i < width; ++) {
    for (int j = 0; j < height; j++) {
    }
  }
}