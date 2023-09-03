#include <stdio.h>

/* PROGRAMMING EXERCISE 3-2. Prepare a program that converts hours to minutes only. 
A typical conversion should write the message 3 hours is equal to 180 minutes. */

int main()
{
    int numhrs, minutes;
    char name[80];

    printf("\n\"LET'S CONVERT HOURS TO MINUTES\"");

    printf("\nPlease enter your name: ");
    scanf("%s", name);
    printf("Please enter number of hours: ");
    scanf("%d", &numhrs);

    minutes = numhrs * 60;
    printf("\n%s, %d hours is equal to %d minutes.", name, numhrs, minutes);

    printf("\n\nThank you for using my program.");

    return 0;
}