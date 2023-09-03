#include<stdio.h>

/* PROGRAMMING EXERCISE 6-1. N factorial can be define as the product of all integer from 1 to N and it is denoted by the symbol N!.0! (zero factorial) is defined a 1. 
Write a program that will input N and would call the function factorial that will return N factorial. (Determine first if N is a nonnegative integer). */

// BOTTOM-UP APPROACH PROGRAM.
// FUNCTION DEFINITION: CALCULATES THE FACTORIAL OF AN NON-NEGATIVE INTEGER n.
unsigned long long factorial(int n) // FUNCTION PROTOTYPE: USES AN UNSIGNED LONG LONG DATA TYPE TO STORE AN INTEGER FROM 0 TO 18 QUINTILLION.
{
    unsigned long long result = 1;
    for(int i = 1; i <= n; i++)
        result *= i; // THIS MULTIPLY EACH INTEGER FROM 1 TO n TOGETHER.

    return result;

}

int main()
{
    int n; // VARIABLE TO STORE THE NON-NEGATIVE INTEGER.
    char name[80]; // VARIABLE TO STORE THE USERS NAME.

    printf("\n\"N FACTORIAL\"");
    printf("\nPlease enter your name: "); // PROMPT THE USER TO ENTER THEIR NAME.
    scanf("%s", name);
    printf("\t%s, please enter non-negative integer: ", name); // PROMPT THE USER TO ENTER A NON-NEGATIVE INTEGER.
    scanf("%d", &n);

    // THIS TEST IF THE USER ENTERED NON-NEGATIVE INTEGER.
    if(n >= 0)
    {
        unsigned long long x = factorial(n); // FUNCTION CALL
        printf("\nYou have entered \"VALID\" non-negative integer.");
        printf("\n\tAnd '%d' factorial (%d!) is define a %llu.", n, n, x);
        // *THE FACTORIAL OF LARGER INTEGERS CAN QUICKLY BECOME VERY LARGE SO UNSIGNED LONG LONG IS APPROPRIATE DATA TYPE.
    }
    // THIS TEST IF THE USER ENTERED NON-NEGATIVE INTEGER.
    else
    {
        printf("\n\tERROR! You have entered \"INVALID\" non-negative integer.");
    }

    printf("\n\nThank you for using my program.");

    return 0;
}
