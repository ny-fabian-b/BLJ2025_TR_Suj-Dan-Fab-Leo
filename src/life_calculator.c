
// Created by Leonat Idrizi on 24.09.2025.

#include <stdio.h>

int BodyMassIndexCalculator(){
    float gewicht;
    float groesse;

    printf("Please enter your weight in Kg: ");
    if (scanf("%f", &gewicht)!=1) {
        printf("Invalid input");
        return 1;
    }

    printf("Please enter your height in meters (e.g. 1.80): ");
    if (scanf("%f", &groesse)!=1) {
        printf("Invalid input");
        return 1;
    }

    if (groesse <= 0) {
        printf("Height must be greater than 0!\n");
        return 1;
    }

    const float bmi = gewicht / (groesse * groesse);

    printf("Your BMI is: %.2f\n", bmi);

    return 0;
}


int AlcPromilleCalculator() {  //rechnet aus wie viel prozent Alkohol man im Blut gerade hat

    float alkohol;
    float koerpergewicht;
    float reduktionsfaktor;
    float promille;
    char geschlecht;


    printf("Please enter the amount of alcohol you drank in g (One cup has about 10g): ");
    if (scanf("%f", &alkohol)!=1) {
        printf("Invalid input");
        return 1;
    }


    printf("Please enter your bodyweight in Kg: ");
    if (scanf("%f", &koerpergewicht)!=1) {
        printf("Invalid input");
        return 1;
    }

    printf("Please enter your gender: ");
    scanf(" %c", &geschlecht);
    if (geschlecht == 'm'|| geschlecht == 'M') {
        reduktionsfaktor = 0.7;
    }else if (geschlecht == 'f'|| geschlecht == 'F') {
        reduktionsfaktor = 0.6;
    }else{
        printf("Invalid Input please try again");
        return 1;                                               //Fehlercode
    }
    promille = alkohol / (koerpergewicht * reduktionsfaktor);
    printf("Your blood alcohol concentration is: %.2f\n", promille);

    return 0;
}

int SleepCalculator(){//Rechnet aus wann man schlafen sollte wenn man zu einer spezifischen zeit aufstehen möchte und auch wie lange man schlafen will
    int wakeHour;
    int wakeMinute;
    int sleepHour;
    int bedHour;
    int bedMinute;

    printf("Enter The Hour you wish to wake up (0-23): ");
    scanf("%d", &wakeHour);

    printf("Enter The Minute you wish to wake up (0-59): ");
    scanf("%d", &wakeMinute);

    printf("How many hours do you wish to sleep?");
    scanf("%d", &sleepHour);

    bedHour = wakeHour - sleepHour;
    bedMinute = wakeMinute;

    if ( bedHour < 0) {
        bedHour +=24;
    }

    printf("You should go to bed at: %02d:%02d\n", bedHour, bedMinute);

    return 0;
}

int CaloriesCalculator()  {         //Rechnet aus wie viel Kalorien der Körper tägich automatisch verliert
    float weight;
    float height;
    float bmr;
    int age;
    char gender;

    printf("Please enter your weight in kg: ");
    scanf("%f", &weight);

    printf("Please enter your height in centimeters (e.g. 180): ");
    scanf("%f", &height);

    printf("Please enter your age: ");
    scanf("%d", &age);

    printf("Please enter your gender: ");
    scanf(" %c", &gender);

    if (gender == 'm'|| gender == 'M') {
        bmr = 66.47 + (13.7 * weight) + (5.0 * height) - (6.8 * age);
    }else if (gender == 'f'|| gender == 'F') {
        bmr = 665.1 + (9.65 * weight) + (1.8 * height) - (4.7 * age);
    } else {
        printf("Invalid Input please try again");
        return 1;
    }

    printf("Your daily basal metabolic rate(BMR) is: %.2f calories", bmr);

    return 0;
}