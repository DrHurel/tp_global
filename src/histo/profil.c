// test_couleur.cpp : Seuille une image en niveau de gris

#include "../../include/image_pm.h"
#include "../../include/lib.h"
#include <stdio.h>
#include <stdlib.h>

int get_profil(PROFIL_MODE mode, OCTET *ImgIn, int *nbOccurence, int n,
               int index, int width) {

  if (mode != LINE && mode != COLUMN) {
    printf("mode : 0 -> ligne\nmode : 1 -> column \n");

    exit(1);
  }

  if (n < index || index < 0) {
    exit(0);
  }

  allocation_tableau(nbOccurence, int, n);

  switch (mode) {
  case LINE:

    for (int j = 0; j < n; j++) {
      nbOccurence[j] = ImgIn[index * width + j];
    }

    break;

  case COLUMN:

    for (int i = 0; i < n; i++) {
      nbOccurence[i] = ImgIn[i * width + index];
    }

    break;
  default:
    exit(EXIT_FAILURE);
  }

  return 1;
}
