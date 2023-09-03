#include<stdio.h>

/* PROGRAMMING EXERCISE 3-5. Hypothetically speaking, on Mars a 100-pound person on Earth would weigh 38 pounds. 
On Jupiter, the same person weight is 264 pounds. Write a program that will input the weight of a person in pound 
on Earth and displays the corresponding weight when the man is on Mars and on Jupiter. */

int main()
{
    double wgt, wgtJ, wgtM;
    char name[80];

    printf("\n\"KNOW YOUR WEIGHT ON THE OTHER WORLDS\"");
    printf("\nPlease enter your name: ");
    scanf("%s", name);
    printf("%s, please enter your weight in pounds: ", name);
    scanf("%lf", &wgt);

    wgtM = wgt * 0.38;
    printf("\n%s, your weight on Mars is %0.2lf pounds", name, wgtM);
    wgtJ = wgt * 2.64;
    printf("\n%s, your weight on Jupiter is %0.2lf pounds", name, wgtJ);

    printf("\n\nThank you for using my program.");

    return 0;

}