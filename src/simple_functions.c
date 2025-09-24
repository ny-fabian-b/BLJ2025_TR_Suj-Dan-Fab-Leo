//
// Created by sujan on 24.09.2025.
//

#include "simple_functions.h"
#include "../include/sub_expression_parser.h"

size_t find_operator(char op, Expression**expression, size_t len) {
    for (size_t i = 0; i < len; i++) {
        if ((*expression)[i].type == OPERATOR) {
            if ((*expression)[i].operator == op) {
                return i;
            }
        }
    }
    return SIZE_MAX;
}

void evaluate_simple_functions(Expression**expression, size_t len) {
    for (size_t i = 0; i < len; i++) {
         size_t exp = find_operator('^',expression,len);
        size_t exp = find_operator('*',expression,len);


    }

}