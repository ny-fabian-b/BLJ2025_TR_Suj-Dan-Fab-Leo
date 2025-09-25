cmake_minimum_required(VERSION 4.0)
project(taschenrechner C)

set(CMAKE_C_STANDARD 23)

add_executable(taschenrechner main.c
        main.c
        src/design.c
        src/input.c
        src/sub_expression_parser.c
        src/functions.c
        src/special_functions.c
        include/config.h
        src/string.c
        include/string.h
        src/bracket_parser.c
        include/bracket_parser.h
        src/arg_parser.c
        include/arg_parser.h
        src/simple_functions.c
        include/simple_functions.h
        src/parser.c
        include/parser.h
        src/rps_game.c
        src/parse_negatives.c
        include/parse_negatives.h
        src/parse_factorial.c
        include/parse_factorial.h
        src/life_calculator.c
        "src/Multiply_and_divide.c"
        include/life_calculator.h)
