//
// Created by fabia on 19.09.2025.
//

#include "../include/special_functions.h"

SFFunc sffuncs[N_SF_FUNCS] = {
    {calcsin, "sin"},
    {calccos, "cos"}
};

SFConstant sfconstants[N_SF_CONSTANTS] = {
    {3.14159265358, "pi"},
    {2.71, "e"}
};

double evaluateSFConstant(char* sf_string) {
    for (size_t i = 0; i < N_SF_CONSTANTS; i++) {
        SFConstant sfc = sfconstants[i];
        if (strcmp(sfc.name, sf_string) == 0) {
            return sfc.value;
        }
    }
    return 0;
}

double evaluateSFFunc(char* sf_string, double* args) {
    for (size_t i = 0; i < N_SF_FUNCS; i++) {
        SFFunc sff = sffuncs[i];
        if (strcmp(sff.name, sf_string) == 0) {
            return sff.func(args);
        }
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


// special functions


double calcsin(double* args) {
    double x = args[0];

    return x + 3;
}

double calccos(double* args) {
    double x = args[0];

    return x + 2;
}

double factorial(double* args) {
    size_t x = (size_t) args[0];

    size_t result = 1;

    for (size_t i = 1; i < x; i++) {
        result *= i;
    }

    return (double) result;
}