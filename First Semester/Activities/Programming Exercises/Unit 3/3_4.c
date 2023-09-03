#include<stdio.h>

/* PROGRAMMING EXERCISE 3-4. A supermarket sells bags of mixed candies. Four types of candies are offered. 
Candy a costs Php. 35.00/kg; Candy B cost Php. 45.00/ kg; candy C cost Php. 56.00/kg and Candy D cost Php. 57.50 kg. 
Write aprogram that will calculate and print the amount of bag of candies in terms of the 
weight of each type of candy as provided by the program user. */

int main()
{
    float kiloA, kiloB, kiloC, kiloD, amtA, amtB, amtC, amtD;

    printf("\n\"CANDY PRICE BY WEIGHT\"");
    printf("\nPlease enter the number of kilos for A: ");
    scanf("%f", &kiloA);
    printf("Please enter the number of kilos for B: ");
    scanf("%f", &kiloB);
    printf("Please enter the number of kilos for C: ");
    scanf("%f", &kiloC);
    printf("Please enter the number of kilos for D: ");
    scanf("%f", &kiloD);

    amtA = kiloA * 35.00;
    printf("\nCandy A cost Php %.02f at %.02f kilogram.", amtA, kiloA);

    amtB = kiloB * 45.00;
    printf("\nCandy B cost Php %.02f at %.02f kilogram.", amtB, kiloB);

    amtC = kiloC * 56.00;
    printf("\nCandy D cost Php %.02f at %.02f kilogram.", amtC, kiloC);

    amtD = kiloD * 57.50;
    printf("\nCandy C cost Php %.02f at %.02f kilogram.", amtD, kiloD);

    printf("\n\nThank you for using my program.");
    
    return 0;
}