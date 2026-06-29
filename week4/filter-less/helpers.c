#include "helpers.h"
// #include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]) {
  int average = 0;

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {

      average = (int)round(
          (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) /
          3.0);
      image[i][j].rgbtRed = average;
      image[i][j].rgbtGreen = average;
      image[i][j].rgbtBlue = average;
    }
  }
  return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width]) {

  int sepiaRed = 0;
  int sepiaGreen = 0;
  int sepiaBlue = 0;

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {

      int originalRed = image[i][j].rgbtRed;
      int originalGreen = image[i][j].rgbtGreen;
      int originalBlue = image[i][j].rgbtBlue;

      sepiaRed = (int)round(.393 * originalRed + .769 * originalGreen +
                            .189 * originalBlue);
      sepiaGreen = (int)round(.349 * originalRed + .686 * originalGreen +
                              .168 * originalBlue);
      sepiaBlue = (int)round(.272 * originalRed + .534 * originalGreen +
                             .131 * originalBlue);

      if (sepiaRed > 255)
        sepiaRed = 255;
      if (sepiaGreen > 255)
        sepiaGreen = 255;

      if (sepiaBlue > 255)
        sepiaBlue = 255;

      image[i][j].rgbtRed = sepiaRed;
      image[i][j].rgbtGreen = sepiaGreen;
      image[i][j].rgbtBlue = sepiaBlue;
    }
  }
  return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]) {

  RGBTRIPLE copy[height][width];

  int ourWidth = 0;

  if (width % 2 == 0) {
    ourWidth = width / 2;
  } else {
    ourWidth = width / 2 + 1;
  }

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < ourWidth; j++) {

      copy[i][j] = image[i][j];

      image[i][j] = image[i][width - 1 - j];
      image[i][width - 1 - j] = copy[i][j];
    }
  }
  return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]) {

  RGBTRIPLE copy[height][width];
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {

      float tempRed = 0, tempGreen = 0, tempBlue = 0, pixelCount = 0;

      for (int local_i = i - 1; local_i <= i + 1; local_i++) {
        for (int local_j = j - 1; local_j <= j + 1; local_j++) {
          if (local_i >= 0 && local_i < height && local_j >= 0 &&
              local_j < width) {
            tempRed += image[local_i][local_j].rgbtRed;
            tempGreen += image[local_i][local_j].rgbtGreen;
            tempBlue += image[local_i][local_j].rgbtBlue;

            pixelCount++;
          }
        }
      }

      copy[i][j].rgbtRed = round(tempRed / pixelCount);
      copy[i][j].rgbtGreen = round(tempGreen / pixelCount);
      copy[i][j].rgbtBlue = round(tempBlue / pixelCount);
    }
  }

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      image[i][j] = copy[i][j];
    }
  }
  return;
}
