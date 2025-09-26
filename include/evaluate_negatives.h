//
// Created by fabia on 24.09.2025.
//

#ifndef TASCHENRECHNER_PARSE_NEGATIVES_H
#define TASCHENRECHNER_PARSE_NEGATIVES_H

#include "sub_expression_parser.h"

void evaluateNegatives(Expression** expr_arr, size_t* len);

void insertExpression(Expression** expr_arr, size_t* len, size_t i, Expression expr);

void removeExpression(Expression** expr_arr, size_t* len, size_t i);

#endif //TASCHENRECHNER_PARSE_NEGATIVES_H