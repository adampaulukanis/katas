/* Game of Life */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <assert.h>

#define WIDTH           100
#define HEIGHT          100
#define SPEED             2
#define STEPS          1000

typedef enum {
    DEAD,
    ALIVE,
} State;

typedef struct {
    State state;
} Cell;

Cell grid[HEIGHT][WIDTH] = {0};
Cell new_grid[HEIGHT][WIDTH] = {0};

State test[2][9] = {
    {DEAD, ALIVE, ALIVE, DEAD, DEAD, DEAD, DEAD, DEAD, DEAD},
    {ALIVE, ALIVE, ALIVE, ALIVE, ALIVE, ALIVE, ALIVE, ALIVE, ALIVE},
};

State gol[2][9] = {
    {DEAD, DEAD, DEAD, ALIVE, DEAD, DEAD, DEAD, DEAD, DEAD},
    {DEAD, DEAD, ALIVE, ALIVE, DEAD, DEAD, DEAD, DEAD, DEAD},
};

void init_grid()
{
    for (size_t y = 0; y < HEIGHT; ++y) {
        for (size_t x = 0; x < WIDTH; ++x) {
            grid[y][x].state = DEAD;
            if (rand() % 2 == 0) {
                grid[y][x].state = ALIVE;
            }
        }
    }
}

void init_glider(size_t offsetX, size_t offsetY)
{
    grid[offsetY - 1][offsetX + 1].state = ALIVE;
    grid[offsetY    ][offsetX - 1].state = ALIVE;
    grid[offsetY    ][offsetX + 1].state = ALIVE;
    grid[offsetY + 1][offsetX + 1].state = ALIVE;
    grid[offsetY + 1][offsetX    ].state = ALIVE;
}

void init_spaceship(size_t offsetX, size_t offsetY)
{
    grid[offsetY - 1][offsetX - 1].state = ALIVE;
    grid[offsetY - 1][offsetX + 2].state = ALIVE;
    grid[offsetY    ][offsetX - 2].state = ALIVE;
    grid[offsetY + 1][offsetX - 2].state = ALIVE;
    grid[offsetY + 1][offsetX + 2].state = ALIVE;
    grid[offsetY + 2][offsetX + 1].state = ALIVE;
    grid[offsetY + 2][offsetX + 0].state = ALIVE;
    grid[offsetY + 2][offsetX - 1].state = ALIVE;
    grid[offsetY + 2][offsetX - 2].state = ALIVE;
}

void init_f(size_t offsetX, size_t offsetY)
{
    grid[offsetY - 1][offsetX + 0].state = ALIVE;
    grid[offsetY - 1][offsetX + 1].state = ALIVE;
    grid[offsetY    ][offsetX - 1].state = ALIVE;
    grid[offsetY    ][offsetX    ].state = ALIVE;
    grid[offsetY + 1][offsetX    ].state = ALIVE;
}

void print_grid()
{
    printf("\n");
    for (size_t y = 0; y < HEIGHT; ++y) {
        for (size_t x = 0; x < WIDTH; ++x) {
            if (grid[y][x].state == ALIVE) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

size_t count_neighbours(size_t x, size_t y) {
    size_t sum = 0;
    if (x < 1 || x >= WIDTH - 1 || y < 1 || y >= HEIGHT - 1) {
        assert(sum == 0);
        return sum; /* 0 */
    }

    assert(sum == 0);

    sum += grid[y - 1][x - 1].state;
    sum += grid[y - 1][x    ].state;
    sum += grid[y - 1][x + 1].state;
    sum += grid[y    ][x - 1].state;
    sum += grid[y    ][x + 1].state;
    sum += grid[y + 1][x - 1].state;
    sum += grid[y + 1][x    ].state;
    sum += grid[y + 1][x + 1].state;

    return sum;
}

void next_gen()
{
    for (size_t y = 0; y < HEIGHT; ++y) {
        for (size_t x = 0; x < WIDTH; ++x) {
            State state = grid[y][x].state;
            size_t neighbours_allive = count_neighbours(x, y);
            //printf("(%zu) ", neighbours_allive);
            new_grid[y][x].state = (State)gol[state][neighbours_allive];
        }
        //printf("\n");
    }

    for (size_t y = 0; y < HEIGHT; ++y) {
        for (size_t x = 0; x < WIDTH; ++x) {
            grid[y][x] = new_grid[y][x];
        }
    }
}

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    srand(time(NULL));
    system("clear");
    //init_grid();
    init_glider(4, 3);
    init_glider(10, 8);
    init_f(50, 50);
    init_spaceship(WIDTH - 10, HEIGHT / 2);
    print_grid(); 

    for (size_t i = 0; i < STEPS; ++i) {
        if (i % 47 == 0) {
            init_spaceship(WIDTH - 10, HEIGHT - 50);
        }
        //system("clear");
        next_gen();
        print_grid(); 
        printf("%zu / %d\n", i, STEPS);
        //usleep(SPEED * 100000);
    }

    return EXIT_SUCCESS;
}
