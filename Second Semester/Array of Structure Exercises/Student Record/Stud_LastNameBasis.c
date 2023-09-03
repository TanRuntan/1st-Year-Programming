
#include <stdio.h>
#include <string.h>

/* Write a program that takes Idno, fname, lname of 5 students and displays the same records in 
ascending order on the basis of lname. */

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
        printf("\nStudent Record [%i]", i + 1);

        printf("\n\tFirst Name: ");
        scanf(" %[^\n]", list[i].stud_fname);

        printf("\tLast Name: ");
        scanf(" %[^\n]", list[i].stud_lname);

        printf("\tStudent ID No: ");
        scanf("%d", &list[i].stud_id);
    }

    for(int a = 0; a < 5; a++)
    {
        for(int b = a + 1; b < 5; b++)
        {
            if (strcmp(list[b].stud_lname, list[a].stud_lname) < 0)
            {
                struct student temp = list[b];
                list[b] = list[a];
                list[a] = temp;
            }
        }
    }

    printf("Student Record");
    for(int j = 0; j < 5; j++)
    {
        printf("\n\t%d \n\t%s \n\t%s\n", list[j].stud_id, list[j].stud_fname, list[j].stud_lname);
    } 

    return 0;

}