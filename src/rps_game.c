#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void ka2(){

    char input[100];
    printf("Tippe Rock, Paper oder Scissors.\n");
    scanf("%s", input);

    srand(time(NULL));

    int zahl = (rand() % 3) + 1; // zufalls zahl zwischen 1-3



    if (zahl == 1) {
        printf("Rock\n");
    }
        else if (zahl == 2) {
            printf("Paper\n");
        }
            else if (zahl == 3) {
                printf("Scissors\n");
            }


    // Gewinn möglichkeiten
    if (strcmp(input, "Paper") == 0 && zahl == 1) {
        printf("du hast gewonnen!\n");
    }
    else if (strcmp(input, "Scissors") == 0 && zahl == 2) {
        printf("du hast gewonnen!\n");
    }
    else if (strcmp(input, "Rock") == 0 && zahl == 3) {
        printf("du hast gewonnen!\n");
    }
    // unentschieden möglichkeiten
    else if (strcmp(input, "Paper") == 0 && zahl == 2) {
        printf("Unentschieden.\n");
    }
    else if (strcmp(input, "Scissors") == 0 && zahl == 3) {
        printf("Unentschieden.\n");
    }
    else if (strcmp(input, "Rock") == 0 && zahl == 1) {
        printf("Unentschieden.\n");
    }

    // Verlier möglichkeiten
    else if (strcmp(input, "Paper") == 0 && zahl == 3) {
        printf("Du hast verloren:(\n");
    }
    else if (strcmp(input, "Scissors") == 0 && zahl == 1) {
        printf("Du hast verloren:(\n");
    }
    else if (strcmp(input, "Rock") == 0 && zahl == 2) {
        printf("Du hast verloren:(\n");
    }
    else {
        printf("Verloren\n");
    }
}