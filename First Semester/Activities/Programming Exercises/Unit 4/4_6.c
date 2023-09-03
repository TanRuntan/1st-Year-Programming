#include<stdio.h>

/* PROGRAMMING EXERCISE 4-6. A Video Rental gives a fine to their customers who return the CDs of tape later thanthe due date. 
Input the number of days late and display the fine. */

int main(){
    int days;
    float fine;
    char tape;
    char name[80];

    printf("\n\"VIDEO RENTAL\"");
    printf("\nPlease enter the name of the customer: ");
    scanf("%s", name);

    printf("\nPlease enter the type of tape that %s rented: ", name);
    printf("\nIF CD PRESS 'C' | IF VHS PRESS 'V'\n");
    scanf("\n%c", &tape);

    printf("\nPlease enter the number of days that %s returned the tape late: ", name);
    scanf("%d", &days);

    if(days <= 2){   
        if(tape == 'c'|| tape == 'C'){
            fine = 10;
            printf("\n%s is fine with Php %.2lf for returning the CD %d days late.", name, fine, days);
        }
        else if (tape == 'v' || tape == 'V'){
            fine = 10;
            printf("\n%s is fine with Php%.2lf for returning the VHS %d days late.", name, fine, days);
        }
        else{
            printf("\nSorry, invalid tape");
        }
    }
    else if(days <= 4){
        if(tape == 'c'|| tape == 'C'){
            fine = 15;
            printf("\n%s is fine with Php %.2lf for returning the CD %d days late.", name, fine, days);
        }
        else if (tape == 'v' || tape == 'V'){
            fine = 15;
            printf("\n%s is fine with Php%.2lf for returning the VHS %d days late.", name, fine, days);
        }
        else{
            printf("\nSorry, invalid tape");
        }
    }
    else if(days <= 5){
        if(tape == 'c'|| tape == 'C'){
            fine = 20;
            printf("\n%s is fine with Php %.2lf for returning the CD %d days late.", name, fine, days);
        }
        else if (tape == 'v' || tape == 'V'){
            fine = 20;
            printf("\n%s is fine with Php%.2lf for returning the VHS %d days late.", name, fine, days);
        }
        else{
            printf("\nSorry, invalid tape");
        }
    }
    else{
        if(tape == 'c'|| tape == 'C'){
            fine = 50;
            printf("\n%s is fine with Php %.2lf for returning the CD %d days late.", name, fine, days);
        }
        else if (tape == 'v' || tape == 'V'){
            fine = 35;
            printf("\n%s is fine with Php%.2lf for returning the VHS %d days late.", name, fine, days);
        }
        else{
            printf("\nSorry, invalid tape");
        }
    }

    printf("\n\nThank you for using my program.");

    return 0;
}