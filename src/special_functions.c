//
// Created by fabia on 19.09.2025.
//

#include "../include/special_functions.h"
#include "../include/life_calculator.h"

SFFunc sffuncs[N_SF_FUNCS] = {
    {calc_sin, "sin"},
    {calc_cos, "cos"},
    {calc_factorial, "fact"}
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

int evaluateSFFunc(char* sf_string, double* args, size_t n_args, double* out) {
    for (size_t i = 0; i < N_SF_FUNCS; i++) {
        SFFunc sff = sffuncs[i];
        if (strcmp(sff.name, sf_string) == 0) {
            *out = sff.func(args, n_args);
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
        return evaluateSFFunc(
            special_func.special_func_string,
            special_func.special_func_args,
            special_func.special_func_n_args,
            out);
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


double calc_sin(double* args, size_t n_args) {
    double x = args[0];

    // modulo
    while (x > PI) {
        x -= 2 * PI;
    }
    while (x < -PI) {
        x += 2 * PI;
    }

    double term = x;
    double result = x;

    // iterate taylor series
    for (size_t i = 0; i < 50; i++) {
        term *= -(x * x) / ((2 * i + 2) * (2 * i + 3));  // !! term from chatgpt !!!
        result += term;

        if (term > -TOLERANCE && term < TOLERANCE) {
            break;
        }
    }

    return result;
}

size_t z_pow(size_t base, size_t exp) {
    size_t result = 1;
    for (size_t i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

double calc_cos(double* args, size_t n_args) {
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
        term *= -(x * x) / ((2 * i + 1) * (2 * i + 2)); // !! term from chatgpt !!!!
        result += term;

        if (term > -TOLERANCE && term < TOLERANCE) {
            break;
        }
    }

    return result;
}

size_t factorial(size_t x) {
    size_t result = 1;

    for (size_t i = 1; i <= x; i++) {
        result *= i;
    }

    return result;
}

double calc_factorial(double* args, size_t n_args) {
    size_t x = (size_t) args[0];

    return (double) factorial(x);
}

double exp(double x) { // !!!! function from chatgpt !!!!
    double term = 1.0;
    double sum  = 1.0;
    for (int n = 1; n < 100; n++) {
        term *= x / n;
        sum += term;
        if (term < TOLERANCE && term > -TOLERANCE) break;
    }
    return sum;
}

double ln(double x) { // !!!! function from chatgpt !!!!
    if (x <= 0) return 0.0/0.0; //nan

    double y = (x - 1) / (x + 1);
    double y2 = y * y;
    double term = y;
    double sum  = 0.0;
    for (int n = 0; n < 100; n++) {
        sum += term / (2*n + 1);
        term *= y2;
        if (term < TOLERANCE && term > -TOLERANCE) break;
    }
    return 2 * sum;
}

double r_pow(double base, double exponent) {
    return exp(base * ln(exponent));
}

double log(double exponent, double base) {
}