//
// Created by fabia on 23.09.2025.
//
#include "../include/arg_parser.h"

#include <stdlib.h>

void parseArgs(char *start, size_t len, double** out, size_t* n_args) {
    // split by ,
    size_t arg_start = 0;

    *out = NULL;
    *n_args = 0;

    for (size_t i = 0; i < len; i++) {
        char c = start[i];
        if (c == ',' || i == len - 1) {
            // increment size of args
            double* new_args = malloc((*n_args + 1) * sizeof(double));
            memcpy(new_args, *out, *n_args * sizeof(double));

            // add new expression
            size_t arg_len = i - arg_start;
            //...

            double argn = 23;
            new_args[*n_args] = argn;

            free(*out);
            *out = new_args;

            // update args
            (*out)[*n_args] = argn;


            (*n_args)++;
        }
    }
}
