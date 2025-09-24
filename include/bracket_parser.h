//
// Created by fabia on 22.09.2025.
//

#ifndef TASCHENRECHNER_BRACKET_PARSER_H
#define TASCHENRECHNER_BRACKET_PARSER_H

#include "sub_expression_parser.h"
#include <stddef.h>

size_t find_closing_bracket(const char* str, size_t opening_pos);

#endif //TASCHENRECHNER_BRACKET_PARSER_H