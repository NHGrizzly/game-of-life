#include "conway.h"
#include "terminal.h"

#ifdef USE_ARGS
int main(int argc, char const *argv[])
#else
int main()
#endif
{
    terminal_clear();

    conway c = {.grid = {{0}}, .height = 32, .width = 60};


    conway_place_glider(&c, 2, 2);
    
    for (c.time_iteration = 0; c.time_iteration < 1000; c.time_iteration++)
    {
        conway_print_grid(&c);
        conway_timestep(&c);
        wait(50);
    }

    return 0;
}

