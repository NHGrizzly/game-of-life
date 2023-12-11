#include "conway.h"
#include "terminal.h"

#ifdef USE_ARGS
int main(int argc, char const *argv[])
#else
int main()
#endif
{
    conway c = {.grid = {{0}}, .height = 10, .width = 10};

    set_cell(&c, 0, 9, true);
    set_cell(&c, 0, 0, true);
    set_cell(&c, 9, 0, true);
    set_cell(&c, 9, 9, true);


    conway_place_glider(&c, 2, 2);
    
    wait(1000);

    conway_print_grid(&c);

    return 0;
}

