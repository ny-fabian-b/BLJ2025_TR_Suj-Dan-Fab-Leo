#include <stdio.h>

#include "include/functions.h"
#include "include/parser.h"
#include "include/special_functions.h"
#include "include/design.h"
#include "include/input.h"
#include "include/config.h"
#include "include/string.h"

int main(void) {
    char input[MAX_INPUT_SIZE];
    getInput(input);

    Expression* expression;
    size_t expr_len = 0;
    parseExpression(&expression, &expr_len, input);

    printf("%s\n", input);
}