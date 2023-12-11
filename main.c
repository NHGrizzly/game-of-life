#include "conway.h"
#include "terminal.h"

#ifdef USE_ARGS
int main(int argc, char const *argv[])
#else
int main()
#endif
{
    terminal_clear();

    conway c = {.grid = {{0}}, .height = 48, .width = 100};

    conway_place_Rpentomino(&c, 20, 40);

    while(c.time_iteration < 3000)
    {
        conway_print_grid(&c);
        conway_timestep(&c);
        // wait(5);
        c.time_iteration++;
    }

    return 0;
}
