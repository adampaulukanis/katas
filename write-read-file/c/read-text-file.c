#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num;
    FILE *fp;
    char *filename = "test.txt";

    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Error: could not open this file: %s.\n", filename);
        exit(1);
    }

    fread(&num, sizeof(num), 1, fp);
    printf("%d\n", num);

    return 0;
}
