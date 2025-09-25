//
// Created by fabia on 19.09.2025.
//

#include "../include/special_functions.h"

SFFunc sffuncs[N_SF_FUNCS] = {
    {calcsin, "sin"},
    {calccos, "cos"},
    {factorial, "fact"}
};

SFConstant sfconstants[N_SF_CONSTANTS] = {
    {3.14159265358, "pi"},
    {2.71, "e"}
};

int evaluateSFConstant(char* sf_string, double* out) {
    for (size_t i = 0; i < N_SF_CONSTANTS; i++) {
        SFConstant sfc = sfconstants[i];
        if (strcmp(sfc.name, sf_string) == 0) {
            *out =  sfc.value;
            return 1;
        }
    }
    return 0;
}

int evaluateSFFunc(char* sf_string, double* args, double* out) {
    for (size_t i = 0; i < N_SF_FUNCS; i++) {
        SFFunc sff = sffuncs[i];
        if (strcmp(sff.name, sf_string) == 0) {
            *out = sff.func(args);
            return 1;
        }
    }
    return 0;
}

int evaluateSpecialFunc(Expression special_func, double* out) {
    if (special_func.special_func_type == SF_CONSTANT) {
        return evaluateSFConstant(special_func.special_func_string, out);
    }
    if (special_func.special_func_type == SF_FUNC) {
        return evaluateSFFunc(special_func.special_func_string, special_func.special_func_args, out);
    }
    return 0;
}

void evaluateSpecialFunctions(Expression** expr_arr, size_t expr_len) {
    for (size_t i = 0; i < expr_len; i++) {
        Expression expr = (*expr_arr)[i];

        if (expr.type == SPECIAL_FUNC) {
            double result = 0;
            if (evaluateSpecialFunc(expr, &result)) {
                (*expr_arr)[i] = createNumberExpression(result);
            }
        }
    }
}


// special functions


double calcsin(double* args) {
    double x = args[0];

    // modulo
    while (x > PI) {
        x -= 2 * PI;
    }
    while (x < -PI) {
        x += 2 * PI;
    }
    printf("%f\n", x);

    double term = x;
    double result = x;

    // iterate taylor series
    for (size_t i = 0; i < 50; i++) {
        term *= -(x * x) / ((2 * i + 2) * (2 * i + 3));
        result += term;

        if (term > -TOLERANCE && term < TOLERANCE) {
            break;
        }
    }

    return result;
}

size_t calcpow(size_t base, size_t exp) {
    for (size_t i = 1; i < exp; i++) {
        base *= base;
    }
    return base;
}

double calccos(double* args) {
    double x = args[0];

    // modulo
    while (x > PI) {
        x -= 2 * PI;
    }
    while (x < -PI) {
        x += 2 * PI;
    }
    double term = 1.0;
    double result = 1.0;

    // iterate taylor series
    for (size_t i = 0; i < 50; i++) {
        term *= -(x * x) / ((2 * i + 1) * (2 * i + 2));
        result += term;

        if (term > -TOLERANCE && term < TOLERANCE) {
            break;
        }
    }

    return result;
}

size_t z_factorial(size_t x) {
    size_t result = 1;

    for (size_t i = 1; i <= x; i++) {
        result *= i;
    }

    return result;
}

double factorial(double* args) {
    size_t x = (size_t) args[0];

    return (double) z_factorial(x);
}