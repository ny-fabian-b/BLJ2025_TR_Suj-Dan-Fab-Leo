//
// Created by fabia on 24.09.2025.
//

#include "../include/parse_negatives.h"

#include <stdlib.h>


void insertExpression(Expression** expr_arr, size_t* len, size_t i, Expression expr) {
    Expression* new_expr_arr = malloc((*len + 1) * sizeof(Expression));

    memcpy(new_expr_arr, *expr_arr, i * sizeof(*new_expr_arr));
    memcpy(&new_expr_arr[i + 1], &(*expr_arr)[i], (*len - i) * sizeof(*new_expr_arr));

    new_expr_arr[i] = expr;

    free(*expr_arr);
    *expr_arr = new_expr_arr;

    (*len)++;
}

void removeExpression(Expression** expr_arr, size_t* len, size_t i) {
    Expression* new_expr_arr = malloc((*len - 1) * sizeof(Expression));

    memcpy(new_expr_arr, *expr_arr, (i) * sizeof(*new_expr_arr));
    memcpy(&new_expr_arr[i], &(*expr_arr)[i + 1], (*len - (i + 1)) * sizeof(*new_expr_arr));

    free(*expr_arr);
    *expr_arr = new_expr_arr;

    (*len)--;
}

void parseNegatives(Expression** expr_arr, size_t* len) {
    ExpressionType p_expr_type = EXPR_NONE;
    ExpressionType pp_expr_type = EXPR_NONE;
    Expression p_expr;
    for (size_t i = 0; i < *len; i++) {
        Expression* expr = &(*expr_arr)[i];

        if (expr->type == NUMBER && p_expr_type == OPERATOR && (pp_expr_type == OPERATOR || i == 1)) {
            if (p_expr.operator == '-') {
                expr->number = -(expr->number);
                removeExpression(expr_arr, len, i - 1);
                i--;
            }
        }
        /*
        if (
            (expr->type == BRACKET || expr->type == SPECIAL_FUNC) &&
            p_expr_type == OPERATOR && pp_expr_type == OPERATOR){
                //1+-(8*8) -> 1+-1*(8*8)
                removeExpression(expr_arr, len, i);
                insertExpression(expr_arr, len, i, createNumberExpression(1));
            }*/

        pp_expr_type = p_expr_type;

        p_expr_type = expr->type;
        p_expr = *expr;
    }

    printExpressionArr(*expr_arr, (*len));
};