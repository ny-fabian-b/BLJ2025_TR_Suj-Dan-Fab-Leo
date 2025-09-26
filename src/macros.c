//
// Created by daniel on 25.09.2025.
//

#include "../include/macros.h"

#include <stdio.h>
#include <string.h>

#include "../include/colors.h"
#include "../include/life_calculator.h"
#include "../include/rps_game.h"



int executeMacros(const char* input) {
    if (strcmp(input, "bmi\n") == 0) {
        BodyMassIndexCalculator();
        printf("\n");

        return 1;
    }
    if (strcmp(input, "calories\n") == 0) {
        CaloriesCalculator();
        printf("\n");

        return 1;
    }
    if (strcmp(input, "sleep\n") == 0) {
        SleepCalculator();
        printf("\n");

        return 1;

    }
    if (strcmp(input, "promille\n") == 0) {
        AlcPromilleCalculator();
        printf("\n");
        return 1;
    }

    if (strcmp(input, "rps\n") == 0) {
        rpsGame();
        printf("\n");
        return 1;
    }

    if (strcmp(input, "help\n") == 0) {
        // read
        FILE* fptr;
        fptr = fopen("../help.txt", "r");

        printf("%s", C_CYAN);

        char line[256];
        while (fgets(line, 256, fptr)) {
            printf("%s", line);
        }

        fclose(fptr);
        return 1;
    }
    return 0;
}