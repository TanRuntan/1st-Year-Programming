#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// FINALS GROUP WORK
// BUGA-AY
// PEREZ
// ROSARDA

struct account
{
    char accountNumber[6];
    char accountPin[5];
    float accountBalance;
};

int existingAccounts(FILE *fp, const char *accountNumber)
{
    struct account userAccount;
    fseek(fp, 0, SEEK_SET);

    while (fscanf(fp, "ACCOUNT NUMBER: %5s | PIN NUMBER: %4s | CURRENT BALANCE: %f\n", userAccount.accountNumber, userAccount.accountPin, &userAccount.accountBalance) == 3)
    {
        if (strcmp(userAccount.accountNumber, accountNumber) == 0)
        {
            return 1; 
        }
    }
    return 0; 
}

int existingCount(FILE *fp)
{
    struct account userAccount;

    int count = 0;
    char ch;
    long int currentPosition = ftell(fp);

    while (fscanf(fp, "ACCOUNT NUMBER: %5s | PIN NUMBER: %4s | CURRENT BALANCE: %f\n", userAccount.accountNumber, userAccount.accountPin, &userAccount.accountBalance) == 3)
    {
        count++;
    }

    fseek(fp, currentPosition, SEEK_SET);

    return count;
}

void create_account(FILE *fp)
{
    struct account *create = malloc(sizeof(struct account));

    printf("\n\n\tEnter account number (5 digits): ");
    while (scanf("%5s", create->accountNumber) != 1 || strlen(create->accountNumber) != 5) 
    {
        printf("\n\t\tINVALID NUMBER. \n\t\tPlease enter a valid 5-digit account number: ");
        while (getchar() != '\n')
            continue;
    }

    while (existingAccounts(fp, create->accountNumber))
    {
        printf("\n\t\tACCOUNT NUMBER ALREADY EXISTS. \n\t\tPlease enter a different 5-digit account number: ");
        while (scanf("%5s", create->accountNumber) != 1 || strlen(create->accountNumber) != 5) {
            printf("\n\t\tINVALID NUMBER. \n\t\tPlease enter a valid 5-digit account number: ");
            while (getchar() != '\n')
                continue;
        }
    }

    printf("\n\tEnter 4-PIN number (4 digits): ");
    while (scanf("%4s", create->accountPin) != 1 || strlen(create->accountPin) != 4) 
    {
        printf("\n\t\tINVALID NUMBER. \n\t\tPlease enter a valid 4-digit pin number: ");
        while (getchar() != '\n')
            continue;
    }

    printf("\n\tEnter Balance: ");
    while (scanf("%f", &create->accountBalance) != 1)
    {
        printf("\n\t\tINVALID BALANCE. \n\t\tPlease enter a valid balance: ");
        while (getchar() != '\n')
            continue;
    }

    fprintf(fp, "ACCOUNT NUMBER: %5s | PIN NUMBER: %4s | CURRENT BALANCE: %.2f\n", create->accountNumber, create->accountPin, create->accountBalance);

    printf("\n\t\tACCOUNT INFORMATION SAVED.");

    free(create);
}

int main()
{
    FILE *fp;
    fp = fopen("account.dat", "r+");
    if (fp == NULL)
    {
        fp = fopen("account.dat", "a+");
        if (fp == NULL)
        {
            printf("Failed to create/open the file.");
            return 1;
        }
    }

    int existingRecords = existingCount(fp);

    int i;
    char tryagain;

    printf("\n\t----------------------------");
    printf("\n\tOPENING OF BANK ACCOUNT");
    printf("\n\t----------------------------");

    printf("\n\n\tHow many accounts do you want to create? ");
    while (scanf("%d", &i) != 1 || i <= 0)
    {
        printf("\n\t\tINVALID NUMBER. \n\t\tPlease enter a valid number: ");
        while (getchar() != '\n')
            continue;
    }

    existingRecords += i;

    for (int j = 0; j < i; j++)
    {
        printf("\n\t----------------------------");
        printf("\n\tCREATE ACCOUNT %d", existingRecords - i + j + 1);
        printf("\n\t----------------------------");

        create_account(fp);

        printf("\n\n");
    }

    printf("\t\tThank you.\n\n");
    fclose(fp);
    return 0;
}
