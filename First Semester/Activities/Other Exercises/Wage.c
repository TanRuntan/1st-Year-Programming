#include <stdio.h>

int main()
{
    int hrs, overtimePay, totalPay;
    char name[80];

    printf("Please input the name of the employee: "); //GETTING THE USER'S INPUT
    scanf("%s", name); // STORING THE USER'S INPUT
    printf("Input the hours of %s, worked for this week: ", name); //GETTING THE USER'S INPUT
    scanf("%d", &hrs); // STORING THE USER'S INPUT

    if(hrs <= 40) // IF THE INPUT HOURS IS <= 40
    {
        totalPay = hrs * 10;
        printf("%s, earned a total pay of $%d.00 this week", name, totalPay); //PRINTING THE OUTPUT
    }
    else // IF THE INPUT HOURS IN < 40
    {
        overtimePay = (40 * 10) + ((hrs - 40) * 15);
        printf("%s, earned a total pay of $%d.00 this week", name, overtimePay); //PRINTING THE OUTPUT
    }

    return 0;

}



