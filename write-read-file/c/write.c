#include <stdio.h>

int main(void)
{
    char *filename = "test.txt";
    FILE *fp;

    if ((fp = fopen(filename, "w")) == NULL) {
        printf("Something went wrong with the file %s\n", filename);
        return 1;
    }

    int buf = 107107; // in hex 00 01 a2 63
    fwrite(&buf, sizeof(buf), 1, fp);

    fclose(fp);

    return 0;
}
