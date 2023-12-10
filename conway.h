#ifndef CONWAY_H
#define CONWAY_H

#include <stdbool.h>

#define CONWAY_HEIGHT 8
#define CONWAY_WIDTH 64 

bool conway_print_grid(bool grid[CONWAY_HEIGHT][CONWAY_WIDTH],
        const unsigned int grid_height, const unsigned int grid_width);

#endif // CONWAY_H
