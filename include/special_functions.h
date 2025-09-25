//
// Created by fabia on 19.09.2025.
//

#ifndef TASCHENRECHNER_SPECIAL_FUNCTIONS_H
#define TASCHENRECHNER_SPECIAL_FUNCTIONS_H

#include "sub_expression_parser.h"

int evaluateSFConstant(char* sf_string, double* out);

int evaluateSFFunc(char* sf_string, double* args, size_t n_args, double* out);

void evaluateSpecialFunctions(Expression** expr_arr, size_t expr_len);

int evaluateSpecialFunc(Expression special_func, double* out);

#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286

double calc_sin(double* args, size_t n_args);
double calc_cos(double* args, size_t n_args);

size_t z_pow(size_t base, size_t exp);
double r_pow(double base, double exp);

double exp(double x);
double ln(double x);

size_t factorial(size_t n);
double calc_factorial(double* args, size_t n_args);

typedef struct SFFunc {
    double (*func)(double*, size_t);
    char* name;
} SFFunc;

typedef struct SFConstant {
    double value;
    char* name;
} SFConstant;

#define N_SF_FUNCS 3
#define N_SF_CONSTANTS 2

extern SFFunc sffuncs[];
extern SFConstant sfconstant[];



#endif //TASCHENRECHNER_SPECIAL_FUNCTIONS_H