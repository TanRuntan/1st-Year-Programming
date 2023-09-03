#include<stdio.h>

/* PROGRAMMING EXERCISE 4-7. Write a program that will input non-negative integer and would 
display the prime factors of the given integer. */

// Example:
// Enter non-negative number: 15
// Prime factors are: 1 3 5 

int main(){
    int num;
    char ans;
    char name[80];

    do 
    {
        printf("\n\"PRIME FACTOR FINDER\"");
        printf("\nPlease enter your name: ");
        scanf("%s", name);
        printf("Please enter non-negative integer: ", name);
        scanf("%d", &num);
        printf("\n%s, the prime factors of %d are: ", name, num);
        for (int i = 2; i <= num; i++)
            while (num % i == 0)
            {
                printf("%d ", i);
                num /= i;
            }

        printf("\n\nDo you want to try again?\n"); 
        printf("If YES press 'Y' | If NO press 'N'\n");
        scanf("\n%c", &ans); 
    } while(ans == 'Y'|| ans == 'y');

    printf("\nThank you for using my program.\n");
    return 0;
}