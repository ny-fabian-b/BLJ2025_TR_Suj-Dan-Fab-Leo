#include <stdio.h>

#include "include/functions.h"
#include "include/parser.h"
#include "include/special_functions.h"
#include "include/design.h"
#include "include/input.h"
#include "include/config.h"

int main(void) {
    char input[MAX_INPUT_SIZE];
    getInput(input);

    printf("%s\n", input);
}