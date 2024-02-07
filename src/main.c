#include "../include/lib.h"
#include <stdio.h>
#include <stdlib.h>

int copy(OCTET *ImgIn, OCTET *ImgOut, int nH, int nW, int nTaille) {
  for (int i = 0; i < nTaille; i++) {
    ImgOut[i] = ImgIn[i];
  }
  return 1;
}

int main(int argc, char **argv) {
  printf("Hello World!\n");

  UI_CONFIG config = Load(argc, argv);

  OCTET *ImgIn, *ImgOut;
  int nH, nW, nTaille;

  lire_nb_lignes_colonnes_image_pgm(config.target, &nH, &nW);
  nTaille = nH * nW;

  allocation_tableau(ImgIn, OCTET, nTaille);
  allocation_tableau(ImgOut, OCTET, nTaille);
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
    if (argc < 5) {
      printf("usage : %s [target_file] [output_file] [job] [threshold]\n",
             argv[0]);
      exit(1);
    }
    printf("HIGHLIGHT\n");
    threshold_pgm(ImgIn, atoi(argv[4]), nH, nW, nTaille);
    erode(ImgIn, ImgOut, nH, nW, nTaille);
    copy(ImgOut, ImgIn, nH, nW, nTaille);
    erode(ImgIn, ImgOut, nH, nW, nTaille);
    copy(ImgOut, ImgIn, nH, nW, nTaille);
    erode(ImgIn, ImgOut, nH, nW, nTaille);
    copy(ImgOut, ImgIn, nH, nW, nTaille);
    dilate(ImgIn, ImgOut, nH, nW, nTaille);
    copy(ImgOut, ImgIn, nH, nW, nTaille);
    dilate(ImgIn, ImgOut, nH, nW, nTaille);
    copy(ImgOut, ImgIn, nH, nW, nTaille);
    dilate(ImgIn, ImgOut, nH, nW, nTaille);
    copy(ImgOut, ImgIn, nH, nW, nTaille);
    erode(ImgIn, ImgOut, nH, nW, nTaille);
    // copy(ImgOut, ImgIn, nH, nW, nTaille);
    // erode(ImgIn, ImgOut, nH, nW, nTaille);
    break;
  case SELECT:
    if (argc < 5) {
      printf("usage : %s [target_file] [output_file] [job] [threshold]\n",
             argv[0]);
      exit(1);
    }
    printf("SELECT\n");
    threshold_pgm(ImgIn, atoi(argv[4]), nH, nW, nTaille);
    erode(ImgIn, ImgOut, nH, nW, nTaille);
    copy(ImgIn, ImgOut, nH, nW, nTaille);
    erode(ImgIn, ImgOut, nH, nW, nTaille);
    copy(ImgIn, ImgOut, nH, nW, nTaille);
    dilate(ImgIn, ImgOut, nH, nW, nTaille);
    copy(ImgIn, ImgOut, nH, nW, nTaille);
    dilate(ImgIn, ImgOut, nH, nW, nTaille);
    copy(ImgIn, ImgOut, nH, nW, nTaille);
    selection(ImgIn, ImgOut, nH, nW, nTaille);
    break;
  case ERODE:
    if (argc < 5) {
      printf("usage : %s [target_file] [output_file] [job] [threshold]\n",
             argv[0]);
      exit(1);
    }
    printf("ERODE\n");
    threshold_pgm(ImgIn, atoi(argv[4]), nH, nW, nTaille);
    erode(ImgIn, ImgOut, nH, nW, nTaille);
    break;
  case DILATE:
    if (argc < 5) {
      printf("usage : %s [target_file] [output_file] [job] [threshold]\n",
             argv[0]);
      exit(1);
    }
    printf("DILATE\n");
    threshold_pgm(ImgIn, atoi(argv[4]), nH, nW, nTaille);
    dilate(ImgIn, ImgOut, nH, nW, nTaille);
    break;
  case INVERSE:
    negate(nTaille, ImgIn, ImgOut);
    break;
  case BLUR:
    blur_1(nW - 1, nH, ImgIn, ImgOut);
    break;
  case BLUR_2:
    blur_2(nW - 1, nH, ImgIn, ImgOut);
    break;
  default:
    printf("NO JOB CORRESPONDING\n");
    exit(1);
    break;
  }

  ecrire_image_pgm(config.output, ImgOut, nH, nW);

  return 0;
}
