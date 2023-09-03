#include <stdio.h>

int main(){

    int a, b, c; 
    // EXECUTING THREE INTEGER VARIABLES TO STORE THE THREE DIFFERENT INTEGERS

    printf("Please input three different integers: \n"); // GETTING THE USER'S INPUT
    scanf("%d %d %d", &a, &b, &c); // STORING TH USER'S INPUT

    // USING MULTIWAY/ IF-ELSE SELECTION
    if(a > b && a > c)
        printf("\n%d is the largest number", a); 
        // THIS WILL EXECUTE IF A (THE FIRST NUMBER) IS THE LARGEST NUMBER
    else if (b > c && b > a)
        printf("\n%d is the largest number", b); 
        // THIS WILL EXECUTE IF B (THE SECOND NUMBER) IS THE LARGEST NUMBER
    else
        printf("\n%d is the largest number", c); 
        // THIS WILL EXECUTE IF C (THE THIRD NUMBER) IS THE LARGEST NUMBER
    
    printf("\nThank you!\n");  // NEXT STATEMENT

    return 0;

}
