#include <stdio.h> 

/* PROGRAMMING EXERCISE 6-2. An integer is considered prime if its only factors are 1 and itself. 
1 can be considered a prime integer because its factors are 1 and only 1. Write a program that will input a 
nonnegative and would call the function prime that returns 0 for true and 1 for false. 
(Precondition: Test if the entered value is nonnegative) */

//BOTTOM-UP APPROACH PROGRAM.
//FUNCTION DEFINITION: TO CHECK IF AN INTEGER IS PRIME OR NOT.
int prime(int n) // FUNCTION PROTOTYPE.
{
    for (int i = 2; i <= n / 2; i++) 
    {
        if (n % i == 0) 
        {
            return 0; // IF n IS DIVISIBLE BY i THEN IT'S NOT A PRIME.
        }
    }
    return 1; // IF n IS NOT DIVISIBLE BY i THEN IT'S A PRIME.
}


int main()
{
    int n; // VARIABLE TO STORE THE NON-NEGATIVE INTEGER.
    char name[80]; // VARIABLE TO STORE THE USERS NAME.

    printf("\n\"PRIME NUMBERS\"");
    printf("\nPlease enter your name: "); // PROMPT THE USER TO ENTER THEIR NAME.
    scanf("%s", name);
    printf("\t%s, please enter a non-negative integer: ", name); // PROMPT THE USER TO ENTER NON-NEGATIVE NUMBER.
    scanf("%d", &n);

    // THIS TEST IF THE USER ENTERED NON-NEGATIVE INTEGER.
    if (n >= 0)
    {
        if (prime(n)) // FUNCTION CALL.
        {
            printf("\nYou have entered \"VALID\" non-negative integer.");
            printf("\n\t And '%d' is a prime number.\n", n);
        }
        else
        {
            printf("\nYou have entered \"VALID\" non-negative integer.");
            printf("\n\tHowever, '%d' is not a prime number.\n", n);
        }
    }
    // THIS TEST IF THE USER ENTERED INVALID NON-NEGATIVE INTEGER.
    else
    {
        printf("\n\tERROR! You have entered \"INVALID\" non-negative integer.\n");
    }

    printf("\nThank you for using my program.");

    return 0;
}

