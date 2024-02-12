// test_couleur.cpp : Seuille une image en niveau de gris

#include "../../include/image_pm.h"
#include "../../include/lib.h"
#include <stdio.h>

int get_profil(PROFIL_MODE mode, OCTET *ImgIn, int *nbOccurence, int n,
               int index) {
  char cNomImgLue[250], cNomImgEcrite[250];

  if (mode < 0 || mode > 2) {
    printf("mode : 1 -> ligne\nmode : 2 -> column \n");

    exit(1);
  }

  switch (mode) {
  case 1 /* constant-expression */:
    if (n < index || index < 0) {
      exit(0);
    }
    allocation_tableau(nbOccurence, int, n);

    for (int j = 0; j < n; j++) {
      nbOccurence[j] = ImgIn[index * n + j];
    }

    ecrire_histo(cNomImgEcrite, nbOccurence, n);
    break;

  default:
    if (n < index || index < 0) {
      exit(0);
    }

    allocation_tableau(nbOccurence, int, n);

    for (int i = 0; i < n; i++) {
      nbOccurence[i] = ImgIn[i * n + index];
    }
    ecrire_histo(cNomImgEcrite, nbOccurence, n);
    break;
  }

  return 1;
}
