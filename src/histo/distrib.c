// test_couleur.cpp : Seuille une image en niveau de gris

#include "../../include/image_pm.h"
#include "../../include/lib.h"
#include <stdio.h>

int ecrire_histo(char *nom_image, int *occurence, int n) {
  FILE *f_image;
  if ((f_image = fopen(nom_image, "wb")) == NULL) {
    printf("\nPas d'acces en ecriture sur l'image %s \n", nom_image);
    exit(EXIT_FAILURE);
  } else {

    for (int i = 0; i < n; i++) {
      printf("%d %d\n", i, occurence[i]);           /*ecriture entete*/
      fprintf(f_image, "%d %d\n", i, occurence[i]); /*ecriture entete*/
    }

    fclose(f_image);
  }

  return 1;
}

int get_distrib(int nbOccurence[256], OCTET *ImgIn, int nW, int nH) {

  for (int i = 0; i < 256; i++) {
    nbOccurence[i] = 0;
  }

  for (int i = 0; i < nH; i++) {
    for (int j = 0; j < nW; j++) {
      nbOccurence[ImgIn[i * nW + j]]++;
    }
  }

  return 1;
}
