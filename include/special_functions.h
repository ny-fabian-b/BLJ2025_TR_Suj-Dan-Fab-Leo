//
// Created by fabia on 19.09.2025.
//

#ifndef TASCHENRECHNER_SPECIAL_FUNCTIONS_H
#define TASCHENRECHNER_SPECIAL_FUNCTIONS_H

#include "sub_expression_parser.h"

double evaluateSFConstant(char* sf_string);

double evaluateSFFunc(char* sf_string, double* args);

void evaluateSpecialFunctions(Expression** expr_arr, size_t expr_len);

double evaluateSpecialFunc(Expression special_func);

#define TRIG_TOLERANCE 1e-15
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286

double calcsin(double* args);
double calccos(double* args);
size_t calcpow(size_t base, size_t exp);
size_t z_factorial(size_t n);
double factorial(double* args);

typedef struct SFFunc {
    double (*func)(double*);
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