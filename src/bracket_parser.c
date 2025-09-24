//
// Created by fabia on 22.09.2025.
//

#include "../include/bracket_parser.h"

size_t find_closing_bracket(const char* str, size_t opening_pos) {
    size_t len = strlen(str);

    size_t n_opening_brackets = 0;
    size_t n_closing_brackets = 0;

    size_t i = opening_pos;
    do {
        if (i == len) {
            return SIZE_MAX;
        }

        const char c = str[i];

        if (c == ')') {
            n_closing_brackets++;
        }
        else if (c == '(') {
            n_opening_brackets++;
        }
        i++;
    } while (n_closing_brackets != n_opening_brackets);

    return i;
}