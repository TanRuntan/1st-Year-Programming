#include <stdio.h>

/* PROGRAMMING EXERCISE 6-5. A Four track stars have entered the mile race at the Penn Relays. 
Write a program that scans in the race time in minutes and seconds for a runner and computes and displays 
the speed in feet per seconds and in meters per seconds. Hint: there are 5280 feet in one mile, and one kilometer equals 3282 feet.
Write and call a function that displays instructions to the program users. */

// BOTTOM-UP APPROACH PROGRAM
// FUNCTION DEFINITION: TO DISPLAY THE PROGRAM INTRODUCTION MESSAGE.
void inst_intro()
{
    printf("\nWELCOME TO THE PENN RELAYS!");
    printf("\n\t*Use this program to determine the speed of each runner in the mile race based on their race time.");
    printf("\n\nLET'S GET STARTED!");
    printf("\n\t*Note: There are 5280 feet in one mile, and one kilometer equals 3282 feet. ");
}

// FUNCTION DEFINITION: TO DISPLAY PROGRAM INSTRUCTION TO ENTER THE NUMBER OF TRACK RACERS.
void inst_racer()
{
    printf("\n\nPlease enter the number of track racers who have entered the mile race: ");
}

// FUNCTION DEFINITION: TO DISPLAY PROGRAM INSTRUCTIONS TO ENTER THE NAMES AND RACE TIME.
void inst_rdata()
{
    printf("\nPlease enter the names and race times in minutes and seconds of the track racers.");
}

int main()
{
    float min, sec, time; // VARIABLE TO STORE THE MINUTES, SECONDS AND TIME IN SECONDS.
    float sfps, smps; // VARIABLE TO STORE THE SPEED IN FEET PER SECONDS AND METERS PER SECOND.
    int num; // VARIABLE TO STORE THE NUMBER OF RACERS.

    inst_intro(); // FUNCTION CALL.

    inst_racer(); // FUNCTION CALL.
    scanf("%d", &num); // PROMPT THE USER TO ENTER THE NAMES AND RACE TIMES OF THE RACERS.
    
    inst_rdata(); // FUNCTION CALL.
    for(int i = 1; i <= num; i++)
    {        
        printf("\nTrack Racer [%d]: ", i);

        char rname[80]; // DECLARE VARIABLE FOR THE RACER'S NAME AND READ IT FROM INPUT.
        scanf("%s", rname);

        printf("\tMinutes: "); // PROMPT THE USER TO INPUT THE MINUTES.
        scanf("%f", &min);
        printf("\tSeconds: "); // PROMPT THE USER TO INPUT THE SECONDS.
        scanf("%f", &sec);

        time = min * 60 + sec; // THIS CONVERT THE TIME TO SECOND.
        sfps = 5280.0 / time; // THIS CALCULATE THE SPEED IN FEET PER SECOND.
        smps = 3282.0 / time; // THIS CALCULATE THE SPEED IN METERS PER SECOND.

        // THIS DISPLAY THE RESULT.
        printf("\nTrack Racer [%d]: %s, obtain the following.\n", i, rname);
        printf("\tSpeed in feet per second: %.2f ft/s\n", sfps);
        printf("\tSpeed in meter per second: %.2f m/s\n", smps);
    }

    printf("\nThank you for using my program.");

    return 0;
}