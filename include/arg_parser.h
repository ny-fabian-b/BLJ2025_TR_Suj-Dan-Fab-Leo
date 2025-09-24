//
// Created by fabia on 23.09.2025.
//

#ifndef TASCHENRECHNER_ARG_PARSER_H
#define TASCHENRECHNER_ARG_PARSER_H
#include "string.h"
#include "sub_expression_parser.h"

void parseArgs(char *start, size_t len, double** out, size_t* n_args);

#endif //TASCHENRECHNER_ARG_PARSER_H
