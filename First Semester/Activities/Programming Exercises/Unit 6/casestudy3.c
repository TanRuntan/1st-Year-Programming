#include<stdio.h>

/* CASE STUDY 3.
- General Program Definition: In military, when one gives a time it is usually in a 24-hour notation (e.g. 1300 means 1:00PM). 
Write a program that converts from 24-hour notation to 12-hour notation using function.

- Input Specifications:The input must be a single integer ranging from 0 to 2400. Any other value must result 
into an input error which the program should display as a message to the user before it halts program execution.

- Output Specifications: Output the time in 12-hour notation using the following format: 1:00 PM using a colon to separate the 
hour part from the minute part and adding the abbreviations AM or PM to indicate what part of the day it is. 
Note that you must observe the 2-digit display. */

// BOTTOM-UP APPROACH PROGRAM.
// FUNCTION DEFINITION: TO CONVERT MILITARY TIME TO STANDARD TIME.
void militarytime (int num)
{
    int hr = num / 100; // THIS EXTRACT HOURS FROM num.
    int min = num % 100; // THIS EXTRACT MINUTES FROM num.
    char time[3] = "";  // INITIALIZE THE ARRAY TO AN EMPTY STING

    if(hr <= 12 ) // THIS CHECK IF HOURS IS LESS THAN OR EQUAL TO 12, THEN IT'S AM
    {
        time[0] = 'A';
        time[1] = 'M';
        if(hr == 0) 
        {
            hr = 12;
        }
    }
    else // THIS CHECK IF HOURS IS GREATER THAN 12, THEN IT'S PM
    {
        time[0] = 'P';
        time[1] = 'M';
        if(hr > 12)
        {
            hr -= 12; // THIS USE TO CONVERT HOUR TO STANDARD TIME FORMAT.
        }
    }

    printf("\n\tStandard Time: %02d:%02d %s\n", hr, min, time);
}

int main()
{
    int num; // VARIABLE TO STORE THE VALUE OF MILITARY TIME.
    char name[80]; // VARIABLE TO STORE THE USER'S NAME.

    printf("\n\"MILITARY TIME TO STANDARD TIME\"");
    printf("\nPlease enter you name: "); // PROMPT THE USER TO ENTER THEIR NAME.
    scanf("%s", name);

    printf("\t%s, please enter a number ranging only from 0 to 2400: ", name); // PROMPT THE USER TO ENTER A VALUE BETWEEN 0 AND 2400.
    scanf("%d", &num);

     // THIS TEST IF THE USER INPUT VALID VALUE BETWEEN 0 TO 2400.
    if(num >= 0 && num <= 2400)
    {
        militarytime(num); // FUNCTION CALL.
    }

    // THIS TEST IF THE USER INPUT INVALID VALUE.
    else
    {
        printf("\n\tERROR! You have entered \"INVALID\" input\n");
    }

    printf("\nThank you for using my program.");

    return 0;
}