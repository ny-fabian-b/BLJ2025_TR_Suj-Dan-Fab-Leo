//
// Created by fabia on 24.09.2025.
//

#include "../include/parser.h"

double evaluateExpression(char* expr, size_t len) {
    Expression* expr_arr = NULL;
    size_t expr_len  = 0;

    parseExpression(&expr_arr, &expr_len, expr, len);

    return expr_arr[0].number;
}