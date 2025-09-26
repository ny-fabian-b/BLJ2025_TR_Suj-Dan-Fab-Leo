//
// Created by daniel on 26.09.2025.
//
#include <stdio.h>
#include <string.h>

int main() {
    char eingabe[50];

    printf("Bitte bewerte den Taschenrechner (0-5): ");
    scanf("%49[^\n]", eingabe);  

    if (strcmp(eingabe, "daniel on top") == 0) {
        printf("yh thats true \n");
