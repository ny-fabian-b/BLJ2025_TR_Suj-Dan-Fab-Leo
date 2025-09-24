//
// Created by fabia on 24.09.2025.
//

#include "../include/parser.h"

#include <stdlib.h>

#include "../include/bracket_parser.h"
#include "../include/simple_functions.h"
#include "../include/special_functions.h"

double evaluateExpression(char* expr, size_t len) {
    Expression* expr_arr = NULL;
    size_t expr_len  = 0;

    parseExpression(&expr_arr, &expr_len, expr, len);

    return evaluateParsedExpression(&expr_arr, &expr_len);
}

double evaluateParsedExpression(Expression** expr_arr, size_t* expr_len) {
    for (size_t i = 0; i < *expr_len; i++) {
        Expression expr = (*expr_arr)[i];

        if (expr.type == BRACKET) {
            if (expr.bracketType == OPENING_BRACKET) {
                size_t closing_pos = find_closing_bracket_expr(*expr_arr, *expr_len, i);

                // extract subexpression array
                size_t subexpr_len = closing_pos - i - 2;
                size_t starting_subexpr_len = subexpr_len;
                Expression* subexpr_arr = malloc(subexpr_len * sizeof(Expression));
                memcpy(subexpr_arr, &(*expr_arr)[i + 1], subexpr_len * sizeof(Expression));

                printExpressionArr(subexpr_arr, subexpr_len);

                double result = evaluateParsedExpression(&subexpr_arr, &subexpr_len);
                //double result = 100.0;

                free(subexpr_arr);

                // put result in
                // 1+(1+2+3)+2+4
                //1+ 6 +2+4

                size_t new_expr_len = *expr_len - starting_subexpr_len - 1;
                Expression* new_expr_arr = malloc(new_expr_len * sizeof(Expression));

                memcpy(new_expr_arr, *expr_arr, i * sizeof(Expression));
                memcpy(&new_expr_arr[i + 1], &(*expr_arr)[closing_pos], (*expr_len - closing_pos) * sizeof(Expression));

                new_expr_arr[i] = createNumberExpression(result);

                printExpressionArr(new_expr_arr, new_expr_len);

                free(*expr_arr);
                *expr_arr = new_expr_arr;
                *expr_len = new_expr_len;

                printf("sudhsudhusudhuh\n");
            }
        }
    }
    evaluateSpecialFunctions(expr_arr, *expr_len);
    evaluate_simple_functions(expr_arr, expr_len);

    return (*expr_arr)[0].number;
}
