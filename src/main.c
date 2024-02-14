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
  int occurence[256];
  int nH, nW, nTaille;

  if (config.job != BLUR_COLOR) {
    lire_nb_lignes_colonnes_image_pgm(config.target, &nH, &nW);
    nTaille = nH * nW;

    allocation_tableau(ImgIn, OCTET, nTaille);
    allocation_tableau(ImgOut, OCTET, nTaille);
    lire_image_pgm(config.target, ImgIn, nTaille);
  } else {
    lire_nb_lignes_colonnes_image_ppm(config.target, &nH, &nW);
    nTaille = nH * nW;

    allocation_tableau(ImgIn, OCTET, nTaille * 3);
    allocation_tableau(ImgOut, OCTET, nTaille * 3);
    lire_image_ppm(config.target, ImgIn, nTaille);
  }

  switch (config.job) {
  case THRESHOLD:
    if (argc < 5) {
      printf("usage : %s [target_file] [output_file] [job] [threshold]\n",
             argv[0]);
      exit(1);
    }
    printf("THRESHOLD\n");
    threshold_pgm(ImgIn, atoi(argv[4]), nH, nW);
    break;
  case HIGHLIGHT:
    if (argc < 5) {
      printf("usage : %s [target_file] [output_file] [job] [threshold]\n",
             argv[0]);
      exit(1);
    }
    printf("HIGHLIGHT\n");
    threshold_pgm(ImgIn, atoi(argv[4]), nH, nW);
    erode(ImgIn, ImgOut, nH, nW);
    copy(ImgOut, ImgIn, nH, nW, nTaille);
    erode(ImgIn, ImgOut, nH, nW);
    copy(ImgOut, ImgIn, nH, nW, nTaille);
    erode(ImgIn, ImgOut, nH, nW);
    copy(ImgOut, ImgIn, nH, nW, nTaille);
    dilate(ImgIn, ImgOut, nH, nW);
    copy(ImgOut, ImgIn, nH, nW, nTaille);
    dilate(ImgIn, ImgOut, nH, nW);
    copy(ImgOut, ImgIn, nH, nW, nTaille);
    dilate(ImgIn, ImgOut, nH, nW);
    copy(ImgOut, ImgIn, nH, nW, nTaille);
    erode(ImgIn, ImgOut, nH, nW);
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
    threshold_pgm(ImgIn, atoi(argv[4]), nH, nW);
    erode(ImgIn, ImgOut, nH, nW);
    copy(ImgIn, ImgOut, nH, nW, nTaille);
    erode(ImgIn, ImgOut, nH, nW);
    copy(ImgIn, ImgOut, nH, nW, nTaille);
    dilate(ImgIn, ImgOut, nH, nW);
    copy(ImgIn, ImgOut, nH, nW, nTaille);
    dilate(ImgIn, ImgOut, nH, nW);
    copy(ImgIn, ImgOut, nH, nW, nTaille);
    selection(ImgIn, ImgOut, nH, nW);
    break;
  case ERODE:
    if (argc < 5) {
      printf("usage : %s [target_file] [output_file] [job] [threshold]\n",
             argv[0]);
      exit(1);
    }
    printf("ERODE\n");
    threshold_pgm(ImgIn, atoi(argv[4]), nH, nW);
    erode(ImgIn, ImgOut, nH, nW);
    break;
  case DILATE:
    if (argc < 5) {
      printf("usage : %s [target_file] [output_file] [job] [threshold]\n",
             argv[0]);
      exit(1);
    }
    printf("DILATE\n");
    threshold_pgm(ImgIn, atoi(argv[4]), nH, nW);
    dilate(ImgIn, ImgOut, nH, nW);
    break;
  case INVERSE:
    if (argc < 4) {
      printf("usage : %s [target_file] [output_file] [job]\n", argv[0]);
      exit(1);
    }
    printf("INVERTE\n");
    negate(nTaille, ImgIn, ImgOut);

    break;
  case BLUR:
    if (argc < 5) {
      printf("usage : %s [target_file] [output_file] [job] [radius]\n",
             argv[0]);
      exit(1);
    }
    printf("BLUR\n");
    blur_1(atoi(argv[4]), nW, nH, ImgIn, ImgOut);
    break;
  case BLUR_2:
    if (argc < 5) {
      printf("usage : %s [target_file] [output_file] [job] [radius\n", argv[0]);
      exit(1);
    }
    printf("BLUR\n");
    blur_2(atoi(argv[4]), nW, nH, ImgIn, ImgOut);
    break;
  case BLUR_COLOR:
    if (argc < 5) {
      printf("usage : %s [target_file] [output_file] [job] [radius]\n",
             argv[0]);
      exit(1);
    }
    printf("BLUR\n");
    blur_color(atoi(argv[4]), nW, nH, ImgIn, ImgOut);
    break;
  case DISTRIB:
    get_distrib(occurence, ImgIn, nW, nH);
    ecrire_histo(config.output, occurence, 256);
    return 0;
  case PROFIL:
    if (argc < 6) {
      printf("usage : %s [target_file] [output_file] [job] [mode] [n]\n",
             argv[0]);
      exit(1);
    }
    int mode = atoi(argv[4]);
    if (mode == LINE) {
      get_profil(mode, ImgIn, occurence, nW, atoi(argv[5]), nW);
      ecrire_histo(config.output, occurence, nW);
    } else {
      get_profil(mode, ImgIn, occurence, nH, atoi(argv[5]), nW);
      ecrire_histo(config.output, occurence, nH);
    }

    return 0;
  default:
    printf("NO JOB CORRESPONDING\n");
    exit(1);
    break;
  }

  if (config.job != BLUR_COLOR) {
    ecrire_image_pgm(config.output, ImgOut, nH, nW);
  } else {
    ecrire_image_ppm(config.output, ImgOut, nH, nW);
  }
  free(ImgIn);
  free(ImgOut);
  return 0;
}
