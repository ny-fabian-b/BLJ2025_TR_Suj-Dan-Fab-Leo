//
// Created by daniel on 25.09.2025.
//

#include "../include/macros.h"

#include <string.h>

#include "../include/life_calculator.h"
#include "../include/rps_game.h"


int executeMacros(const char* input) {
    if (strcmp(input, "bmi")) {
        BodyMassIndexCalculator();
        return 1;
    }
    if (strcmp(input, "calories")) {
        CaloriesCalculator();
        return 1;
    }
    if (strcmp(input, "sleep")) {
        SleepCalculator();
        return 1;

    }
    if (strcmp(input, "promille")) {
        AlcPromilleCalculator();
        return 1;
    }

    if (strcmp(input, "rps")) {
        rpsGame();
        return 1;
    }
    return 0;
}