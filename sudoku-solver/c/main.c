#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

const size_t WIDTH = 9;

size_t grid[WIDTH * WIDTH] = { 0 };

void print_grid(void)
{
    for (size_t y = 0; y < WIDTH; ++y) {
        for (size_t x = 0; x < WIDTH; ++x) {
            printf("%zu", grid[y * WIDTH + x]);
        }
        printf("\n");
    }
}

bool possible(size_t y,size_t x,size_t n)
{
    // Check the row
    for (size_t i = 0; i < WIDTH; ++i) {
        if (grid[y * WIDTH + i] == n) return false;
    }

    // Check the column
    for (size_t i = 0; i < WIDTH; ++i) {
        if (grid[i * WIDTH + x] == n) return false;
    }
    // Check the box
    size_t x0 = floor(x / 3) * 3;
    size_t y0 = floor(y / 3) * 3;
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            if (grid[(y0 + i) * WIDTH + (x0 + j)] == n) return false;
        }
    }

    return true;
}

int main(void)
{
    /*
     * init 1..9
     */
    for (size_t y = 0; y < WIDTH; ++y) {
        for (size_t x = 0; x < WIDTH; ++x) {
            grid[y * WIDTH + x] = 0;
        }
    }

    for (size_t i = 0; i < WIDTH; ++i) {
        grid[0 * WIDTH + i] = i + 1;
    }
    grid[0 * WIDTH + 5] = 0;

    print_grid();

    for (size_t i = 0; i < WIDTH; ++i) {
        printf("%zu: %d\n", 1 + i, possible(0, 5, 1 + i));
    }

    return EXIT_SUCCESS;
}
