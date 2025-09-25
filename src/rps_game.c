#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void ka2() {
    char input[100];
    printf("Type rock, paper or scissors\n");
    scanf("%s", input);

    srand(time(NULL));

    int zahl = (rand() % 3) + 1; // zufalls zahl zwischen 1-3



    if (zahl == 1) {
        printf("rock\n");
    }
    else if (zahl == 2) {
        printf("paper\n");
    }
    else if (zahl == 3) {
        printf("scissors\n");
    }


    // Gewinn möglichkeiten
    if (strcmp(input, "paper") == 0 && zahl == 1) {
        printf("YOU WON!!!\n");
    }
    else if (strcmp(input, "scissors") == 0 && zahl == 2) {
        printf("YOU WON!!!\n");
    }
    else if (strcmp(input, "rock") == 0 && zahl == 3) {
        printf("YOU WON!!!\n");
    }
    // unentschieden möglichkeiten
    else if (strcmp(input, "paper") == 0 && zahl == 2) {
        printf("TIE.\n");
    }
    else if (strcmp(input, "scissors") == 0 && zahl == 3) {
        printf("TIE.\n");
    }
    else if (strcmp(input, "rock") == 0 && zahl == 1) {
        printf("TIE.\n");
    }

    // Verlier möglichkeiten
    else if (strcmp(input, "paper") == 0 && zahl == 3) {
        printf("YOU LOST:(\n");
    }
    else if (strcmp(input, "scissors") == 0 && zahl == 1) {
        printf("YOU LOST:(\n");
    }
    else if (strcmp(input, "rock") == 0 && zahl == 2) {
        printf("YOU LOST:(\n");
    }
    else {
        printf("ERROR GAME OVER\n");
    }
}