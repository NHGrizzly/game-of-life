#include "conway.h"
#include "terminal.h"


void conway_print_grid(const conway * c)
{
    terminal_clear();
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
