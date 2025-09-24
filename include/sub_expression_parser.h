//
// Created by fabia on 19.09.2025.
//

#ifndef TASCHENRECHNER_SUB_EXPRESSION_PARSER_H
#define TASCHENRECHNER_SUB_EXPRESSION_PARSER_H

#include "../include/config.h"
#include "../include/string.h"

#include <stddef.h>
#include <string.h>
#include <stdio.h>

extern char* operators;

typedef enum ExpressionType {
    EXPR_NONE, //0
    NUMBER, //1
    SPECIAL_FUNC,//2
    OPERATOR, //3
    BRACKET //4
} ExpressionType;

typedef enum BracketType {
    BRACKET_NONE,
    OPENING_BRACKET,
    CLOSING_BRACKET
} BracketType;

typedef enum SpecialFuncType {
    SF_NONE,
    SF_CONSTANT,
    SF_FUNC,
} SpecialFuncType;

typedef struct Expression Expression;

typedef struct Expression {
    ExpressionType type;

    double number;

    char* special_func_string;
    double* special_func_args;
    size_t special_func_n_args;
    SpecialFuncType special_func_type;

    char operator;

    BracketType bracketType;

} Expression;

int isNumber(char c);
int isOperator(char c);
int isBracket(char c);

void parseExpression(Expression** expressionarr, size_t* size, char* input, size_t input_len) ;

void parseSubExpression(size_t* i, char* expression, ExpressionType type, int* end, ExpressionType* next_type, Expression* out, size_t len);

void parseNumber(size_t* i, char* expression, int* isEnd, ExpressionType* next_type, Expression* out, size_t len);
void parseSpecialFunc(size_t* i, char* expression, int* end, ExpressionType* next_type, Expression* out, size_t len);
void parseOperator(size_t* i, char* expression, int* end, ExpressionType* next_type, Expression* parsed, size_t len);
void parseBracket(size_t* i, char* expression, int* end, ExpressionType* next_type, Expression* parsed, size_t len);

void initExpression(Expression* expr);
Expression createNumberExpression(double number);
Expression createOperatorExpression(char c);
Expression createSpecialFuncExpression(char* special_func);
Expression createBracketExpression(BracketType bracket_type);

void printExpression(Expression* expr);
void printExpressionType(ExpressionType type);
void printBracketType(BracketType type);

void printExpressionArr(Expression* arr, size_t size);

void initParser();

#endif //TASCHENRECHNER_PARSER_H