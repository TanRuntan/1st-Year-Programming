#include <stdio.h>
#include <stdlib.h>

// DISPLAY
// 1 STOCK NUMBER
// 1 STYLE NUMBER
// 1 SPECIFIC SIZE. DIFFERENT PAIRS
// 1 SAME PRICE

struct shoe
{
    int stockNumber;
    int styleNumber;
    int pairs[12];
    float price;
};

void shoe_record(FILE *fp)
{
    struct shoe invent;
    int tempstyleNumber;
    int tempstockNumber;
    int foundStock = 0;
    int foundStyle = 0;

    do {
        printf("\n\n\tEnter stock number: ");
        while (scanf("%d", &tempstockNumber) != 1)
        {
            printf("\n\t\tINVALID INPUT. \n\t\tPlease enter a valid stock number: ");
            while (getchar() != '\n')
                continue;
        }

        fseek(fp, 0, SEEK_SET);
        foundStock = 0; // Reset the flag for each iteration

        while (fscanf(fp, "%d %d ", &invent.stockNumber, &invent.styleNumber) == 2)
        {
            for (int i = 0; i < 12; i++)
            {
                fscanf(fp, "%d", &invent.pairs[i]);
            }
            fscanf(fp, "%f", &invent.price);

            if (invent.stockNumber == tempstockNumber)
            {
                foundStock = 1;
                printf("\n\t\tSTOCK NUMBER ALREADY EXISTS. \n\t\tPlease enter a different stock number.\n");
                break;
            }
        }

    } while (foundStock);

    do {
        printf("\n\tEnter style number (0-50): ");
        while (scanf("%d", &tempstyleNumber) != 1 || tempstyleNumber < 0 || tempstyleNumber > 50)
        {
            printf("\n\t\tINVALID STYLE NUMBER. \n\t\tPlease enter a valid style number (0-50): ");
            while (getchar() != '\n')
                continue;
        }

        fseek(fp, 0, SEEK_SET);
        foundStyle = 0; // Reset the flag for each iteration

        while (fscanf(fp, "%d %d ", &invent.stockNumber, &invent.styleNumber) == 2)
        {
            for (int i = 0; i < 12; i++)
            {
                fscanf(fp, "%d", &invent.pairs[i]);
            }
            fscanf(fp, "%f", &invent.price);

            if (invent.styleNumber == tempstyleNumber)
            {
                foundStyle = 1;
                printf("\n\t\tSTYLE NUMBER ALREADY EXISTS. \n\t\tPlease enter a different style number.\n");
                break;
            }
        }

    } while (foundStyle);
        

    invent.styleNumber = tempstyleNumber;
    invent.stockNumber = tempstockNumber;

    printf("\n\tEnter stock on hand per sizes.\n");
    for (int i = 0; i < 12; i++)
    {
        printf("\tSize %d: ", i + 3);
        if (scanf("%d", &invent.pairs[i]) != 1)
        {
            printf("\n\t\tINVALID INPUT. \n\t\tPlease enter a valid number.\n\n");
            while (getchar() != '\n')
                continue;
            i--;
        }
    }

    printf("\n\tEnter price: ");
    if (scanf("%f", &invent.price) != 1)
    {
        printf("\n\t\tINVALID PRICE. \n\t\tPlease enter a valid price.\n\n");
        while (getchar() != '\n')
            continue;
    }

    // Open the file in "append" mode instead of "read and write" mode
    FILE *fp_append = fopen("inventory.txt", "a");
    if (fp_append == NULL)
    {
        printf("Failed to open the file.");
        return;
    }

    fprintf(fp_append, "%d %d ", invent.stockNumber, invent.styleNumber);
    for (int i = 0; i < 12; i++)
    {
        fprintf(fp_append, "%d ", invent.pairs[i]);
    }
    fprintf(fp_append, "%.2f\n", invent.price);

    fclose(fp_append);

    printf("\n\t\tSHOE RECORD ADDED SUCCESSFULLY.");
}

