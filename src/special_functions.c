//
// Created by fabia on 19.09.2025.
//

#include "../include/special_functions.h"

#include "../include/colors.h"
#include "../include/life_calculator.h"

SFFunc sffuncs[N_SF_FUNCS] = {
    {calc_sin, "sin"},
    {calc_cos, "cos"},
    {calc_tan, "tan"},
    {calc_factorial, "fact"},
    {calc_log, "log"},
    {calc_log2, "log2"},
    {calc_log10, "log10"},
    {calc_ln, "ln"},
    {calc_exp, "exp"},
    {calc_sqrt, "sqrt"},
    {calc_cbrt, "cbrt"},
    {calc_root, "root"},
};

SFConstant sfconstants[N_SF_CONSTANTS] = {
    {PI, "pi"},
    {E, "e"}
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

int check_n_args(size_t actual, size_t n) {
    if (actual != n) {
        printf("%sinvalid number of arguments %s\n", C_RED, C_RESET);
        return 1;
    }
    return 0;
}

// special functions

double d_sin(double x) {
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

double calc_sin(double* args, size_t n_args) {
    if (check_n_args(n_args, 1)) return NAN;
    return d_sin(args[0]);
}

size_t z_pow(size_t base, size_t exp) {
    size_t result = 1;
    for (size_t i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

double d_cos(double x) {
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

double calc_cos(double* args, size_t n_args) {
    if (check_n_args(n_args, 1)) return NAN;
    return d_cos(args[0]);
}
double d_tan(double x) {
    return d_sin(x) / d_cos(x);
}

double calc_tan(double* args, size_t n_args) {
    if (check_n_args(n_args, 1)) return NAN;
    return d_tan(args[0]);
}

size_t factorial(size_t x) {
    size_t result = 1;

    for (size_t i = 1; i <= x; i++) {
        result *= i;
    }

    return result;
}

double calc_factorial(double* args, size_t n_args) {
    if (check_n_args(n_args, 1)) return NAN;

    return (double) factorial((size_t) args[0]);
}

double exp(double x) { // !!!! function from chatgpt !!!!
    double term = 1.0;
    double sum  = 1.0;
    for (int n = 1; n < 1000; n++) {
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
    for (int n = 0; n < 1000; n++) {
        sum += term / (2*n + 1);
        term *= y2;
        if (term < TOLERANCE && term > -TOLERANCE) break;
    }
    return 2 * sum;
}

double d_pow(double base, double exponent) {
    return exp(exponent * ln(base));
}

double d_abs(double x) {
    if (x < 0) return -x;
    return x;
}

double log(double value, double base) {
    return ln(value) / ln(base);
}
double calc_ln(double* args, size_t n_args) {
    if (check_n_args(n_args, 1)) return NAN;
    return ln(args[0]);
}

double calc_exp(double* args, size_t n_args) {
    if (check_n_args(n_args, 1)) return NAN;
    return exp(args[0]);
}

double calc_log2(double* args, size_t n_args) {
    if (check_n_args(n_args, 1)) return NAN;
    return log(args[0], 2.0);
}

double calc_log10(double* args, size_t n_args) {
    if (check_n_args(n_args, 1)) return NAN;
    return log(args[0], 10.0);
}

double calc_sqrt(double* args, size_t n_args) {
    if (check_n_args(n_args, 1)) return NAN;
    return d_pow(args[0], 0.5);
}

double calc_cbrt(double* args, size_t n_args) {
    if (check_n_args(n_args, 1)) return NAN;
    return d_pow(args[0], 1.0/3.0);
}

double calc_root(double* args, size_t n_args) {
    if (check_n_args(n_args, 2)) return NAN;
    return d_pow(args[0], 1.0 / args[1]);
}

double calc_log(double* args, size_t n_args) {
    if (check_n_args(n_args, 2)) return NAN;
    double base = args[1];
    double value = args[0];

    return log(value, base);
}

double d_mod(double x, double y) {
    if (y == 0) {
        return 0.0 / 0.0; // nan;
    }

    size_t a = (size_t) (x / y);

    return x - (double) a * y;
}

double calc_pow(double* args, size_t n_args) {
    if (check_n_args(n_args, 2)) return NAN;
    return d_pow(args[0], args[1]);
}
double calc_mod(double* args, size_t n_args) {
    if (check_n_args(n_args, 2)) return NAN;
    return d_mod(args[0], args[1]);
}