#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  if (argc != 2) {
    printf("Usage: ./recover FILE\n");
    return 1;
  }

  FILE *card = fopen(argv[1], "r");
  // FILE *out = fopen("out.txt", "w");

  if (card == NULL) {
    printf("failed to open file\n");
    return 1;
  }

  // create buffer to store data
  uint8_t buffer[512];

  int jpg = 1;
  int imgCount = 0;
  char filename[8];
  FILE *img = NULL;

  // repeat intil end of card
  while (fread(buffer, 1, 512, card)) {
    // read 512 bytes in to a buffer done in the while loop

    // if start of new jpg,  0xff 0xd8 0xff 0xe1-f
    if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0)) 
    {
      jpg = 0;
    }

    if (jpg == 0){

      if (imgCount != 0) {
        fclose(img);
      }

      sprintf(filename, "%03i.jpg", imgCount);

      imgCount++;

      img = fopen(filename, "w");
      fwrite(buffer, 1, 512, img);
      jpg = 1;
    }
    else if (imgCount != 0)
    {
      fwrite(buffer, 1, 512, img);
    
    }
  }


  fclose(img);
  fclose(card);
  // printf("File(s) succesfully recovered\n");
  return 0;
}

    // printf("Found a jpeg: ");
    // imgCount++;
    // sprintf(filename, "%03i.jpg", imgCount);
    //
    // FILE *img = fopen(filename, "w");
    // fwrite(filename, 1, 512, img);
    // // printf("%s\n", filename);
    // printf("%i\n", imgCount);

    // if first jpg
    // ...
    // else
    // ...
    // else
    // if already found jpg
    // ...

    // fread(buffer, 1, 512, card);
  // }

  // 0xff 0xd8 0xff 0xe1-f

  // for (int i = 0; i < 512; i++) {
  //   // printf("%02x\n", buffer[i]);
  //   fprintf(out, "%04i\n", buffer[i]);
  // }
  // printf("\n");
