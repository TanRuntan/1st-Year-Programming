#include<stdio.h>

/* CASE STUDY 1. The proper divisor of an integer N are the positive divisors less than N, a positive integer is said to be 
DEFICIENT, PERFECT or ABUNDANT numbers if the sum of its proper divisors is less than, equal to or greater than the number respectively. 
Write a program using function call by reference to input integer N andcall function KOMPUTE to determine of integer N is DEFICIENT, PERFECT or ABUNDANT . */

// BOTTOM-UP APPROACH
// FUNCTION DEFINITION:TO COMPUTE AND DETERMINE IF THE INTEGER IS DEFICIENT, PERFECT, OR ABUNDANT.
void kompute(int n, char *result)
{
    int sum = 0; // THIS INITIALIZE THE SUM VARIABLE TO 0.
    printf("\nProper divisors of %d are: ", n);
    for (int i = 1; i < n; i++) // USE FOR LOOP TO FINE THE PROPER DIVISORS.
    {
        if ( n % i == 0) // THIS CHECKS IF i IS A DIVISOR OF n.
        {
            printf("%d,", i);
            sum += i; // THIS ADDS ALL THE PROPER DIVISOR TO SUM.
        }
    }  
    printf("\nThe sum of the proper divisor is %d", sum);

    if(sum < n) // THIS CHECK IF THE SUM OF PROPER DIVISORS IS LESS THAN n.
    {
        *result = 'D'; // SET RESULT TO DEFICIENT.
    }
    else if(sum == n) // THIS CHECK IF THE SUM OF PROPER DIVISORS IS EQUAL TO n.
    {
        *result = 'P'; // SET RESULT TO PERFECT.
    }
    else if(sum > n) // THIS CHECK IF THE SUM OF PROPER DIVISORS IS GREATER THAN n.
    {
        *result = 'A'; // SET RESULT TO ABUNDANT.
    }
}

int main(){

    int n; // VARIABLE TO STORE A POSITIVE INTEGER. 
    char result, name[80]; // VARIABLE TO STORE THE RESULT AND USER'S NAME.

    printf("\n\"DEFICIENT, PERFECT, ABUNDANT\"");

    printf("\nPlease enter your name: "); // PROMPT THE USER TO ENTER THEIR NAME.
    scanf("%s", name);

    printf("\t%s, please enter a positive integer: ", name); // PROMPT THE USER TO ENTER A POSITIVE INTEGER.
    scanf("%d", &n);

    // THIS TEST IF THE USER INPUT VALID POSITIVE INTEGER.
    if(n >= 0)
    {
        kompute(n, &result); // FUNCTION CALL.

        switch(result) // THIS USES SWITCH TO DETERMINE THE RESULT AND PRINT APPROPRIATE MESSAGE.
        {
            case 'D':
                printf("\n\tTherefore '%d' is \"DEFICIENT\" number.", n);
                break;
            case 'P':
                printf("\n\tTherefore '%d' is \"PERFECT\" number.", n);
                break;
            case 'A':
                printf("\n\tTherefore '%d' is \"ABUNDANT\" number.", n);
                break;
        }
    
    // THIS TEST IF THE USER INPUT AN INVALID POSITIVE INTEGER.
    }
    else
    {
        printf("\n\tERROR! You have entered \"INVALID\" positive integer.");
    }

    printf("\n\nThank you for using my program.");

    return 0;
}


