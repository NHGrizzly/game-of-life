#ifndef CONWAY_H
#define CONWAY_H

#include <stddef.h>
#include <stdbool.h>

typedef struct conway
{
    bool grid[256][256];
    const unsigned int height;
    const unsigned int width;
    size_t time_iteration;
} conway;

void conway_print_grid(const conway * c);

unsigned int conway_count_neighbors(conway *restrict c, const unsigned int row, const unsigned int column);

bool conway_place_glider(conway *restrict c, const unsigned int row, const unsigned int column);

void set_cell(conway *restrict c, const unsigned int row, const unsigned int column, const bool alive);

#endif // CONWAY_H
