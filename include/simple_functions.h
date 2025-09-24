//
// Created by sujan on 24.09.2025.
//

#ifndef TASCHENRECHNER_SIMPLE_FUNCTIONS_H
#define TASCHENRECHNER_SIMPLE_FUNCTIONS_H

#include "sub_expression_parser.h"

void evaluate_simple_functions(Expression**expression, size_t* len);
void put_result_at(size_t size, double result, size_t * len, Expression ** expression);


#endif //TASCHENRECHNER_SIMPLE_FUNCTIONS_H