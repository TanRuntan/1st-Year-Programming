#include<stdio.h>
#define START 200 // DEFINING A CONSTANT 'START'.
#define FINISH 500 // DEFINING A CONSTANT 'FINISH'.

/* PROGRAMMING EXERCISE 6-4. Afamous conjecture, called the GOLDBACH conjecture, says that every even integer n greater than 2 has the property tat it is the sum of two prime numbers. 
Computers have been used extensively to test this conjecture. No counter example has been found. 
Write a program the will prove that the conjecture is true for all the even integers between the symbolic constants START and FINISH. */

// TOP-DOWN APPROACH PROGRAM.
int main()
{
    int goldbach_prime(int n); // FUNCTION PROTOTYPE.

    printf("\nEvery even number greater than 2 is the sum of two primes:\n");
    for(int i = START; i <= FINISH; i += 2) // THIS CHECKS IF THE SUM OF THE TWO PRIME NUMBERS IS EQUAL TO i.
    {
        int found = 0;
        for(int j = 2; j <= i / 2; j++) 
        {
            if(goldbach_prime(j) && goldbach_prime(i - j)) // FUNCTION CALL: IF j AND i-j BOTH ARE PRIME NUMBERS THEN PRINT THEM AS THE SUM OF TWO PRIME NUMBERS.
            {
                printf("\n\t%02d \t= \t%02d \t+ \t%02d", i, j, i - j);
                found = 1; // IF THE SUM OF THE TWO PRIMES ARE EQUAL TO i, THEN FOUND IS SET TO 1.
                break;
            }
        }
        if(!found) // IF THERE ARE NO TWO PRIME NUMBERS WHICH SUM UP TO i, THEN FOUND IS NOT SET TO 1.
        {
            printf("\nThere is no two primes that sum up %d", i);
        }
    }

    printf("\n\nThank you for using my program.");

    return 0;
}

// FUNCTION DEFINITION: TO CHECK IF A NUMBER IS PRIME OR NOT.
int goldbach_prime(int n)
{
    for (int i = 2; i <= n - 1; i++) 
    {
        if (n % i == 0)  
        {
            return 0; // IF n IS DIVISIBLE BY i THEN IT'S NOT A PRIME.
        }
    }
    return 1; // IF n IS NOT DIVISIBLE BY i THEN IT'S A PRIME.
}