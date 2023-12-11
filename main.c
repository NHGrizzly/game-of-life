#include "conway.h"
#include "terminal.h"

int main(int argc, char const *argv[])
{
    conway c = {.grid = {{0}}, .height = 10, .width = 10};

    conway_print_grid(&c);

    return 0;
}

