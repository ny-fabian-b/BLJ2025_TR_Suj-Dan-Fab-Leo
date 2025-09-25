
// Created by Leonat Idrizi on 24.09.2025.

#include <stdio.h>

int BodyMassIndexCalculator() {
    float gewicht, groesse, bmi;

    printf("Please enter your weight in Kg: ");
    scanf("%f", &gewicht);

    printf("Please enter your height in meters (0.00): ");
    scanf("%f", &groesse);

    if (groesse <= 0) {
        printf("Height must be greater than 0!\n");
        return 1;
    }

    bmi = gewicht / (groesse * groesse);

    printf("Your BMI is: %.2f\n", bmi);

    return 0;
}


int AlcPromilleCalculator() {

    float alkohol, koerpergewicht, reduktionsfaktor, promille;
    char geschlecht;


    printf("Please enter the amount of alcohol you drank in g: ");
    scanf("%f", &alkohol);

    printf("Please enter your bodyweight in Kg: ");
    scanf("%f", &koerpergewicht );

    printf("Please enter your gender: ");
    scanf("%c", &geschlecht);
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

int SleepCalculator() {
    int wakeHour, wakeMinute;
    int sleepHour;
    int bedHour, bedMinute;

    printf("Enter your wake up hour (0-23): ");
    scanf("%d", &wakeHour);

    printf("Enter your wake up minute (0-59): ");
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

int CaloriesCalculator() {
    float weight, height, bmr;
    int age;
    char gender;

    printf("Please enter your weight in kg: ");
    scanf("%f", &weight);

    printf("Please enter your height in meters (0.00): ");
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

    printf("Your daily basal metabolic rate(BMR) is: %.2f calories")






}