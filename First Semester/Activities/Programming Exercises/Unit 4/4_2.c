#include<stdio.h>
#define PI 3.14159

/* PROGRAMMING EXERCISE 4-2. Pizza parlors offers different pizza sizes in terms of diameters. 
For example, Domino’s has three options: 10 inches, 12 inches, 14 inches diameter. 
Extravaganza pizza costing 178 pesos, 259 pesos and 314 pesos respectively. 
Write a program that will input the diameter of the pizza, and its price. 
Determine the (a) area of the pizza and (b) the price by the divided area. 
Find out which of thethree options above (for Domino’s) is the least expensive in terms of price per square inch of pizza. 
Note that the area of a circle is equivalent to PI* (diameter / 2)2. */

int main(){
    int diameter;
    float price, price_psquare, area;
    char name[80];
    char ans;

    do
    {
        printf("\n\"PIZZA PRICE COMPARISON\"");
        printf("\nPlease enter the name of the pizza: ");
        scanf("%s", name);

        printf("Please enter the diameter of the piza: ");
        scanf("%d", &diameter);

        printf("Please enter the price of the pizza: ");
        scanf("%f", &price);

        area = PI * (diameter / 2) * (diameter / 2);
        printf("\nThe area of %s pizza is %.2f", name, area);
        price_psquare = price / area;
        printf("\nThe price of %s pizza in %.2f per square inches is Php %.2f", name, area, price_psquare);

        printf("\n\nTry again?\n");
        printf("If YES press 'Y' | If NO press 'N'\n");
        scanf("\n%c", &ans);
    } while (ans == 'Y' || ans == 'y');

    printf("\n\nThank you for using my program.");

    return 0;
}
