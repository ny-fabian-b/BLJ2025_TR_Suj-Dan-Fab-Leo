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



double calcsin(double* args);
double calccos(double* args);

typedef struct SFFunc {
    double (*func)(double*);
    char* name;
} SFFunc;

typedef struct SFConstant {
    double value;
    char* name;
} SFConstant;

#define N_SF_FUNCS 2
#define N_SF_CONSTANTS 2

extern SFFunc sffuncs[];
extern SFConstant sfconstant[];



#endif //TASCHENRECHNER_SPECIAL_FUNCTIONS_H