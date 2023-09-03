#include<stdio.h>

/* PROGRAMMING EXERCISE 3-3. Consider three numbers a, b, and c. 
Write a program that will compute and display their sum, difference, product, quotients (a/ b/ c) and the sum of their squares. */

int main()
{

    int a, b, c, sum, diff, prod, qnt, ssqr;
    char name[80];

    printf("\n\"TRIPLE VALUE COMPUTATIONS\"");
    printf("\nPlease enter your name: ");
    scanf("%s", name);
    printf("\n%s, please enter three numbers: ", name);
    scanf("%d %d %d", &a, &b, &c);

    printf("\n%s, the following answers are as follows.", name);
    
    sum =  a + b + c;
    printf("\nThe sum is equal to %d", sum);
    diff = a - b - c;
    printf("\nThe difference is equal to %d", diff);
    prod = a * b * c;
    printf("\nThe product is equal to %d",prod);
    qnt = a / b / c;
    printf("\nThe quotient is equal to %d", qnt);
    ssqr = ((a * a) + (b * b) + (c * c));
    printf("\nThe sum of their squares is equal to %d", ssqr);

    printf("\n\nThank you for using my program.");

    return 0;

}