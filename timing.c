#include "timing.h"

void wait(const long milliseconds)
{
    volatile clock_t start, current;
    start = clock();

    while ((current-start) < milliseconds)
    {
        current = clock();
    }
}
