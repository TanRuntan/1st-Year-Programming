#include <stdio.h>

// JEDI ACADEMY PROBLEM

// ARRIESGADO
// BUGA-AY
// EDUSMA
// LATAG
// TINGSON
// VILLAS

int main(){
    int rec, height, age, cit;
    char name[80];

    printf("Please enter the name of the applicant: \n");
    scanf("%s", name);
    printf("\nPlease enter the height of the applicant in cm: \n");
    scanf("%d", &height);
    printf("\nPlease enter the age of the applicant: \n");
    scanf("%d", &age);
    printf("\nEnter 1 if the applicant is citizen of the Planet Endor, if not enter 0: \n");
    scanf("%d", &cit);
    printf("\nEnter 1 if the applicant is recommended, if not enter 0: \n");
    scanf("%d", &rec);

    if(rec == 1){
        printf("\n%s is accepted to the Jedi Knight Academy", name);
    }
    else
        if(height >= 200){
            if(age >= 21 && age <= 25){
                if (cit == 1){
                printf("\n%s is accepted to the Jedi Knight Academy", name);
                }
                else{
                printf("\n%s is rejected to the Jedi Knight Academy", name);}
            }
            else{
            printf("\n%s is rejected to the Jedi Knight Academy", name);}  
        }
        else{
        printf("\n%s is rejected to the Jedi Knight Academy", name);}   
        
    return 0;
}

