#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 3

struct account
{
    char accountNumber[6];
    char accountPin[5];
    float accountBalance;
};

int main()
{
    FILE *fp;
    fp = fopen("account.dat", "r+");
    if (fp == NULL)
    {
        fp = fopen("account.dat", "w+");
        if (fp == NULL)
        {
            printf("Failed to create/open the file.");
            return 1;
        }
    }

    struct account tocheck;
    int count = 0;

    while (fscanf(fp, "%5s %4s %f\n", tocheck.accountNumber, tocheck.accountPin, &tocheck.accountBalance) == 3)
    {
        count++;
    }

    if (count == MAX_RECORDS)
    {
        printf("\n\t-----------------------------------------------------");
        printf("\n\t  THE [account.dat] IS ALREADY FULL WITH %d RECORDS.", MAX_RECORDS);
        printf("\n\t-----------------------------------------------------\n\n");

        fclose(fp);
        return 0;
    }

    int remaining_records = MAX_RECORDS - count;
    struct account *create = (struct account *)malloc(count * sizeof(struct account));

    printf("\n\t------------------------------");
    printf("\n\tOPENING OF BANK ACCOUNT.");
    printf("\n\t------------------------------\n");

    for (int i = 0; i < count; i++)
    {
        printf("\n\tACCOUNT %d\n", count + i + 1);
  
        printf("\tEnter account number (5 digits): ");
        while (scanf("%s", create[i].accountNumber) != 1 || strlen(create[i].accountNumber) != 5) 
        {
            printf("\n\t\tINVALID ACCOUNT NUMBER. \n\t\tPlease enter a valid 5-digit account number: ");
            while (getchar() != '\n')
                continue;
        }

        printf("\n\tEnter 4-PIN number (4 digits): ");
        while (scanf("%s", create[i].accountPin) != 1 || strlen(create[i].accountPin) != 4) 
        {
            printf("\n\t\tINVALID PIN NUMBER. \n\t\tPlease enter a valid 4-digit pin number: ");
            while (getchar() != '\n')
                continue;
        }

        printf("\n\tEnter Balance: ");
        while(scanf("%f", &create[i].accountBalance) != 1)
        {
            printf("\n\t\tINVALID BALANCE. \n\t\tPlease enter a valid balance: ");
            while (getchar() != '\n')
                continue;
        }

        fprintf(fp, "%5s %4s %f\n", create[i].accountNumber, create[i].accountPin, create[i].accountBalance);
    }

    printf("\n\tACCOUNT INFORMATION SAVED.");
    fclose(fp);

  
    free(create);
    return 0;
}
