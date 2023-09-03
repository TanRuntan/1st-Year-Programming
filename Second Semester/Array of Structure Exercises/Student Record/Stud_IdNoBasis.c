#include <stdio.h>
#include <string.h> // used for string comparison

/* Write a program that takes Idno, fname, lname of 5 students and displays the same records in 
ascending order on the basis of Idno. */

struct student
{
    int stud_id;
    char stud_fname[80];
    char stud_lname[80];
};

int main()
{
    struct student list[5];

    for(int i = 0; i < 5; i++)
    {
        printf("\nEnter the record [%i]\n", i + 1);

        printf("\tFirst Name: ");
        scanf("%s", list[i].stud_fname);

        printf("\tLast Name: ");
        scanf("%s", list[i].stud_lname);

        printf("\tStudent ID Number: ");
        scanf("%d", &list[i].stud_id);
    }

    for (int a = 0; a < 5; a++) 
    {
        for (int b = a + 1; b < 5; b++) 
        {
            if (list[a].stud_id > list[b].stud_id)  // if (strcmp(list[b].stud_lname, list[a].stud_lname) < 0)
            {
                struct student temp = list[a];
                list[a] = list[b];
                list[b] = temp;
            }
        }
    }

    printf("\nStudent Records in Ascending Order (According to their ID Number):\n");
    for (int i = 0; i < 5; i++) {
        printf("\n\t%d \n\t%s \n\t%s\n", list[i].stud_id, list[i].stud_fname, list[i].stud_lname);
    }

    return 0;
}
