//
// Created by fabia on 19.09.2025.
//

#ifndef TASCHENRECHNER_PARSER_H
#define TASCHENRECHNER_PARSER_H

typedef enum ExpressionType {
    NUMBER,
    SPECIAL_FUNC,
    OPERATOR,
    BRACKET
} ExpressionType;

typedef struct Expression {
    ExpressionType type;
    double* number;

} Expression;


#endif //TASCHENRECHNER_PARSER_H