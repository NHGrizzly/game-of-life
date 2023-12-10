#ifndef CONWAY_H
#define CONWAY_H

#include <stdbool.h>

#define CONWAY_HEIGHT 8
#define CONWAY_WIDTH 64 

/* grid must be at least 5 by 5*/
#define CONWAY_GLIDER(grid) grid[1][2] = true;\
    grid[2][3] = true;\
    grid[3][1] = true;\
    grid[3][2] = true;\
    grid[3][3] = true;

bool conway_print_grid(bool grid[CONWAY_HEIGHT][CONWAY_WIDTH],
        const unsigned int grid_height, const unsigned int grid_width);

#endif // CONWAY_H
