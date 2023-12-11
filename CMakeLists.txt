
cmake_minimum_required(VERSION 3.6)

project(GameOfLife)
set_property(GLOBAL PROPERTY C_STANDARD 99)
add_compile_options(-Wall -Wextra -Wpedantic)

add_library(timing timing.c)

add_library(conway conway.c)
target_link_libraries(conway timing)

add_library(terminal terminal.c)

add_executable(main main.c)
target_link_libraries(main conway terminal)

