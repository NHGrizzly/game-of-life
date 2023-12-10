
cmake_minimum_required(VERSION 3.6)

project(GameOfLife)
set_property(GLOBAL PROPERTY C_STANDARD 99)

add_library(terminal terminal.c)

add_executable(conway conway.c)

target_link_libraries(conway terminal)

