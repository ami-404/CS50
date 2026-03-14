#include "helpers.h"
// #include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]) {

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {

      // printf("N: %i R: %i G: %i B: %i\n",i, image[i][j].rgbtRed, image[i][j].rgbtGreen, image[i][j].rgbtBlue);
      // printf("%i\n", image[i][j].rgbtRed );
      int average = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3;
      // printf("%i\n", average);

      image[i][j].rgbtRed = average;
      image[i][j].rgbtGreen = average;
      image[i][j].rgbtBlue = average;

    }
  }
  return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width]) { return; }

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]) { return; }

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]) { return; }
