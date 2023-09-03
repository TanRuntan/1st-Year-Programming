#include<stdio.h>

/* CASE STUDY 3. Write a program that will input non-negative integer and call a function DWARF to determine if the integer is DWARF or NOT. 
An integer is said to be DWARF if the sum of its factors is greater than the half of the number. */

// Example:
// Input number: 6
// Factors are: 1 2 3
// Sum of its factor: 1 +2 + 3 =6
// Half of the number : 6 /2 = 3
// 6 is DWARF

int main(){
    int num, half, org_num;
    int sum;
    char ans;
    char name[80];

    do
    {
        printf("\n\"DWARF OR NOT?\"");
        printf("\nPlease enter your name: ");
        scanf("%s", name);
        printf("Please enter non-negative number: ", name);
        scanf("%d", &org_num);

        sum = 0;
        printf("\n%s, the answers to the following are as follows.", name);
        num = org_num;
        printf("\nThe prime factors of %d are: ", num);
           for(int i = 1; i <= num; i++){
                if(num % i == 0)
                {
                    printf("%d ", i);
                    sum += i;
                    num = org_num / i;
                }
            }
        half = org_num / 2;
        printf("\nThe sum of its factors is %d", sum); 
        printf("\nThe half of %d is %d", org_num, half);

            if(sum > half)
                printf("\nTherefore, %d is DWARF", org_num);
            else
                printf("\nTherefore, %d is NOT DWARF", org_num);
    
        printf("\n\nDo you want to try again?\n"); 
        printf("If YES press 'Y' | If NO press 'N'\n");
        scanf("\n%c", &ans); 
    } while(ans == 'Y'|| ans == 'y');

    printf("\n\nThank you for using my program.\n");

    return 0;

}



