//
// Created by daniel on 25.09.2025.
//

#include "../include/macros.h"

#include <string.h>

#include "../include/life_calculator.h"
#include "../include/rps_game.h"


int executeMacros(const char* input) {
    if (strcmp(input, "bmi\n") == 0) {
        BodyMassIndexCalculator();
        return 1;
    }
    if (strcmp(input, "calories\n") == 0) {
        CaloriesCalculator();
        return 1;
    }
    if (strcmp(input, "sleep\n") == 0) {
        SleepCalculator();
        return 1;

    }
    if (strcmp(input, "promille\n") == 0) {
        AlcPromilleCalculator();
        return 1;
    }

    if (strcmp(input, "rps\n") == 0) {
        rpsGame();
        return 1;
    }
    return 0;
}