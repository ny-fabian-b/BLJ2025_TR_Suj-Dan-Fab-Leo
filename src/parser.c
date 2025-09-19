//
// Created by fabia on 19.09.2025.
//

#include "../include/parser.h"

#include <stdlib.h>

char* operators = nullptr;

void initParser() {
    operators = OPERATORS;
}
int isNumber(char c) {
    return c >= '0' && c <= '9' || c == '.';
}
int isOperator(char c) {
    return strFind(OPERATORS, c) != SIZE_MAX;
}
int isBracket(char c) {
    return c == ')' || c == '(';
}

ExpressionType guessType(char c) {
    if (isNumber(c)) {
        return NUMBER;
    }
    if (isBracket(c)) {
        return BRACKET;
    }
    if (isOperator(c)) {
        return OPERATOR;
    }
    return SPECIAL_FUNC;
}

void initExpression(Expression* expr) {
    expr->number = 0;
    expr->type = EXPR_NONE;
    expr->specialFunc = nullptr;
    expr->bracketType = BRACKET_NONE;
    expr->operator = '\0';
}

Expression createNumberExpression(double number) {
    Expression expr;
    initExpression(&expr);
    expr.type = NUMBER;
    expr.number = number;
    return expr;
}
Expression createOperatorExpression(char c) {
    Expression expr;
    initExpression(&expr);
    expr.type = OPERATOR;
    expr.operator = c;
    return expr;
}
Expression createSpecialFuncExpression(char* special_func) {
    Expression expr;
    initExpression(&expr);
    expr.type = SPECIAL_FUNC;
    expr.specialFunc = special_func;
    return expr;
}
Expression createBracketExpression(BracketType bracket_type) {
    Expression expr;
    initExpression(&expr);
    expr.type = SPECIAL_FUNC;
    expr.bracketType = bracket_type;
    return expr;
}

void printExpression(Expression* expr) {
    switch (expr->type) {
        case NUMBER:
            printf("NUMBER: %f\n", expr->number); break;
        case BRACKET:
            printf("BRACKET: %s\n", expr->specialFunc); break;
        case OPERATOR:
            printf("OPERATOR: %c\n", expr->operator); break;
        case SPECIAL_FUNC:
            printf("SPECIAL_FUNC: %s\n", expr->specialFunc); break;
        case EXPR_NONE:
            printf("EXPR_NONE\n"); break;
    }
}

void printExpressionType(ExpressionType type) {
    switch (type) {
        case NUMBER: printf("NUMBER"); break;
        case BRACKET: printf("BRACKET"); break;
        case SPECIAL_FUNC: printf("SPECIAL_FUNC"); break;
        case OPERATOR: printf("OPERATOR"); break;
        case EXPR_NONE: printf("EXPR_NONE"); break;
    }
}
void printBracketType(BracketType type) {
    switch (type) {
        case OPENING_BRACKET: printf("("); break;
        case CLOSING_BRACKET: printf(")"); break;
    }
}

void parseSubExpression(size_t* i, char* expression, ExpressionType type, int* isEnd, ExpressionType* next_type, Expression* out, size_t len) {
    switch (type) {
        case NUMBER:
            parseNumber(i, expression, isEnd, next_type, out, len);
            break;
        case OPERATOR:
            parseOperator(i, expression, isEnd, next_type, out, len);
            break;
        case BRACKET:
            parseOperator(i, expression, isEnd, next_type, out, len);
            break;
    }
}

void parseNumber(size_t* i, char* expression, int* isEnd, ExpressionType* next_type, Expression* out, size_t len) {
    size_t start = *i;

    while (*i != len - 1 && isNumber(expression[*i])) {
        (*i)++;
    }
    //end
    if (*i == len - 1) {
        *isEnd = 1;
        *next_type = EXPR_NONE;
    }
    // next type
    else {
        char next_char = expression[*i];
        if (isOperator(next_char)) {
            *next_type = OPERATOR;
        }
        else if (isBracket(next_char)) {
            *next_type = BRACKET;
        }
        else {
            *next_type = SPECIAL_FUNC;
        }
    }
    // out
    size_t num_len = *i - start;

    char* num_str = malloc(sizeof(char) * (num_len + 1));
    num_str[num_len] = '\0';
    memcpy(num_str, expression + start, sizeof(char) * num_len);

    double out_num = strtod(num_str, NULL);

    free(num_str);

    *out = createNumberExpression(out_num);
}

void parseSpecialFunc(size_t* i, char* expression, int* isEnd, ExpressionType* next_type, Expression* out, size_t len) {
    size_t start = *i;

    while (*i != len - 1 && guessType(expression[*i]) == SPECIAL_FUNC) {
        (*i)++;
    }
    //end
    if (*i == len - 1) {
        *isEnd = 1;
        *next_type = EXPR_NONE;
    }
    // next type
    else {
        char next_char = expression[*i];
        if (isNumber(next_char)) {
            *next_type = NUMBER;
        }
        else if (isBracket(next_char)) {
            *next_type = BRACKET;
        }
        else if (isOperator(next_char)) {
            *next_type = OPERATOR;
        }
    }
    // out
    size_t sf_len = *i - start;

    char* sf_str = malloc(sizeof(char) * (sf + 1));
    sf_str[sf_len] = '\0';
    memcpy(sf_str, expression + start, sizeof(char) * sf_len);

    double out_num = strtod(sf_str, NULL);

    free(sf_str);

    *out = createNumberExpression(out_num);
}
void parseOperator(size_t* i, char* expression, int* isEnd, ExpressionType* next_type, Expression* out, size_t len) {
    (*i)++; // len of operator is always 1
    //end
    if (*i == len - 1) {
        *isEnd = 1;
        *next_type = EXPR_NONE;
    }
    // next type
    else {
        char next_char = expression[*i];
        if (isNumber(next_char)) {
            *next_type = NUMBER;
        }
        else if (isBracket(next_char)) {
            *next_type = BRACKET;
        }
        else {
            *next_type = SPECIAL_FUNC;
        }
    }
    // out

    char out_op = expression[*i - 1];

    *out = createOperatorExpression(out_op);
}
void parseBracket(size_t* i, char* expression, int* isEnd, ExpressionType* next_type, Expression* out, size_t len) {
    (*i)++; // len of bracket is always 1
    //end
    if (*i == len - 1) {
        *isEnd = 1;
        *next_type = EXPR_NONE;
    }
    // next type
    else {
        char next_char = expression[*i];
        if (isNumber(next_char)) {
            *next_type = NUMBER;
        }
        else if (isBracket(next_char)) {
            *next_type = BRACKET;
        }
        else {
            *next_type = SPECIAL_FUNC;
        }
    }
    // out
    char bracket_char = expression[*i - 1];

    BracketType out_bracket = BRACKET_NONE;
    if (bracket_char == '(') {
        out_bracket = OPENING_BRACKET;
    }
    else if (bracket_char == ')') {
        out_bracket = CLOSING_BRACKET;
    }


    *out = createBracketExpression(out_bracket);
}

void parseExpression(Expression** expressionptr, size_t* expression_len, char* input) {
    size_t input_len = strlen(input);

    //Expression* expression = *expressionptr;
    //expression = nullptr;

    size_t i = 0;
    int end = 0;
    ExpressionType type = guessType(input[0]);
    ExpressionType nextType;

    while (!end) {
        Expression cexpr;
        parseSubExpression(&i, input, type, &end, &nextType, &cexpr, input_len);

        printExpression(&cexpr);


        printf("%llu, %d, %d, %dgg\n", i, type, end, nextType);
        type = nextType;

        //break;
    }
}
