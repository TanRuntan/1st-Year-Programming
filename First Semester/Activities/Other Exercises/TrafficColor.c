#include<stdio.h>

int main()
{
    char color;

    printf("\nPLEASE INPUT TRAFFIC COLOR: "); //GETTING THE USER'S INPUT
    scanf(" %c", &color); // STORING THE USER'S INPUT

    if (color == 'r' || color == 'R') // IF THE USER INPUT RED
    {
        printf("\n\tSTOP");
    }
    else if(color == 'y' || color == 'Y') // IF THE USER INPUT YELLOW
    {
        printf("\n\tWAIT");
    }
    else if(color == 'g' || color == 'G') // IF THE USER INPUT GREEN
    {
        printf("\n\tGO");
    }
    else
    {
        printf("\n\tInvalid Input");
    }

    printf("\n\nCareful in driving\n");
    printf("Thank you for using my program\n");

    return 0;
}

