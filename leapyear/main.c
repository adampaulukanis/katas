#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
        exit(1);

    int year = atoi(argv[1]);
    int flag = 0;

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        flag = 2;
    else
        flag = 1;

    printf("flag is %d\n and year %d\n", flag, year);
    switch (flag) {
        case 2:
            printf("%d is a leap year\n", year);
            break;
        case 1:
            printf("%d is not a leap year\n", year);
            break;
        default:
            printf("should NOT happen");
    }

    return 0;
}