void shoe_display(FILE *fp)
{
    struct shoe invent;
    int tempstockNumber;
    int tempstyleNumber;
    int sizeIndex;
    int found = 0;

    printf("\n\tEnter stock number: ");
    while (scanf("%d", &tempstockNumber) != 1)
    {
        printf("\n\t\tINVALID INPUT. \n\t\tPlease enter a valid stock number: ");
        while (getchar() != '\n')
            continue;
    }

    printf("\n\tEnter style number (0-50): ");
    while (scanf("%d", &tempstyleNumber) != 1 || tempstyleNumber < 0 || tempstyleNumber > 50)
    {
        printf("\n\t\tINVALID STYLE NUMBER. \n\t\tPlease enter a valid style number (0-50): ");
        while (getchar() != '\n')
            continue;
    }

    printf("\n\tEnter size number (3-14): ");
    while (scanf("%d", &sizeIndex) != 1 || sizeIndex < 3 || sizeIndex > 14)
    {
        printf("\n\t\tINVALID SIZE NUMBER. \n\t\tPlease enter a valid size number (3-14): ");
        while (getchar() != '\n')
            continue;
    }

    sizeIndex -= 3;

    fseek(fp, 0, SEEK_SET);

    while (fscanf(fp, "%d %d ", &invent.stockNumber, &invent.styleNumber) == 2) {
        for (int i = 0; i < 12; i++) {
            fscanf(fp, "%d", &invent.pairs[i]);
        }
        fscanf(fp, "%f", &invent.price);

        if (invent.stockNumber == tempstockNumber && invent.styleNumber == tempstyleNumber && invent.pairs[sizeIndex] > 0) 
        {
            found = 1;

            printf("\n\t----------------------------");
            printf("\n\tStock Number: %d", invent.stockNumber);
            printf("\n\tStyle Number: %d", invent.styleNumber);
            printf("\n\t----------------------------\n");
            
            printf("\n\tSize %d", sizeIndex + 3);
            printf("\n\tNumber of pairs: %d\n", invent.pairs[sizeIndex]);
            printf("\n\tPrice: %.2f\n", invent.price);
            break;
        }
    }

    if (!found) {
        printf("\n\t\tRECORD NOT FOUND.");
    }
}

void shoe_allrec(FILE *fp)
{
    struct shoe invent;

    fseek(fp, 0, SEEK_SET);

    while (fscanf(fp, "%d %d ", &invent.stockNumber, &invent.styleNumber) == 2)
    {
        for (int i = 0; i < 12; i++)
        {
            fscanf(fp, "%d", &invent.pairs[i]);
        }
        fscanf(fp, "%f", &invent.price);
    
        printf("\n\t----------------------------");
        printf("\n\tStock Number: %d", invent.stockNumber);
        printf("\n\tStyle Number: %d", invent.styleNumber);
        printf("\n\t----------------------------");

        for (int i = 0; i < 12; i++) {
            printf("\n\n\tSize %d", i + 3);
            printf("\n\tNumber of pairs: %d", invent.pairs[i]);
            printf("\n\tPrice: %.2f", invent.price);
        }
    }
}

void shoe_updateprice(FILE *fp)
{
    struct shoe invent;
    int tempstockNumber;
    int tempstyleNumber;
    float newPrice;
    int found = 0;

    printf("\n\tEnter stock number: ");
    while (scanf("%d", &tempstockNumber) != 1)
    {
        printf("\n\t\tINVALID INPUT. \n\t\tPlease enter a valid stock number: ");
        while (getchar() != '\n')
            continue;
    }

    printf("\n\tEnter style number (0-50): ");
    while (scanf("%d", &tempstyleNumber) != 1 || tempstyleNumber < 0 || tempstyleNumber > 50)
    {
        printf("\n\t\tINVALID STYLE NUMBER. \n\t\tPlease enter a valid style number (0-50): ");
        while (getchar() != '\n')
            continue;
    }

   FILE *tempFile = fopen("temp_inventory.txt", "w");
    if (tempFile == NULL)
    {
        printf("Failed to create temporary file.");
        return;
    }

    // Read all records from the original file and update the price in memory
    while (fscanf(fp, "%d %d", &invent.stockNumber, &invent.styleNumber) == 2)
    {
        for (int i = 0; i < 12; i++)
        {
            fscanf(fp, "%d", &invent.pairs[i]);
        }
        fscanf(fp, " %f\n", &invent.price); // Add an extra space before %f to consume the newline character

        if (invent.stockNumber == tempstockNumber && invent.styleNumber == tempstyleNumber)
        {
            found = 1;
            printf("\n\tEnter new price: ");
            scanf("%f", &newPrice);

            invent.price = newPrice;
        }

        // Write the updated record to the temporary file with a newline character
        fprintf(tempFile, "%d %d ", invent.stockNumber, invent.styleNumber);
        for (int i = 0; i < 12; i++)
        {
            fprintf(tempFile, "%d ", invent.pairs[i]);
        }
        fprintf(tempFile, "%.2f\n", invent.price);
    }

    // If the record is not found, display a message
    if (!found)
    {
        printf("\n\t\tRECORD NOT FOUND.");
        fclose(tempFile);
        remove("temp_inventory.txt"); // Remove the temporary file
        return;
    }

    // Close the original file and temporary file
    fclose(fp);
    fclose(tempFile);

    // Replace the original file with the temporary file
    remove("inventory.txt");
    rename("temp_inventory.txt", "inventory.txt");

    printf("\n\t\tPRICE UPDATED SUCCESSFULLY.");

    // Reset the file pointer to the beginning of the file
    fp = fopen("inventory.txt", "r+");
    if (fp == NULL)
    {
        printf("Failed to create/open the file.");
        return;
    }
}

