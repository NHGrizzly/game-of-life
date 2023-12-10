#include "conway.h"
#include "terminal.h"

bool cells[CONWAY_HEIGHT][CONWAY_WIDTH];

int main(int argc, char const *argv[])
{
    CONWAY_GLIDER(cells,2,2)

    conway_print_grid(cells, CONWAY_HEIGHT, CONWAY_WIDTH);
    return 0;
}

bool conway_print_grid(bool grid[CONWAY_HEIGHT][CONWAY_WIDTH],
        const unsigned int grid_height, const unsigned int grid_width)
{
    terminal_clear();
    for (unsigned i = 0; i < grid_height; i++)
    {
        for (unsigned int j = 0; j < grid_width; j++)
        {
            if (grid[i][j])
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
