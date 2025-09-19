//
// Created by fabia on 19.09.2025.
//

#include "../include/input.h"

#include <stdio.h>

void getInput(char* s) {
    printf("Enter expression to evaluate: \n");
    fgets(s, MAX_INPUT_SIZE, stdin);
}

#include "../include/input.h"