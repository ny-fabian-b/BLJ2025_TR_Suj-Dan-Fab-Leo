//
// Created by fabia on 25.09.2025.
//

#include "../include/evaluate_factorial.h"

#include "../include/special_functions.h"
#include "../include/evaluate_negatives.h"

void evaluateFactorials(Expression** expr_arr, size_t* len) {
    ExpressionType p_expr_type = EXPR_NONE;

    for (size_t i = 0; i < *len; i++) {
        Expression expr = (*expr_arr)[i];

        if (expr.type == SPECIAL_FUNC && expr.special_func_type == SF_CONSTANT && p_expr_type == NUMBER) {
            if (strcmp(expr.special_func_string, "!") == 0) {
                // evaluate factorial
                double result = (double) factorial((size_t) (*expr_arr)[i - 1].number);
                (*expr_arr)[i - 1] = createNumberExpression(result);

                // remove factorial SF
                removeExpression(expr_arr, len, i);
                i--;
            }
        }

        p_expr_type = expr.type;
    }
}
