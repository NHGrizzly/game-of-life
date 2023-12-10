#ifndef TERMINAL_H
#define TERMINAL_H

#include <stdbool.h>
#include <stdio.h>

#define CELL_CHARACTER "#"

bool terminal_goto(unsigned int row, unsigned int col);
bool terminal_clear();

bool terminal_print_at(const unsigned int row, const unsigned int col);

#endif // TERMINAL_H
