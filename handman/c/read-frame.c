#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 6     /* remember to add +1 for \n */
#define HEIGHT 7
#define FRAMES 7

int main(void)
{
    FILE *fp;
    static char frames[FRAMES][(WIDTH+1)*HEIGHT];
    char *filename = "frames.txt";
    size_t i;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error could not open this file: %s\n", filename);
        exit(1);
    }

    for (i=0; i<FRAMES; ++i) {
        fread(&frames[i], (WIDTH+1)*HEIGHT, 1, fp);
    }

    printf("%s\n", (char *)frames[4]);

    fclose(fp);

    return 0;
}
