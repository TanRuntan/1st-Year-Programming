#include<stdio.h>

/* PROGRAMMING EXERCISE 6-6.Two positive integers i and j are considered to be relatively prime if 
there exist no integer greater than 1 that divides them both. Write a function rel_prime that has two input parameters, I and j, 
and returns a value of 1 if and only if I and j are relatively prime. Otherwise, rel_prime should return a value of 0. */

// BOTTOM-UP APPROACH PROGRAM.
// FUNCTION DEFINITION: TO CHECK IF TWO INTEGERS ARE RELATIVELY PRIME.
int rel_prime (int num1, int num2) // FUNCTION PROTOTYPE.
{
    int divisor = 1; // THIS INITIALIZE DIVISOR TO 1.
    for(int i = 2; i <= num1 && i <= num2; i++)
    {
        // THIS CHECKS IF BOTH NUMBERS ARE DIVISIBLE BY i, SET DIVISOR TO i AND EXIT THE LOOP.
        if(num1 % i == 0 && num2 % i == 0)
        {
            divisor = i;
            break;
        }
        
    }

    if(divisor == 1)
    {
        return 1; // IF THERE IS NO SAME DIVISOR OTHER THAN 1.
    }
    return 0; // IF THERE IS ANOTHER SAME DIVISIOR FOUND.
}

int main()
{
    int i, j; // VARIABLE TO STORE TWO POSITIVE INTEGERS.
    char name[80]; // VARIABLE TO STORE USERS NAME.

    printf("\n\"RELATIVELY PRIME\"");
    printf("\nPlease enter your name: "); // PROMPT THE USER TO ENTER THEIR NAME.
    scanf("%s", name);
    printf("%s, please enter the following", name); // PROMPT THE USER TO ENTER TWO POSITIVE INTEGER.
    printf("\n\tThe first positive integer: ");
    scanf("%d", &i);
    printf("\tThe second positive integer: ");
    scanf("%d", &j);

    // THIS TEST IF THE USER ENTERED TWO POSITIVE INTEGER.
    if(i >= 0 && j >= 0)
    {
        if(rel_prime(i,j)) // FUNCTION CALL.
        {
            printf("\nYou have entered \"VALID\" positive integer."); // TO CHECK IF THE USER INPUT VALID POSITIVE INTEGER.
            printf("\n\tAnd '%d' and '%d' are relatively prime.\n", i, j);
        }
        else
        {
            printf("\nYou have entered \"VALID\" positive integer."); // TO CHECK IF THE USER INPUT VALID POSITIVE INTEGER.
            printf("\n\tHowever, '%d' and '%d' are not relatively prime.\n", i, j);
        }
    }
    // THIS TEST IF THE USER ENTERED INAVLID TWO POSITIVE INTEGER.
    else
    {
        printf("\n\tERROR! You have entered \"INVALID\" positive integer.\n");
    }

    printf("\nThank you for using my program.");

    return 0;
}