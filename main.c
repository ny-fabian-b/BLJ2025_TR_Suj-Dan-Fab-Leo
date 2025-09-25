#include <stdio.h>

#include "include/colors.h"
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

    printf("\n%swelcome to Taschenrechner! enter 'help' for a guide\n", C_CYAN);

    while (1) {
        char input[MAX_INPUT_SIZE];
        getInput(input);

        if (executeMacros(input)) {
            continue;
        }

        printf("%s", C_GREY);

        double r = evaluateExpression(input, strlen(input));

        printf("%s\nresult: %f\n", C_CYAN, r);
    }
}
