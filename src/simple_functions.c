//
// Created by sujan on 24.09.2025.
//

#include "../include/simple_functions.h"

#include <stdlib.h>

#include "../include/colors.h"
#include "../include/sub_expression_parser.h"
#include "../include/special_functions.h"

size_t find_operator(char op, Expression**expression, size_t len, int reverse) {
    for (size_t i = 0; i < len; i++) {
        size_t j = i;
        if (reverse) j = len - i - 1;

        if ((*expression)[j].type == OPERATOR) {
            if ((*expression)[j].operator == op) {
                return j;
            }
        }
    }

    return SIZE_MAX;
}

double evaluate_operator_at(size_t i, Expression** expression, size_t len) {
    char op = (*expression)[i].operator;

    if ((*expression)[i - 1].type != NUMBER || (*expression)[i + 1].type != NUMBER) {
        printf("%sInvalid Operands\n%s", C_RED, C_RESET);
        return NAN;
    }
    double n1 = (*expression)[i - 1].number;
    double n2 = (*expression)[i + 1].number;

    switch (op) {
        case '+':
            return n1 + n2;
        case '-':
            return n1 - n2;
        case '*':
            return n1 * n2;
        case '/':
            return n1 / n2;
        case '%':
            return d_mod(n1, n2);
        case '^':
            return d_pow(n1, n2);
    }

    return NAN;
}

void put_result_at(size_t i, double result, size_t* len, Expression** expression) {
    //.....1+1..... -> ....2.....
    *len -= 2;
    Expression* new_expression = malloc(*len * sizeof(Expression));

    memcpy(new_expression, *expression, (i - 1) * sizeof(Expression));
    memcpy(&new_expression[i], &(*expression)[i + 2], (*len - i) * sizeof(Expression));

    free(*expression);

    *expression = new_expression;

    (*expression)[i - 1] = createNumberExpression(result);

    printExpressionArr(*expression, *len);
}


void evaluate_simple_functions(Expression**expression, size_t* len) {
    size_t i = 0;
    //exp
    while (1) {
        size_t exp = find_operator('^', expression, *len, 1);

        if (exp == SIZE_MAX) break;

        if (exp < 1 || i > *len - 2) return;

        double result = evaluate_operator_at(exp, expression, *len);
        put_result_at(exp, result, len, expression);
    }

    //mult, div, mod
    while (1) {
        size_t mult = find_operator('*',expression,*len, 0);
        size_t div = find_operator('/',expression,*len, 0);
        size_t mod = find_operator('%',expression,*len, 0);

        i = mult;
        if (i > div) {
            i = div;
        }
        if (i > mod) {
            i = mod;
        }

        if (i == SIZE_MAX) {
            break;
        }

        if (i < 1 || i > *len - 2) return;

        double result = evaluate_operator_at(i, expression, *len);
        put_result_at(i, result, len, expression);
    }

    //add, sub
    i = 0;
    while (1) {
        size_t sub = find_operator('-',expression,*len, 0);
        size_t add = find_operator('+',expression,*len, 0);
        i = add;
        if (add > sub) {
            i = sub;
        }

        if (i == SIZE_MAX) {
            break;
        }

        if (i < 1 || i > *len - 2) return;

        double result = evaluate_operator_at(i, expression, *len);
        put_result_at(i, result, len, expression);
    }

}
