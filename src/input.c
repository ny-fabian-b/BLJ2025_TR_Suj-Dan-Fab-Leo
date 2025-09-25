//
// Created by fabia on 19.09.2025.
//

#include "../include/input.h"

#include <stdio.h>

#include "../include/colors.h"

void getInput(char* s) {
    fflush(stdin);
    printf("%sEnter expression to evaluate: \n>", C_GREEN);
    printf("%s", C_BRIGHT_WHITE);
    fgets(s, MAX_INPUT_SIZE, stdin);
}

#include "../include/input.h"

// 1+56 ->
// 1|+|56