void shoe_updatestock(FILE *fp)
{
    struct shoe invent;
    int tempstockNumber;
    int tempstyleNumber;
    int newStock;
    int sizeIndex;
    int found = 0;

    printf("\n\tEnter stock number: ");
    while (scanf("%d", &tempstockNumber) != 1)
    {
        printf("\n\t\tINVALID INPUT. \n\t\tPlease enter a valid stock number: ");
        while (getchar() != '\n')
            continue;
    }

    printf("\n\tEnter style number (0-50): ");
    while (scanf("%d", &tempstyleNumber) != 1 || tempstyleNumber < 0 || tempstyleNumber > 50)
    {
        printf("\n\t\tINVALID STYLE NUMBER. \n\t\tPlease enter a valid style number (0-50): ");
        while (getchar() != '\n')
            continue;
    }

    FILE *tempFile = fopen("temp_inventory.txt", "w");
    if (tempFile == NULL)
    {
        printf("Failed to create temporary file.");
        return;
    }

    while (fscanf(fp, "%d %d", &invent.stockNumber, &invent.styleNumber) == 2)
    {
        for (int i = 0; i < 12; i++)
        {
            fscanf(fp, "%d", &invent.pairs[i]);
        }
        fscanf(fp, "%f\n", &invent.price);

        if (invent.stockNumber == tempstockNumber && invent.styleNumber == tempstyleNumber)
        {
            found = 1;

            printf("\n\tEnter size (3-14) to change stock on hand: ");
            while (scanf("%d", &sizeIndex) != 1 || sizeIndex < 3 || sizeIndex > 14)
            {
                printf("\n\t\tINVALID SIZE. \n\t\tPlease enter a valid size number: ");
                while (getchar() != '\n')
                    continue;
            }

            sizeIndex -= 3;

            printf("\n\tEnter a new stock for size %d: ", sizeIndex + 3);
            while (scanf("%d", &newStock) != 1)
            {
                printf("\n\t\tINVALID INPUT. \n\t\tPlease enter a valid stock number: ");
                while (getchar() != '\n')
                    continue;
            }

            invent.pairs[sizeIndex] = newStock;
        }

        // Write the record to the temporary file
        fprintf(tempFile, "%d %d ", invent.stockNumber, invent.styleNumber);
        for (int i = 0; i < 12; i++)
        {
            fprintf(tempFile, "%d ", invent.pairs[i]);
        }
        fprintf(tempFile, "%.2f\n", invent.price);
    }

    fclose(fp);
    fclose(tempFile);

    // Replace the original file with the temporary file
    remove("inventory.txt");
    rename("temp_inventory.txt", "inventory.txt");

    if (found)
    {
        printf("\n\t\tSTOCK ON HAND UPDATED SUCCESSFULLY.");
    }
    else
    {
        printf("\n\t\tRECORD NOT FOUND.");
    }

    // Reset the file pointer to the beginning of the file
    fp = fopen("inventory.txt", "r+");
    if (fp == NULL)
    {
        printf("Failed to create/open the file.");
        return;
    }
}

