cmake_minimum_required(VERSION 4.0)
project(taschenrechner C)

set(CMAKE_C_STANDARD 23)

add_executable(taschenrechner main.c
        main.c
        src/design.c
        src/input.c
        src/parser.c
        src/functions.c
        src/special_functions.c
        "src/+ funktion.c"
        "include/+ funktion.h")
