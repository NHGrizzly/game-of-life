#ifndef CONWAY_H
#define CONWAY_H

#include <stddef.h>
#include <stdbool.h>

#define CONWAY_HEIGHT 8
#define CONWAY_WIDTH 64 

/* grid must be at least 5 by 5*/
#define CONWAY_GLIDER(grid, row, col) grid[row+1][col+2] = true;\
    grid[row+2][col+3] = true;\
    grid[row+3][col+1] = true;\
    grid[row+3][col+2] = true;\
    grid[row+3][col+3] = true;
typedef struct conway
{
    bool grid[256][256];
    const unsigned int height;
    const unsigned int width;
    size_t time_iteration;
} conway;

void conway_print_grid(const conway * c);

unsigned int conway_count_neighbors(conway *restrict c, const unsigned int row, const unsigned int column);

void set_cell(conway *restrict c, const unsigned int row, const unsigned int column, const bool alive);

#endif // CONWAY_H
