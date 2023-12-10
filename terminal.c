#include "terminal.h"

#include <stdio.h>

bool terminal_print_at(const unsigned int row, const unsigned int col)
{
    terminal_goto(row, col);
    printf(CELL_CHARACTER);
}

bool terminal_goto(unsigned int row, unsigned int col)
{
    printf("\x1b[%u;%uH",row+1,col+1);
}

bool terminal_clear()
{
    printf("\x1b[2J");
}
