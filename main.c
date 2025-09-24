#include <stdio.h>

#include "include/parser.h"
#include "include/functions.h"
#include "include/sub_expression_parser.h"
#include "include/special_functions.h"
#include "include/design.h"
#include "include/input.h"
#include "include/config.h"
#include "include/string.h"
#include "include/design.h"
#include "include/functions.h"

int main(void) {
    ka();

    while (1) {
        char input[MAX_INPUT_SIZE];
        getInput(input);

        double r = evaluateExpression(input, strlen(input));

        printf("result: %f\n", r);
    }
}
