#include <stdio.h>

/* PROGRAMMING EXERCISE 4-3. Write a program that would input 3 integers and would output them in descending order. */

int main()
{
    int a, b, c;
    int num_inputs;
    char ans;
    char name[80];

    do 
    {
        printf("\n\"SORTING THREE INTEGERS IN DESCENDING ORDER\"");
        printf("\nPlease enter your name: ");
        scanf("%s", name); 
        printf("Please enter three integers numbers: ");
        num_inputs = scanf("%d %d %d", &a, &b, &c);

        if (num_inputs == 3) {
            if (a >= b && a >= c) {
                printf("%s, the integers in descending order are %d, %d, %d", name, a, b >= c ? b : c, b >= c ? c : b);
            }
            else if (b >= a && b >= c) {
                printf("%s, the integers in descending order are %d, %d, %d", name, b, a >= c ? a : c, a >= c ? c : a);
            }
            else if (c >= a && c >= b) {
                printf("%s, the integers in descending order are %d, %d, %d", name, c, a >= b ? a : b, a >= b ? b : a);
            }
        }
        else{
            printf("\nSorry, invalid input");
        }
    printf("\n\nDo you want to try again?\n"); 
    printf("If YES press 'Y' | If NO press 'N'\n");
    scanf("\n%c", &ans); 
    } while(ans == 'Y'|| ans == 'y');

    printf("Thank you for using my program.");
    
    return 0;
}

