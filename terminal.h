#ifndef TERMINAL_H
#define TERMINAL_H

#include <stdbool.h>

static bool terminal_goto(unsigned int row, unsigned int col);
static bool terminal_clear();

static bool terminal_print_at(const unsigned int row, const unsigned int col);

#endif // TERMINAL_H
