#include <stdio.h>

/* PROGRAMMING EXERCISE 4-5. Assume a range of integer values starting from N1 and ending at N2. 
Assume also an integer say M. Write a program that will print and display all the numbers from N1 to N2 which are divisible by M. 
You are also required display the count of such numbers. For example, if N1 = 4, N2 = 12 and M = 4, the output will be: 4, 8, 12. 
The value 3 will also be displayed indicating that there are 3 numbers which are divisible by 4. */

int main(){
    int n1, n2, m;
    int total;
    char ans;
    char name[80];

    do
    { 
        printf("\n\"DIVISIBLE NUMBERS COUNT\"");
        printf("\nPlease enter your name: ");
        scanf("%s", name);

        printf("Please enter the starting integer (N1): ");
        scanf("%d", &n1);

        printf("Please enter the ending integer (N2): ");
        scanf("%d", &n2);

        printf("Please enter the integer to divide by (M): ");
        scanf("%d", &m);

        total = 0;
        printf("\n%s, the numbers from N1 to N2 that are divisible by M are: ", name);
        for (int i = n1; i <= n2; i++) 
        {
            if (i % m == 0) 
            {
                printf("%d, ", i);
                total++;
            }
        }
    
        printf("\nAlso there are %d numbers in the range that are divisible by M.\n", total);

        printf("\nTry again?\n"); 
        printf("If YES press 'Y' | If NO press 'N'\n");
        scanf("\n%c", &ans); 
        } while (ans == 'Y' || ans == 'y');  
    
    printf("\n\nThank you for using my program.");

    return 0;
}
