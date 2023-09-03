#include<stdio.h>

/* PROGRAMMING EXERCISE 4-1. Write a program that will determine whether a person is a child, a teen-ager 
or an adult using age as input. Assume that a child is from 0 to 12 years old, a teen-ager is from 13 to 19 
and adult is from 20 years old and above. Return ‘C’ from child, ‘T’ for teen-ager and ‘A’ for adult. */

int main(){
    int age; 
    char classification; 
    char name[80]; 
    char ans; 

    do 
    { 
        printf("\n\"AGE GROUP INDENTIFICATION\"");
        printf("\n'C' for Children, 'T' for Teens, 'A' for Adults");

        printf("\n\nPlease enter your name: ");
        scanf("%s", name); 

        printf("Please enter your age: ");
        scanf("%d", &age); 

        if(age >= 0 && age <= 12)
        {
            classification = 'C';
            printf("\n%s, you're a \'%c\'", name, classification);
        }
        if(age >= 13 && age <= 19)
        { 
            classification = 'T';
            printf("\n%s, you're a \'%c\'", name, classification);
        }
        if(age >= 20)
        { 
            classification = 'A';
            printf("\n%s, you're an \'%c\'", name, classification);
        }
        printf("\n\nTry again?\n");
        printf("If YES press 'Y' | If NO press 'N'\n");
        scanf("\n%c", &ans); 
    } while (ans == 'Y' || ans == 'y');  

    printf("\n\nThank you for using my program.");

    return 0; 
}
