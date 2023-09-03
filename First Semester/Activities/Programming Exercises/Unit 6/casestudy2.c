#include<stdio.h>

/* CASE STUDY 2. Write a program to call function TRIANGLE to determine if a given sides is equilateral, isosceles or scalene. 
A triangle is EQUILATERAL if all the three sides have the same length. ISOSCELES if only two sides have the same length and SCALENE if no sides have the same length. 
Input the length of the three sides and print whether the triangle is equilateral, isoscelesor scalene. */

// BOTTOM-UP APPROACH PROGRAM.
// FUNCTION DEFINTION: TO DETERMINE THE TYPE OF TRIANGLE BY ITS SIDES.
void triangle (int a, int b, int c)
{
    if(a == b && b == c) // THIS CHECK IF ALL SIDES HAVE THE SAME LENGTH.
    {
        printf("\n\tThe given sides of a triangle is \"EQUILATERAL\".\n");
    }
    else if (a != b && b != c && c != a) // THIS CHECK IF ALL SIDES HAVE THE SAME LENGTH.
    {
        printf("\n\tThe given sides of a triangle is \"SCALENE\".\n");
    }
    else // THIS CHECK IF ONLY TWO SIDES HAVE THE SAME LENGTH.
    {
        printf("\n\tThe given sides of a triangle is \"ISOSCELES\".\n");
    }
}

int main()
{
    int a, b, c; // VARIABLE TO STORE THE VALUE OF THREE SIDES.
    char name[80]; // VARIABLE TO STORE THE USER'S NAME.

    printf("\n\"TYPE OF TRIANGLES BY SIDES\"");
    printf("\nPlease enter your name: "); // PROMPT THE USER TO ENTER THEIR NAME.
    scanf("%s", name);

    printf("\n%s, please enter the following:", name); // PROMPT THE USER TO ENTER THE VALUE OF THE THREE SIDES.
    printf("\n\tThe first side of the triangle: ");
    scanf("%d", &a);
    printf("\tThe second side of the triangle: ");
    scanf("%d", &b);
    printf("\tThe second side of the triangle: ");
    scanf("%d", &c);

    triangle(a,b,c); // FUNCTION CALL

    printf("\nThank you for using my program.");

    return 0;
}