void shoe_delete(FILE *fp) 
{
    struct shoe invent;
    int tempstyleNumber;
    int tempstockNumber;
    int foundStock = 0;
    int foundStyle = 0;
    int choice;

    printf("\n\n\tDELETE OPTIONS:");
    printf("\n\t1. Delete all records");
    printf("\n\t2. Delete a specified number of records based on stock and style numbers");
    printf("\n\t3. Delete the entire inventory file");
    printf("\n\tEnter your choice (1-3): ");
    
    if (scanf("%d", &choice) != 1 || choice < 1 || choice > 3) {
        printf("\n\t\tINVALID CHOICE.");
        return;
    }
    
    switch (choice) {
        case 1:
            {
                printf("\n\n\tWARNING: This will delete all records. Are you sure? (Y | N): ");
                char confirm;
                scanf(" %c", &confirm);
                if (confirm == 'Y' || confirm == 'y') {
                    fclose(fp); 
                    fp = fopen("inventory.txt", "w"); 
                    if (fp == NULL) {
                        printf("Failed to create/open the file.");
                        return;
                    }
                    printf("\n\t\tALL RECORDS DELETED SUCCESSFULLY.");
                } else {
                    printf("\n\t\tOPERATION CANCELLED.");
                }
            }
            break;
        case 2:
            int numRecordsToDelete;
            printf("\n\tEnter the number of records you want to delete: ");
            scanf("%d", &numRecordsToDelete);

            int foundRecords = 0; 
            int deletedRecords = 0; 

            printf("\n\n\tDELETE RECORDS:");
            for (int i = 0; i < numRecordsToDelete; i++) 
            {
                printf("\n\tRecord %d:", i + 1);
                printf("\n\tEnter stock number: ");
                scanf("%d", &tempstockNumber);
                printf("\tEnter style number (0-50): ");
                scanf("%d", &tempstyleNumber);

                FILE *tempFile = fopen("temp_inventory.txt", "w");
                if (tempFile == NULL) 
                {
                    printf("Failed to create temporary file.");
                    return;
                }

                fseek(fp, 0, SEEK_SET);
                int found = 0;
                while (fscanf(fp, "%d %d", &invent.stockNumber, &invent.styleNumber) == 2) 
                {
                    for (int i = 0; i < 12; i++) {
                        fscanf(fp, "%d", &invent.pairs[i]);
                    }
                    fscanf(fp, "%f", &invent.price);

                    
                    if (invent.stockNumber == tempstockNumber && invent.styleNumber == tempstyleNumber) {
                        found = 1; 
                        foundRecords++; 
                        
                        fscanf(fp, "%*[^\n]");
                    } else {
                        
                        fprintf(tempFile, "%d %d ", invent.stockNumber, invent.styleNumber);
                        for (int i = 0; i < 12; i++) {
                            fprintf(tempFile, "%d ", invent.pairs[i]);
                        }
                        fprintf(tempFile, "%.2f\n", invent.price);
                    }
                }
                if (found) {
                    deletedRecords++; 
                }

                fclose(fp);
                fclose(tempFile);

                
                remove("inventory.txt");
                rename("temp_inventory.txt", "inventory.txt");

                printf("\n\t\t%d RECORD(S) DELETED SUCCESSFULLY.", deletedRecords);
                
                fp = fopen("inventory.txt", "r+");
                if (fp == NULL) {
                    printf("Failed to create/open the file.");
                    return;
                }
            }

            
            break;
        case 3:
        {
            char confirm;
            printf("\n\n\tWARNING: This will delete the entire inventory file. Are you sure? (Y | N): ");
            scanf(" %c", &confirm);
            if (confirm == 'Y' || confirm == 'y') 
            {
                fclose(fp); 
                if (remove("inventory.txt") == 0) {
                    printf("\n\t\tINVENTORY FILE DELETED SUCCESSFULLY.");
                } else {
                    printf("\n\t\tFAILED TO DELETE INVENTORY FILE.");
                }
            } else 
            {
                printf("\n\t\tOPERATION CANCELLED.");
            }
        }
        break;

        default:
            printf("\n\t\tINVALID CHOICE.");
            break;
    }
}

