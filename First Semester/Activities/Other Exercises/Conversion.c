#include <stdio.h>

int main()
{
    int num, hours, minutes, seconds;
    printf("PLEASE ENTER NUMBER OF SECOND/S: "); //GETTING THE USER'S INPUT
    scanf("%d", &num); // STORING THE USER'S INPUT

    hours = (num / 3600); //SECONDS TO HOURS
    minutes =  (num / 60) - (hours * 60); //SECONDS TO MINUTES
    seconds =  num - (3600 * hours) - (minutes * 60); //SECONDS

    //PRINTING EVERY OUTPUT
    printf("\n\tHOURS/S: %02d\n", hours);
    printf("\tMINUTE/S: %02d\n", minutes);
    printf("\tSECOND/S: %02d\n", seconds);

    //PRINTING THE PROCESSED OUTPUT
    printf("\n\tTIME: %02d:%02d:%02d\n", hours, minutes, seconds);
    //WE ADD FORMAT SPECIFIER %02 TO ADD ZERO IN EVERY SINGLE DIGIT INTEGER

    return 0;
    
}