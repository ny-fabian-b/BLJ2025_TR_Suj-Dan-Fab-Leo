//
// Created by fabia on 19.09.2025.
//

#include "../include/special_functions.h"

double evaluateSFConstant(char* sf_string) {
    if (strcmp(sf_string, "pi") == 0) {
        return 3.14;
    }
    return 0;
}

double evaluateSFFunc(char* sf_string, double* args) {
    if (strcmp(sf_string, "sin") == 0) {
        return args[0] * 3;
    }
    return 0;
}

double evaluateSpecialFunc(Expression special_func) {
    if (special_func.special_func_type == SF_CONSTANT) {
        return evaluateSFConstant(special_func.special_func_string);
    }
    if (special_func.special_func_type == SF_FUNC) {
        return evaluateSFFunc(special_func.special_func_string, special_func.special_func_args);
    }
}

void evaluateSpecialFunctions(Expression** expr_arr, size_t expr_len) {
    for (size_t i = 0; i < expr_len; i++) {
        Expression expr = (*expr_arr)[i];

        if (expr.type == SPECIAL_FUNC) {
            (*expr_arr)[i] = createNumberExpression(evaluateSpecialFunc(expr));
        }
    }
}