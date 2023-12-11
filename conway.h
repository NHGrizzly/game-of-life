#ifndef CONWAY_H
#define CONWAY_H

#include <stddef.h>
#include <stdbool.h>

#include "timing.h"

typedef struct conway
{
    bool grid[256][256];
    const unsigned int height;
    const unsigned int width;
    size_t time_iteration;
} conway;

void conway_set_cell(conway *restrict c, const unsigned int row, const unsigned int column, const bool alive);
void conway_timestep(conway *restrict c);
void conway_print_grid(const conway * c);

// spaceships
bool conway_place_glider(conway *restrict c, const unsigned int row, const unsigned int column);
bool conway_place_gosper(conway *restrict c, const unsigned int row, const unsigned int column);
bool conway_place_LWSS(conway *restrict c, const unsigned int row, const unsigned int column);
// bool conway_place_MWSS(conway *restrict c, const unsigned int row, const unsigned int column);
// bool conway_place_HWSS(conway *restrict c, const unsigned int row, const unsigned int column);

// methuselahs
bool conway_place_Rpentomino(conway *restrict c, const unsigned int row, const unsigned int column);

#endif // CONWAY_H
