#include <string.h>

#include "conway.h"
#include "terminal.h"

// neighbor functions
/**
 * Counts the neighbors of `c->grid[row,column]`
 */
unsigned int conway_count_neighbors(conway *restrict c, const unsigned int row, const unsigned int column);
bool neighbor_UL(conway *restrict c, const unsigned int row, const unsigned int column); // upper left
bool neighbor_U(conway *restrict c, const unsigned int row, const unsigned int column); // uppper
bool neighbor_UR(conway *restrict c, const unsigned int row, const unsigned int column); // upper right
bool neighbor_L(conway *restrict c, const unsigned int row, const unsigned int column); // left
bool neighbor_R(conway *restrict c, const unsigned int row, const unsigned int column); // right
bool neighbor_BL(conway *restrict c, const unsigned int row, const unsigned int column); // bottom left
bool neighbor_B(conway *restrict c, const unsigned int row, const unsigned int column); // bottom
bool neighbor_BR(conway *restrict c, const unsigned int row, const unsigned int column); // bottom right

void conway_set_cell(conway *restrict c, const unsigned int row, const unsigned int column, const bool alive)
{
    c->grid[row][column] = alive;
}

void conway_timestep(conway *restrict c)
{
    conway copy;
    memcpy(&copy, c, sizeof(*c));

    for (size_t i = 0; i < c->height; i++)
    {
        for (size_t j = 0; j < c->width; j++)
        {
            switch (conway_count_neighbors(&copy, i, j))
            {
            case 2:
                c->grid[i][j] = copy.grid[i][j];
                break;
            case 3:
                c->grid[i][j] = true;
                break;
            
            default:
                c->grid[i][j] = false;
                break;
            }
        }
    }
}

void conway_print_grid(const conway * c)
{
    terminal_goto(0,0);
    for (unsigned i = 0; i < c->height; i++)
    {
        for (unsigned int j = 0; j < c->width; j++)
        {
            if (c->grid[i][j])
            {
                printf(CELL_CHARACTER);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

bool conway_place_glider(conway *restrict c, const unsigned int row, const unsigned int column)
{
    conway_set_cell(c, row, column+1, true);
    conway_set_cell(c, row+1, column+2, true);
    conway_set_cell(c, row+2, column, true);
    conway_set_cell(c, row+2, column+1, true);
    conway_set_cell(c, row+2, column+2, true);
    return true;
}

bool conway_place_gosper(conway *restrict c, const unsigned int row, const unsigned int column)
{
    conway_set_cell(c, row+4, column, true);
    conway_set_cell(c, row+5, column, true);
    conway_set_cell(c, row+4, column+1, true);
    conway_set_cell(c, row+5, column+1, true);
    conway_set_cell(c, row+4, column+10, true);
    conway_set_cell(c, row+5, column+10, true);
    conway_set_cell(c, row+6, column+10, true);
    conway_set_cell(c, row+3, column+11, true);
    conway_set_cell(c, row+7, column+11, true);
    conway_set_cell(c, row+2, column+12, true);
    conway_set_cell(c, row+8, column+12, true);
    conway_set_cell(c, row+2, column+13, true);
    conway_set_cell(c, row+8, column+13, true);
    conway_set_cell(c, row+5, column+14, true);
    conway_set_cell(c, row+3, column+15, true);
    conway_set_cell(c, row+7, column+15, true);
    conway_set_cell(c, row+4, column+16, true);
    conway_set_cell(c, row+5, column+16, true);
    conway_set_cell(c, row+6, column+16, true);
    conway_set_cell(c, row+5, column+17, true);
    conway_set_cell(c, row+2, column+20, true);
    conway_set_cell(c, row+3, column+20, true);
    conway_set_cell(c, row+4, column+20, true);
    conway_set_cell(c, row+2, column+21, true);
    conway_set_cell(c, row+3, column+21, true);
    conway_set_cell(c, row+4, column+21, true);
    conway_set_cell(c, row+1, column+22, true);
    conway_set_cell(c, row+5, column+22, true);
    conway_set_cell(c, row+0, column+24, true);
    conway_set_cell(c, row+1, column+24, true);
    conway_set_cell(c, row+5, column+24, true);
    conway_set_cell(c, row+6, column+24, true);
    conway_set_cell(c, row+2, column+34, true);
    conway_set_cell(c, row+3, column+34, true);
    conway_set_cell(c, row+2, column+35, true);
    conway_set_cell(c, row+3, column+35, true);
    return true;
}

unsigned int conway_count_neighbors(conway *restrict c, const unsigned int row, const unsigned int column)
{
    unsigned int neighbors = 0;

    if(neighbor_UL(c, row, column)) neighbors++;
    if(neighbor_U(c, row, column)) neighbors++;
    if(neighbor_UR(c, row, column)) neighbors++;
    if(neighbor_L(c, row, column)) neighbors++;
    if(neighbor_R(c, row, column)) neighbors++;
    if(neighbor_BL(c, row, column)) neighbors++;
    if(neighbor_B(c, row, column)) neighbors++;
    if(neighbor_BR(c, row, column)) neighbors++;

    return neighbors;
}

bool neighbor_UL(conway *restrict c, const unsigned int row, const unsigned int column)
{
    unsigned int neighbor_row = row != 0 ? row-1 : c->height - 1;
    unsigned int neighbor_column = column != 0 ? column-1 : c->width - 1;
    
    return c->grid[neighbor_row][neighbor_column];
}

bool neighbor_U(conway *restrict c, const unsigned int row, const unsigned int column)
{
    unsigned int neighbor_row = row != 0 ? row-1 : c->height - 1;
    
    return c->grid[neighbor_row][column];
}

bool neighbor_UR(conway *restrict c, const unsigned int row, const unsigned int column)
{
    unsigned int neighbor_row = row != 0 ? row-1 : c->height - 1;
    unsigned int neighbor_column = column != c->width - 1 ? column+1 : 0;
    
    return c->grid[neighbor_row][neighbor_column];
}

bool neighbor_L(conway *restrict c, const unsigned int row, const unsigned int column)
{
    unsigned int neighbor_column = column != 0 ? column-1 : c->width - 1;
    
    return c->grid[row][neighbor_column];
}

bool neighbor_R(conway *restrict c, const unsigned int row, const unsigned int column)
{
    unsigned int neighbor_column = column != c->width - 1 ? column+1 : 0;
    
    return c->grid[row][neighbor_column];
}

bool neighbor_BL(conway *restrict c, const unsigned int row, const unsigned int column)
{
    unsigned int neighbor_row = row != c->height - 1 ? row+1 : 0;
    unsigned int neighbor_column = column != 0 ? column-1 : c->width - 1;
    
    return c->grid[neighbor_row][neighbor_column];
}

bool neighbor_B(conway *restrict c, const unsigned int row, const unsigned int column)
{
    unsigned int neighbor_row = row != c->height - 1 ? row+1 : 0;
    
    return c->grid[neighbor_row][column];
}

bool neighbor_BR(conway *restrict c, const unsigned int row, const unsigned int column)
{
    unsigned int neighbor_row = row != c->height - 1 ? row+1 : 0;
    unsigned int neighbor_column = column != c->width - 1 ? column+1 : 0;
    
    return c->grid[neighbor_row][neighbor_column];
}
