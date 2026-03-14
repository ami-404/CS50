#include "helpers.h"
// #include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]) {

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {

      // printf("N: %i R: %i G: %i B: %i\n",i, image[i][j].rgbtRed,
      // image[i][j].rgbtGreen, image[i][j].rgbtBlue); printf("%i\n",
      // image[i][j].rgbtRed );
      int average = (int)round(
          (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) /
          3);
      // printf("%i\n", average);

      image[i][j].rgbtRed = average;
      image[i][j].rgbtGreen = average;
      image[i][j].rgbtBlue = average;
    }
  }
  return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width]) {

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {

      int originalRed = image[i][j].rgbtRed;
      int originalGreen = image[i][j].rgbtGreen;
      int originalBlue = image[i][j].rgbtBlue;

      int sepiaRed = round(.393 * originalRed + .769 * originalGreen +
                           .189 * originalBlue);
      int sepiaGreen = round(.349 * originalRed + .686 * originalGreen +
                             .168 * originalBlue);
      int sepiaBlue = round(.272 * originalRed + .534 * originalGreen +
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
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      copy[i][j] = image[i][j];
    }
  }
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {

      image[i][j].rgbtRed = copy[i][width - j].rgbtRed;
      image[i][j].rgbtGreen = copy[i][width - j].rgbtGreen;
      image[i][j].rgbtBlue = copy[i][width - j].rgbtBlue;
    }
  }
  return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]) {

  RGBTRIPLE copy[height][width];
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      copy[i][j] = image[i][j];
    }
  }

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      int averageRed = (copy[i][j].rgbtRed + copy[i][j - 1].rgbtRed +
                        copy[i][j + 1].rgbtRed + copy[i - 1][j + 1].rgbtRed +
                        copy[i - 1][j - 1].rgbtRed + copy[i - 1][j].rgbtRed +
                        copy[i + 1][j + 1].rgbtRed +
                        copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed) /
                       9;

      int averageGreen =
          (copy[i][j].rgbtGreen + copy[i][j - 1].rgbtGreen +
           copy[i][j + 1].rgbtGreen + copy[i - 1][j + 1].rgbtGreen +
           copy[i - 1][j - 1].rgbtGreen + copy[i - 1][j].rgbtGreen +
           copy[i + 1][j + 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen +
           copy[i + 1][j].rgbtGreen) /
          9;

      int averageBlue =
          (copy[i][j].rgbtBlue + copy[i][j - 1].rgbtBlue +
           copy[i][j + 1].rgbtBlue + copy[i - 1][j + 1].rgbtBlue +
           copy[i - 1][j - 1].rgbtBlue + copy[i - 1][j].rgbtBlue +
           copy[i + 1][j + 1].rgbtBlue + copy[i + 1][j - 1].rgbtBlue +
           copy[i + 1][j].rgbtBlue) /
          9;

      image[i][j].rgbtRed = averageRed;
      image[i][j].rgbtGreen = averageGreen;
      image[i][j].rgbtBlue = averageBlue;
    }
  }

  return;
}
