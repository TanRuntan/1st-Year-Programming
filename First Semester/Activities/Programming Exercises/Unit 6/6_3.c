#include<stdio.h>

/* PROGRAMMING EXERCISE 6-3. Write a function int is_prime(int n) that returns 1 if n is prime and 0 otherwise. 
Hint: if k and n are positive integer, then k divides n if and only if n % k has value 0. */

//BOTTOM-UP APPROACH PROGRAM.
// FUNCTION DEFINITION: TO CHECK IF AN INTEGER IS PRIME OR NOT.
int is_prime(int n) // FUNCTION PROTOTYPE.
{
    for (int k = 2; k <= n / 2; k++) 
    {
        if (n % k == 0) 
        {
            return 0; // IF n IS DIVISIBLE BY k THEN IT'S NOT A PRIME.
        }
    }
    return 1; // IF n IS NOT DIVISIBLE BY k THEN IT'S A PRIME.
}


int main()
{
    int n; // VARIABLE TO STORE THE NON-NEGATIVE INTEGER.
    char name[80]; // VARIABLE TO STORE THE USERS NAME.

    printf("\n\"IS IT A PRIME NUMBER?\"");
    printf("\nPlease enter your name: "); // PROMPT THE USER TO ENTER THEIR NAME.
    scanf("%s", name);
    printf("\t%s, please enter a non-negative integer: ", name); // PROMPT THE USER TO ENTER NON-NEGATIVE NUMBER.
    scanf("%d", &n);

    if (is_prime(n)) // FUNCTION CALL.
    {
        printf("\nYou have entered \"VALID\" non-negative integer.");
        printf("\n\t And '%d' is a prime number.", n);
    }
    else
    {
        printf("\nYou have entered \"VALID\" non-negative integer.");
        printf("\n\tHowever, '%d' is not a prime number.\n", n);
    }

    printf("\n\nThank you for using my program.");

    return 0;
}