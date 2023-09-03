#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
        printf("Failed to create/open the file.");
        return 1;
    }

    struct account userAccount;
    char inputAccountNumber[6];
    char inputPin[5];
    int found = 0;
    long int accountPosition = 0;

    system("cls");

    printf("\n\t------------------------------------------");
    printf("\n\t  Sign-in to PUP-On-Line Banking Systems");
    printf("\n\t------------------------------------------\n");

    while (!found ) 
    {
        printf("\n\tEnter account number: ");
        scanf("%s", inputAccountNumber);

        fseek(fp, 0, SEEK_SET);

        accountPosition = ftell(fp);

        while (fscanf(fp, "ACCOUNT NUMBER: %5s | PIN NUMBER: %4s | CURRENT BALANCE: %f\n\n", userAccount.accountNumber, userAccount.accountPin, &userAccount.accountBalance) == 3)
        {
            if (strcmp(inputAccountNumber, userAccount.accountNumber) == 0)
            {
                int attempts = 3;
                while (attempts > 0)
                {
                    printf("\tEnter 4-PIN number: ");
                    scanf("%s", inputPin);
                    getchar();

                    if (strcmp(inputPin, userAccount.accountPin) == 0)
                    {
                        int choice;
                        int confirm;
                        int exit = 0;
                        
                        do
                        {     
                               
                            printf("\n\t------------------------------------------");
                            printf("\n\t  Welcome to PUP-On-Line Banking Systems");
                            printf("\n\t------------------------------------------\n");

                            printf("\n\tLogin Successful!\n");
                            printf("\n\t1. Balance Inquiry");
                            printf("\n\t2. Deposit");
                            printf("\n\t3. Withdraw");
                            printf("\n\t4. Delete Account");
                            printf("\n\t5. Exit");

                            printf("\n\n\tPress the number of your choice: ");
                            scanf("%d", &choice);

                            system("cls");

                            switch (choice)
                            {
                                case 1:
                                    system("cls");

                                    printf("\n\t----------------------------"); 
                                    printf("\n\t1. BALANCE INQUIRY");
                                    printf("\n\t----------------------------");

                                    do
                                    {
                                        printf("\n\tYour current balance: %.2f\n", userAccount.accountBalance);
                                
                                        printf("\n\t\tDo you want to go back to the main menu (Y | N)?: ");
						                scanf(" %c", &confirm);
						                while(getchar() != '\n')
							                continue;
                                    } while(confirm == 'N' || confirm == 'n');
                                    break;
                                
                                case 2:
                                    system("cls");

                                    printf("\n\t----------------------------"); 
                                    printf("\n\t2. DEPOSIT");
                                    printf("\n\t----------------------------");

    
                                    do
                                    {
                                        printf("\n\tEnter the amount to deposit: ");
                                        float depositAmount;
                                        scanf("%f", &depositAmount);
                                        if (depositAmount > 0)
                                        {
                                            userAccount.accountBalance += depositAmount;
                                            fseek(fp, accountPosition, SEEK_SET);
                                            fprintf(fp, "ACCOUNT NUMBER: %5s | PIN NUMBER: %4s | CURRENT BALANCE: %.2f\n\n", userAccount.accountNumber, userAccount.accountPin, userAccount.accountBalance);
                                            fflush(fp);
                                            printf("\n\t\tDEPOSIT SUCCESSFUL. \n\t\tYour new balance: %.2f\n", userAccount.accountBalance);

                                            FILE *appendFp = fopen("account.dat", "a+");
                                            if (appendFp != NULL)
                                            {
                                                time_t t;
                                                struct tm *td_info;
                                                time(&t);
                                                td_info = localtime(&t);
                                                char date_str[11];
                                                strftime(date_str, 11, "%Y-%m-%d", td_info);
                                                char time_str[12];
                                                strftime(time_str, 12, "%I:%M:%S %p", td_info);

                                                fprintf(appendFp, "HISTORY: ACCOUNT NUMBER: %s | PIN NUMBER: %s | DEPOSIT %.2f | BALANCE: %.2f | TRANSACTION DATE: %s | TRANSACTION TIME: %s\n",
                                                        userAccount.accountNumber, userAccount.accountPin, depositAmount, userAccount.accountBalance, date_str, time_str);
                                                fclose(appendFp);
                                            }
                                            else
                                            {
                                                printf("Failed to open the file for appending.\n");
                                            }
                                        }
                                        else
                                        {
                                            printf("\n\t\tDEPOSIT FAILED. \n\t\tInvalid deposit amount.\n");
                                        }

                                            printf("\n\t\tDo you want to deposit again (Y | N)?: ");
                                            scanf(" %c", &confirm);
                                            while(getchar() != '\n')
                                                continue;
                                        }while (confirm == 'Y' || confirm == 'y');
                                    break;


                                case 3:
                                    system("cls");

                                    printf("\n\t----------------------------"); 
                                    printf("\n\t3. WITHDRAW");
                                    printf("\n\t----------------------------");

                                    do
                                    {
                                        printf("\n\tEnter the amount to withdraw: ");
                                        float withdrawAmount;
                                        scanf("%f", &withdrawAmount);
                                        if (withdrawAmount > 0 && withdrawAmount <= userAccount.accountBalance)
                                        {
                                            userAccount.accountBalance -= withdrawAmount;
                                            fseek(fp, accountPosition, SEEK_SET);
                                            fprintf(fp, "ACCOUNT NUMBER: %5s | PIN NUMBER: %4s | CURRENT BALANCE: %.2f\n\n", userAccount.accountNumber, userAccount.accountPin, userAccount.accountBalance);
                                            fflush(fp);
                                            printf("\n\t\tWITHDRAWAL SUCCESSFUL. \n\t\tYour new balance: %.2f\n", userAccount.accountBalance);
                                        
                                            FILE *appendFp = fopen("account.dat", "a+");
                                            if (appendFp != NULL)
                                            {
                                                time_t t;
                                                struct tm *td_info;
                                                time(&t);
                                                td_info = localtime(&t);
                                                char date_str[11];
                                                strftime(date_str, 11, "%Y-%m-%d", td_info);
                                                char time_str[12];
                                                strftime(time_str, 12, "%I:%M:%S %p", td_info);

                                                fprintf(appendFp, "HISTORY: ACCOUNT NUMBER: %5s | PIN NUMBER: %4s | WITHDRAW %.2f | BALANCE: %.2f | TRANSACTION DATE: %s | TRANSACTION TIME: %s\n",
                                                        userAccount.accountNumber, userAccount.accountPin, withdrawAmount, userAccount.accountBalance, date_str, time_str);
                                                fclose(appendFp);
                                            }
                                            else
                                            {
                                                printf("Failed to open the file for appending.\n");
                                            }
                                        }
                                        else
                                        {
                                            printf("\n\t\tWITHDRAWAL FAILED. \n\t\tYou have insufficient balance: %.2f\n", userAccount.accountBalance);
                                        }
                            
                                        printf("\n\t\tDo you want to withdraw again (Y | N)?: ");
						                scanf(" %c", &confirm);
						                while(getchar() != '\n')
							                continue;
                                    } while (confirm == 'Y' || confirm == 'y');
                                    break;
                                
                                case 4:
                                    system("cls");

                                    printf("\n\t----------------------------"); 
                                    printf("\n\t4. DELETE ACCOUNT");
                                    printf("\n\t----------------------------");

                                    printf("\n\tAre you sure you want to delete this account? (Y/N): ");
                                    char confirmation;
                                    scanf(" %c", &confirmation);

                                    if (confirmation == 'Y' || confirmation == 'y')
                                    {
                                        
                                        fclose(fp);

                                        FILE *tempFp = fopen("temp.dat", "w");
                                        if (tempFp == NULL)
                                        {
                                            printf("Failed to create a temporary file for account deletion.\n");
                                            break;
                                        }

                                        fseek(fp, 0, SEEK_SET);
                                        while (fscanf(fp, "ACCOUNT NUMBER: %5s | PIN NUMBER: %4s | CURRENT BALANCE: %f\n\n", userAccount.accountNumber, userAccount.accountPin, &userAccount.accountBalance) == 3)
                                        {
                                            if (strcmp(inputAccountNumber, userAccount.accountNumber) != 0)
                                            {
                                                fprintf(tempFp, "ACCOUNT NUMBER: %5s | PIN NUMBER: %4s | CURRENT BALANCE: %.2f\n\n", userAccount.accountNumber, userAccount.accountPin, userAccount.accountBalance);
                                            }
                                        }

                                        FILE *transactionFp = fopen("account.dat", "r");

                                        if (transactionFp == NULL)
                                        {
                                            printf("Failed to open the transaction file.\n");
                                            fclose(tempFp);
                                            break;
                                        }

                                        char line[160];
                                        while (fgets(line, sizeof(line), transactionFp) != NULL)
                                        {
                                            if (strstr(line, inputAccountNumber) == NULL)
                                            {
                                                fprintf(tempFp, "%s", line);
                                            }
                                        }

                                        fclose(transactionFp);
                                        fclose(tempFp);

                                        fclose(fp);

                                        if (remove("account.dat") != 0)
                                        {
                                            printf("Failed to delete the account. Please try again later.\n");
                                            break;
                                        }

                                        if (rename("temp.dat", "account.dat") != 0)
                                        {
                                            printf("Failed to delete the account. Please try again later.\n");
                                            break;
                                        }

                                        printf("\n\tAccount deleted successfully.\n");
                                        printf("\n\tThe program exited. Thank you for using PUP-On-Line Bank.\n");
                                        fclose(fp);
                                        return 0;
                                    }
                                    else
                                    {
                                        printf("Account deletion canceled. Returning to the main menu.\n");
                                    }
                                    found = 1; 
                                    break;
                                
                                case 5:
                                    system("cls");

                                    printf("\n\t----------------------------"); 
                                    printf("\n\t5. EXIT");
                                    printf("\n\t----------------------------");

                                    printf("\n\n\tDo you really want to exit (Y | N)?: ");
                                    scanf(" %c", &confirm);
                                    while(getchar() != '\n')
                                        continue;
                                    if(confirm == 'N' || confirm == 'n')
                                    {
                                        exit = 0;
                                    }
                                    else
                                    {   
                                        printf("\n\tThe program exited. Thank you for using PUP-On-Line Bank.\n");
                                        exit = 1;

                                    }
                                    break;

                                default:
                                    printf("Invalid choice.\n");
                            }
                        }while(choice != 5 || exit == 0);

                        found = 1;
                        break;
                    }
                    else
                    {
                        attempts--;
                        printf("\n\t\tINCORRECT PIN. \n\t\t%d attempts remaining.\n", attempts);
                        if (attempts == 0)
                        {
                            printf("\n\tLogin failed. Exiting...\n");
                            fclose(fp);
                            return 0; 
                        }
                    }
                }
                break;
            }

            accountPosition = ftell(fp);
        }

        if (!found)
        {
            printf("\n\t\tACCOUNT NOT FOUND. \n\t\tPlease check your account number and try again.\n");
        }
    }

    fclose(fp);
    return 0;
}