#include<stdio.h>

/* CASE STUDY 1. Write a program that accepts a positive integer and gives its prime factorization, 
that expresses the integer as a product ofprimes. */

int main(){
    int num;
    char ans;
    char name[80];

    do 
    {
        printf("\n\"PRIME FACTORIZATION PROGRAM\"");
        printf("\nPlease enter your name: ");
        scanf("%s", name);
        printf("Please enter a positive integer: ", name);
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