int main()
{
    FILE *fp;
    fp = fopen("inventory.txt", "r+");
    if (fp == NULL)
    {
        fp = fopen("inventory.txt", "w+");
        if (fp == NULL)
        {
            printf("Failed to create/open the file.");
            return 1;
        }
    }

    int choice;
	char tryagain;
    char confirm;
	int exit = 0;

	do
	{
		do
		{
            printf("\n\t----------------------------");
			printf("\n\tSHOE INVENTORY MANAGEMENT");
            printf("\n\t----------------------------");
			printf("\n\n\t1. Enter a record");
			printf("\n\t2. Display a specific record");
            printf("\n\t3. Display all record");
			printf("\n\t4. Update the price");
			printf("\n\t5. Update the stock on hand");
			printf("\n\t6. Delete a record");
			printf("\n\t7. Exit");
			

            printf("\n\n\tEnter you like to perform: ");
            do
            {  
                if(scanf("%d", &choice) != 1)
                {
                    printf("\n\t\tINVALID OPTION. \n\t\tPlease enter valid option: ");
                    while(getchar() != '\n')
                        continue;
                }
            } while (choice == 0);
            
			switch(choice)
			{
				case 1:
                printf("\n\t----------------------------");
                printf("\n\t1. Enter a record");
                printf("\n\t----------------------------");
					do
					{	
						shoe_record(fp);
						printf("\n\t\tDo you to want enter record again (Y | N)?: ");
						scanf(" %c", &tryagain);
						while(getchar() != '\n')
							continue;
					}while(tryagain == 'Y' || tryagain == 'y');
					break;
		
				case 2:
                printf("\n\t----------------------------");
                printf("\n\t2. Display a specific record");
                printf("\n\t----------------------------");

                    fseek(fp, 0, SEEK_SET);
					do
					{
						shoe_display(fp);
						printf("\n\t\tDo you want to display record again (Y | N)?: ");
						scanf(" %c", &tryagain);
						while(getchar() != '\n')
							continue;
					}while(tryagain == 'Y' || tryagain == 'y');
					break;

                case 3:
                printf("\n\t----------------------------");
                printf("\n\t3. Display all record");
                printf("\n\t----------------------------");

                    fseek(fp, 0, SEEK_SET);
					do
					{
						shoe_allrec(fp);
						printf("\n\t\tDo you want to display record again (Y | N)?: ");
						scanf(" %c", &tryagain);
						while(getchar() != '\n')
							continue;
					}while(tryagain == 'Y' || tryagain == 'y');
					break;
					
				case 4:
                printf("\n\t----------------------------");
                printf("\n\t4. Update the price");
                printf("\n\t----------------------------");

                    fseek(fp, 0, SEEK_SET);
					do
					{
						shoe_updateprice(fp);
						printf("\n\t\tDo you want to update the price again (Y | N)?: ");
						scanf(" %c", &tryagain);
						while(getchar() != '\n')
							continue;
					}while(tryagain == 'Y' || tryagain == 'y');
					break;
			
				case 5:
                printf("\n\t----------------------------");
                printf("\n\t5. Update the stock on hand");
                printf("\n\t----------------------------");

                    fseek(fp, 0, SEEK_SET);
					do
					{
                        shoe_updatestock(fp);
						printf("\n\t\tDo you want to update the stock on hand again (Y | N)?: ");
						scanf(" %c", &tryagain);
						while(getchar() != '\n')
							continue;
					}while(tryagain == 'Y' || tryagain == 'y');
					break;	
	 
				case 6:
                printf("\n\t----------------------------");
                printf("\n\t6. Delete a stock");
                printf("\n\t----------------------------");
                    do
                    {
                        shoe_delete(fp);
                        printf("\n\t\tDo you want to delete a stock again (Y | N)?: ");
                        scanf(" %c", &tryagain);
                        while(getchar() != '\n')
                            continue;
                    } while (tryagain == 'Y' || tryagain == 'y');
					break;
              
				case 7:
                printf("\n\t----------------------------"); 
                printf("\n\t7. Exit");
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
                        exit = 1;
                    }
                    break;
                    
				default:
					printf("Invalid choice. Please try again.");	
			}
			
		}while (choice != 7 && (tryagain == 'Y' || tryagain == 'y'));
	}while(choice != 7 || exit != 1);
	
    printf("\n\tTHANK YOU.\n\n");
	fclose(fp);
	return 0;
}