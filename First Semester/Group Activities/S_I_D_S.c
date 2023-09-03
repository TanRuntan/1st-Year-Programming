#include<stdio.h>

// SEARCHING. INSERTION. DELETION. SORTING
int main(){

    int x[5]; // ARRAY DECLARATION WITH A SIZE OF 5
    int n = 3; // NUMBER OF ELEMENTS 
    int i, j, k, t, ins, delete, found, temp; 
    int select; // VARIABLE TO STORE THE MENU SELECTION
    char ans; // VARIABLE TO STORE THE USERS ANSWER 'Y' AND 'N'
    char name[80]; // ARRAY TO STORE THE USERS NAME

    printf("\nWelcome! \nPlease enter your name: "); // ASKING THE USER TO ENTER THEIR NAMES
    scanf("%s", name); 

    printf("\n%s, please enter %d elements: ", name, n); // ASKING THE USER TO ENTER THREE NUMBER OF ELEMENTS
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x[i]); // READ THE THREE NUMBER OF ELEMENTS
    }
    printf("\tThe values you have entered are: "); // PRINTING THE NUMBER OF ELEMENTS THAT THE USER ENTERED
    for (i = 0; i < n; i++)
    {
        printf("%d, ", x[i]);
    }
        
    do // USING DO-WHILE LOOP TO PERFORM THE PROCESS SEVERAL TIMES
    {
        printf("\n\nWhich operation would you like to perform?"); // ASKING THE USER WHICH OPERATION THEY LIKE TO PERFORM
        printf("\n\tPRESS '1' TO SEARCH \n\tPRESS '2' TO INSERT \n\tPRESS '3' TO DELETE \n\tPRESS '4' TO SORT \n\tPRESS '5' TO EXIT\n");
        scanf("%d",&select);

        switch(select) // USING SWITCH STATEMENT FOR EVERY SELECTION
        {
            case 1:
                do // USING DO-WHILE LOOP STATEMENT TO PERFORM THE CASE 1 (TO SEARCH) SEVERAL TIMES
                {
                    printf("\n%s, please enter the number you want to search for: ", name); // GETTING THE NUMBER THAT THE USER WANT TO SEARCH FOR
                    scanf("%d", &t);
                    found = 0; // THIS TRACKS IF THE ELEMENT TO BE SEARCH HAS BEEN FOUND. IT IS SET TO 0 BEFORE THE FOR LOOP SEARCHES
                    for (i = 0; i < 5; i++) // FOR LOOP STATEMENT TO SEARCH FOR THE NUMBER IN THE ARRAY
                    {
                        if(x[i] == t) // USING IF STATEMENT IF THE NUMBER IS FOUND
                        {
                            found = 1; // IF THE ELEMENT IS FOUND THE VARIABLE WILL SET TO 1.
                            printf("\t%d was found at x[%d] or element %d.", t, i, i + 1); // PRINTING THE RESULT OF SEARCHING
                            break; // USE OF BREAK IF THE ELEMENT WAS FOUND
                        }

                    }
                    if(!found) // THIS CHECK IF THE NUMBER IS NOT FOUND.
                        {
                            printf("\t%d was not found.", t);
                        }
                
                    printf("\n\nTry again:\n"); // ASKING THE USER TO TRY AGAIN
                    printf("If YES press'Y' |  If NO press 'N'\n");
                    scanf("\n%c", &ans);
                } while(ans == 'Y'  || ans == 'y'); // IF YES, CASE 1 WILL PERFORM AGAIN
                break;
            
            case 2:
                do // USING DO-WHILE LOOP STATEMENT TO PERFORM THE CASE 2 (TO INSERT) SEVERAL TIMES
                {
                    if (n == 5) // THIS CHECKS IF THE SIZE OF ARRAY REACH IT'S CAPACITY WHICH IS 5
                    {
                        printf("\nError! The array is full."); // IF THE ARRAY IS FULL CONTAINING WITH 5 ELEMENTS THIS OUTPUT WILL BE PRINTED
                    }
                    else // THIS WILL PERFORM IF THE SIZE OF THE ARRAY IS NOT FULL
                    {
                        printf("\n%s, please enter a number you want to insert: ", name); // GETTING THE NUMBER THAT THE USER WANT TO INSERT FOR
                        scanf("%d", &ins);
                    
                        x[n] = ins; // USE THIS STATEMENT TO INSERT THE NUMBER INTO THE ARRAY
                        printf("\t%d was inserted at x[%d] or element %d.", ins, n, n + 1); // PRINTING THE RESULT OF INSERTING
                        n++; // UPDATING THE NUMBER OF ELEMENTS IN THE ARRAY
                    
                        printf("\n\tThus the new set of array is: "); // PRINTING THE NEW SET OF ARRAY
                            for (j = 0; j < n; j++)
                            {
                                printf("%d, ", x[j]);
                            }
                    }

                    printf("\n\nTry again:\n"); // ASKING THE USER TO TRY AGAIN
                    printf("If YES press'Y' |  If NO press 'N'\n");
                    scanf("\n%c", &ans);
                } while(ans == 'Y'  || ans == 'y'); // IF YES, CASE 2 WILL PERFORM AGAIN
                break;

            case 3:
                do // USING DO-WHILE LOOP STATEMENT TO PERFROM THE CASE (TO DELETE) SEVERAL TIMES
                {
                    printf("\n%s, please enter a number you want to delete: ", name); // GETTING THE NUMBER THAT THE USER WANTS TO DELETE
                    scanf("%d", &delete);
                    found = 0; // THIS TRACKS IF THE ELEMENT TO BE DELETED HAS BEEN FOUND. IT IS SET TO 0 BEFORE THE FOR LOOP SEARCHES
                    for (i = 0; i < n; i++) // USING FOR LOOP STATEMENT TO SEARCH FOR THE NUMBER IN THE ARRAY
                    {
                        if(x[i] == delete) // USING IF STATEMENT IF THE ELEMENT IS FOUND
                        {
                            found = 1; // IF THE ELEMENT IS FOUND THE VARIABLE WILL SET TO 1.
                            for (j = i; j < n - 1; j++) // USE TO SHIFT ELEMENTS TO LEFT IN ORDER TO FILL THE DELETED GAP
                            {
                               x[j] = x[j + 1];
                            }
                            n--; // DECREASING THE NUMBER OF ELEMENTS IN THE ARRAY

                            printf("\t%d was deleted.", delete); // PRINTING THE RESULT OF DELETING
                            printf("\n\tThus the new set of array is: "); // PRINTING THE NEW SET OF ARRAY
                            for (k = 0; k < n; k++)
                            {
                                printf("%d, ", x[k]);
                            }
                            break; // USE OF BREAK FOR THE INNER LOOP
                        }
                    }
                    if(!found) // THIS CHECK IF THE NUMBER IS NOT FOUND.
                        {
                            printf("\t%d was not found in the array.", delete);
                        }

                    printf("\n\nTry again:\n"); // ASKING THE USER TO TRY AGAIN
                    printf("If YES press'Y' |  If NO press 'N'\n");
                    scanf("\n%c", &ans);
                } while(ans == 'Y'  || ans == 'y'); // IF YES CASE 3 WILL PERFORM AGAIN
                break;
            
            case 4:
                do // USING DO-WHILE LOOP STATEMENT TO PERFORM THE CASE 4 (TO SORT) SEVERAL TIMES
                {
                    // SORTING THE ARRAY IN ASCENDING ORDER
                    for (i = 0; i < n; ++i) 
                        for (j = i + 1; j < n; ++j)
                        {
                            if(x[i] > x[j]) // SWAPPING ELEMENTS IF NECESSARY TO SORT IN ASCENDING ORDER
                            {
                                // TO SWAP THE ELEMENTS IN ASCENDING ORDE
                                temp = x[i]; 
                                x[i] = x[j];
                                x[j] = temp;
                            }
                        }
    
                    printf("\nThe ascending order of numbers is: "); // PRINTING THE ARRAY IN ASCENDING ORDER
                    for(i = 0; i < n; i++)
                        printf("%d, ", x[i]);

                    // SORTING THE ARRAY IN DESCEDING ORDER
                    for (i = 0; i < n; i++) 
                        for (j = i + 1; j < n; j++)
                        {
                            if(*(x + i) < *(x + j)) // SWAPPING ELEMENTS IF NECESSARY TO SORT IN DESCENDING ORDER
                            {
                                // TO SWAP THE ELEMENTS IN DESCENDING ORDER
                                temp = *(x + i);
                                *(x + i) = *(x + j);
                                *(x + j) = temp;
                            }
                        }

                    printf("\nThe descending order of numbers is: "); // PRINTING THE ARRAY IN DESCENDING ORDER
                    for(i = 0; i < n; ++i)
                        printf("%d, ", x[i]);

                    printf("\n\nTry again:\n"); // ASKING THE USER TO TRY AGAIN
                    printf("If YES press'Y' |  If NO press 'N'\n");
                    scanf("\n%c", &ans);
                } while(ans == 'Y'  || ans == 'y'); // IF YES CASE 4 WILL PERFORM AGAIN
                break;
            
            case 5: // CASE 5 (TO EXIT) USE TO EXIT THE PROGRAM
                printf("\nAre you sure you want to exit?"); // ASKING THE USER IF THEY'RE SURE THEY WANT TO EXIT
                printf("\nIf YES press'Y' |  If NO press 'N'\n");
                scanf("\n%c", &ans);

                // IF THE USER ENTERED 'Y' or 'y', THEN THE PROGRAM WILL EXIT
                if(ans == 'Y' || ans == 'y')
                {
                    printf("\nThank you for using the program");
                    return 0;
                }

                // IF THE USER ENTERED 'N' or 'n', THEN THE CASE(SELECTION) WILL BE RESET TO 0
                else if(ans == 'N' || ans == 'n')
                {
                    select = 0;
                }
                break;
            
            default: // THIS WILL ONLY WORK IF THE USER INPUT INVALID VALUE
                printf("\nERROR! Invalid Input.");
                printf("\nPlease try again.\n");
                break;
            


        }
    }while(select !=5 ); // THIS MEANS ONLY CASE 1 TO 4 WILL BE EXECUTED WITHIN THE LOOP. CASE 5 IS USED IF THE USER WANTS TO TERMINATE THE PROGRAM OR NOT
    
}