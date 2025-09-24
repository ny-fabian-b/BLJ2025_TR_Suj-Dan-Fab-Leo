//
// Created by sujan on 24.09.2025.
//

#include "../include/simple_functions.h"

#include <stdlib.h>

#include "../include/sub_expression_parser.h"

size_t find_operator(char op, Expression**expression, size_t len, int reverse) {
    if (reverse) {
        for (size_t i = 0; i < len; i++) {
            if ((*expression)[i].type == OPERATOR) {
                if ((*expression)[i].operator == op) {
                    return i;
                }
            }
        }
    }

    return SIZE_MAX;
}

double evaluate_operator_at(size_t i, Expression** expression) {
    char op = (*expression)[i].operator;
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
    }
}

void put_result_at(size_t i, double result, size_t* len, Expression** expression) {
    //.....1+1..... -> ....2.....
    *len -= 2;
    Expression* new_expression = malloc(*len * sizeof(Expression));

    memcpy(new_expression, *expression, (i - 1) * sizeof(Expression));
    memcpy(&new_expression[i], &(*expression)[i + 2], (*len - i) * sizeof(Expression));
    //1*2*3 -> 2 3 2 3
    //1*2*3 -< 2*3

    free(*expression);

    *expression = new_expression;

    (*expression)[i - 1] = createNumberExpression(result);

    printf("%d %d %d %d\n\n", *len, *len - i, i - 1, i);
    printExpressionArr(*expression, *len);
    printf("\n");
}


void evaluate_simple_functions(Expression**expression, size_t* len) {
    size_t i = 0;
    //exp
    while (1) {
        size_t exp = find_operator(i, expression, len);
    }

    //mult, div
    while (1) {
        size_t mult = find_operator('*',expression,*len);
        size_t div = find_operator('/',expression,*len);
        i = mult;
        if (mult > div) {
            i = div;
        }

        if (i == SIZE_MAX) {
            break;
        }

        double result = evaluate_operator_at(i, expression);
        put_result_at(i, result, len, expression);
    }

    //add, sub
    i = 0;
    while (1) {
        size_t sub = find_operator('-',expression,*len);
        size_t add = find_operator('+',expression,*len);
        i = add;
        if (add > sub) {
            i = sub;
        }

        if (i == SIZE_MAX) {
            break;
        }

        double result = evaluate_operator_at(i, expression);
        put_result_at(i, result, len, expression);
    }

}
