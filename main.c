#include <stdio.h>

#include "include/functions.h"
#include "include/sub_expression_parser.h"
#include "include/special_functions.h"
#include "include/design.h"
#include "include/input.h"
#include "include/config.h"
#include "include/string.h"
#include "include/design.h"
#include "include/parser.h"
#include "include/functions.h"
int main(void) {
    char input[MAX_INPUT_SIZE];
    getInput(input);

    Expression* expressionarr = NULL;
    size_t expr_len = 0;
    parseExpression(&expressionarr, &expr_len, input);
}