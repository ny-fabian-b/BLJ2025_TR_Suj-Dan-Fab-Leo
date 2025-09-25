//
// Created by fabia on 23.09.2025.
//
#include "../include/arg_parser.h"

#include <stdlib.h>

#include "../include/parser.h"

void parseArgs(char *start, size_t len, double** out, size_t* n_args) {
    // split by ,
    size_t arg_start = 0;

    *out = NULL;
    *n_args = 0;

    for (size_t i = 0; i < len; i++) {
        char c = start[i];
        if (c == ',' || i == len - 1) {
            // add new expression
            size_t arg_len = i - arg_start + 1;

            char* arg_str = malloc(arg_len * sizeof(char));
            memcpy(arg_str, &start[arg_start], (arg_len - 1) * sizeof(char));
            arg_str[arg_len - 1] = '\0';

            double argn = evaluateExpression(arg_str, arg_len);
            //printf("%d '%s' a%ca\n", arg_len - 1, arg_str, c);

            // increment size of args
            double* new_args = malloc((*n_args + 1) * sizeof(double));
            if (*n_args > 0) {
                memcpy(new_args, *out, *n_args * sizeof(double));
                free(arg_str);
            }



            new_args[*n_args] = argn;

            free(*out);
            *out = new_args;

            // update args
            (*out)[*n_args] = argn;


            (*n_args)++;

            arg_start = i + 1;
        }
    }
}
