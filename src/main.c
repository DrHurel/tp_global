#include "../include/lib.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  printf("Hello World!\n");

  UI_CONFIG config = Load(argc, argv);

  OCTET *ImgIn;
  int nH, nW, nTaille;

  lire_nb_lignes_colonnes_image_pgm(config.target, &nH, &nW);
  nTaille = nH * nW;

  allocation_tableau(ImgIn, OCTET, nTaille);
  lire_image_pgm(config.target, ImgIn, nTaille);

  switch (config.job) {
  case THRESHOLD:
    if (argc < 5) {
      printf("usage : %s [target_file] [output_file] [job] [threshold]\n",
             argv[0]);
      exit(1);
    }
    printf("THRESHOLD\n");
    threshold_pgm(ImgIn, atoi(argv[4]), nH, nW, nTaille);
    break;
  case HIGHLIGHT:
    break;
  case SELECT:
    threshold_pgm(ImgIn, atoi(argv[4]), nH, nW, nTaille);
    erode(ImgIn, nH, nW, nTaille);
    dilate(ImgIn, nH, nW, nTaille);
    dilate(ImgIn, nH, nW, nTaille);

    break;
  case ERODE:
    if (argc < 5) {
      printf("usage : %s [target_file] [output_file] [job] [threshold]\n",
             argv[0]);
      exit(1);
    }
    printf("ERODE\n");
    threshold_pgm(ImgIn, atoi(argv[4]), nH, nW, nTaille);
    erode(ImgIn, nH, nW, nTaille);
    break;
  case DILATE:
    if (argc < 5) {
      printf("usage : %s [target_file] [output_file] [job] [threshold]\n",
             argv[0]);
      exit(1);
    }
    printf("DILATE\n");
    threshold_pgm(ImgIn, atoi(argv[4]), nH, nW, nTaille);
    dilate(ImgIn, nH, nW, nTaille);
    break;
  default:
    printf("NO JOB CORRESPONDING\n");
    exit(1);
    break;
  }

  ecrire_image_pgm(config.output, ImgIn, nH, nW);

  return 0;
}
