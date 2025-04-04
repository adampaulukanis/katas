#include <stdio.h>
#include <string.h>

#define WIDTH 6
#define HEIGHT 7
#define FRAMES 7

static char frames[][WIDTH*HEIGHT] = {
    " *---* |   |     |     |     |     |------",
    " *---* |   | O   |     |     |     |------",
    " *---* |   | O   | |   |     |     |------",
    " *---* |   | O   |/|   |     |     |------",
    " *---* |   | O   |/|\\  |     |     |------",
    " *---* |   | O   |/|\\  |/    |     |------",
    " *---* |   | O   |/|\\  |/ \\  | END |------"
};

void printFrame(size_t frameNo)
{
    size_t x, y;
    for (y=0;y<HEIGHT; ++y) {
        for (x=0; x<WIDTH; ++x) {
            printf("%c", frames[frameNo][x+WIDTH*y]);
        }
        printf("\n");
    }
}

int main(void)
{
    size_t f;

    for (f=0; f<FRAMES; ++f) {
        printf("---frame#%lu----\n", f);
        printFrame(f);
    }

    return 0;
}
