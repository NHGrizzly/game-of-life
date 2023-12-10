#include "terminal.h"

#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* code */
    terminal_clear();
    terminal_print_at( 0, 0 );
    terminal_print_at( 2, 1 );

    return 0;
}


static bool terminal_print_at(const unsigned int row, const unsigned int col)
{
    terminal_goto(row, col);
    printf("#");
}

bool terminal_goto(unsigned int row, unsigned int col)
{
    printf("\x1b[%u;%uH",row+1,col+1);
}

bool terminal_clear()
{
    printf("\x1b[2J");
}
