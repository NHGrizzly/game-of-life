
cmake_minimum_required(VERSION 3.6)

project(GameOfLife)

add_executable(terminal_test terminal.c)

set_property(TARGET terminal_test PROPERTY C_STANDARD 99)
