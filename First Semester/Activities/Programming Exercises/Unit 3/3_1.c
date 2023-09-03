#include<stdio.h>

/* PROGRAMMING EXERCISE 3-1. The volume of a rectangular box is given by the formula, V=length * width * height. 
Design a program that will calculate and display the volume of a box whose dimensions are specified by the user. */

int main()
{
    int l, w, h, v;
    char name[80];
 
    printf("\n\"VOLUME OF A RECTANGULAR BOX\"");

    printf("\nPlease enter your name: ");
    scanf("%s", name);

    printf("\nPlease enter the following.");
    printf("\nLENGTH:\t");
    scanf("%d", &l);

    printf("WIDTH:\t");
    scanf("%d", &w);

    printf("HEIGHT:\t");
    scanf("%d", &h);

    v =  l * w * h;
    printf("\n%s, the volume of the box is equal to %d", name, v);

    printf("\n\nThank you for using my program.");
    
    return 0;
}