#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

int getLine(char line[], int maxline);

int main(int argc, char *argv[])
{
    FILE *fp;
    const char *filename = "../famous-person.txt";
    char line[MAXLINE];

    if ((fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "%s: can't open %s\n", argv[0], filename);
        exit(1);
    }

    int len = getLine(line, MAXLINE);
    printf("%d: %s\n", len, line);

    return 0;
}

/* getline: read a line into line, return length */
int getLine(char line[], int maxline)
{
    int c, i;

    for (i=0; i<maxline-1 && (c=getchar())!=EOF && c!='\n'; ++i) {
        line[i] = c;
    }

    if (c=='\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';
    return i;
}
