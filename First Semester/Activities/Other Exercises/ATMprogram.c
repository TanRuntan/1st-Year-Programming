#include<stdio.h>

int main(){

    int transaction, wd, dpst;
    int balance = 25000;
    char ans;

    do
    {
        printf("\nWELCOME TO ISPAN BANK");
        printf("\n\nWhich transaction would you like to perform?");
        printf("\nPRESS '1' TO DEPOSIT\nPRESS '2' TO WITHDRAW\nPRESS '3' TO CHECK BALANCE\nPRESS '4' TO EXIT\n");
        scanf("%d", &transaction);

        switch(transaction)
        {
            case 1:
                do
                {
                    printf("\nDEPOSIT SELECTED");
                    printf("\nPlease enter the amount you would like to deposit: ");
                    scanf("%d", &dpst);
                    balance = balance + dpst;

                    printf("\nTry again?\n");
                    printf("If YES press 'Y' | If NO press 'N'\n");
                    scanf("\n%c", &ans);
                } while(ans == 'Y'|| ans == 'y');
                break;
            case 2:
                do
                {
                    printf("\nWITHDRAW SELECTED");
                    printf("\nPlease enter the amount you would like to withdraw: ");
                    scanf("%d", &wd);
                    balance = balance - wd;

                    printf("\nTry again?\n");
                    printf("If YES press 'Y' | If NO press 'N'\n");
                    scanf("\n%c", &ans);
                } while(ans == 'Y'|| ans == 'y');
                break;
            case 3:
                do
                {
                    printf("\nBALANCE INQUIRY SELECTED");
                    printf("\nYour total balance now is Php%d ", balance);

                    printf("\n\nTry again?\n");
                    printf("If YES press 'Y' | If NO press 'N'\n");
                    scanf("\n%c", &ans);
                } while(ans == 'Y'|| ans == 'y');
                break;
            case 4:
                printf("\nAre you sure you want to exit?\n");
                printf("\nIf YES press 'Y' | If NO press 'N'\n");
                scanf("\n%c", &ans);
                if(ans == 'Y' || ans == 'y') 
                {
                    printf("\nTHANK YOU FOR USING ISPAN BANK!");
                    return 0;
                }
                else if (ans == 'N'|| ans == 'n')
                {
                    transaction = 0;
                }
                break;
            default:
                printf("\nERROR! Bongol amp");
                break;
        }
    } while(transaction != 4);
      
}