#include <stdio.h>

#include "include/parser.h"
#include "include/sub_expression_parser.h"
#include "include/special_functions.h"
#include "include/design.h"
#include "include/input.h"
#include "include/config.h"
#include "include/design.h"
#include "include/macros.h"

int main(void) {
    ka();

    printf("welcome to Taschenrechner! enter help for a guide");

    while (1) {
        char input[MAX_INPUT_SIZE];
        getInput(input);

        if (executeMacros(input)) {
            strncpy(input, "hallo", MAX_INPUT_SIZE);
            continue;
        }

        double r = evaluateExpression(input, strlen(input));

        printf("result: %f\n", r);
    }
}
