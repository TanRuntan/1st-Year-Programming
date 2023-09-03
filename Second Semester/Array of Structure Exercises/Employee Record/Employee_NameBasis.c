#include <stdio.h>
#include <string.h>

struct employee
{
    char emp_name[80];
    char emp_add[80];
    int emp_age;
    float emp_salary;
};

int main()
{
    struct employee rec[5];

    for(int i = 0; i < 5; i++)
    {
        printf("\nEmployee Record [%i]", i + 1);
        
        printf("\n\tName: ");
        scanf(" %[^\n]", rec[i].emp_name);

        printf("\tAdress: ");
        scanf(" %[^\n]", rec[i].emp_add);

        printf("\tAge: ");
        scanf("%d", &rec[i].emp_age);

        printf("\tSalary: ");
        scanf("%f", &rec[i].emp_salary);
    }

    for(int a = 0; a < 5; a++)
    {
        for (int b = a + 1; b < 5; b++)
        {
            if(strcmp(rec[b].emp_name, rec[a].emp_name) < 0)
            {
                struct employee temp = rec[b];
                rec[b] = rec[a];
                rec[a] = temp;
            }
        }
    }

    printf("\nEmployee Record in Ascending Order");
    for(int j = 0; j < 5; j++)
    {
        printf("\n\t%s \n\t%s \n\t%d \n\t%f \n", rec[j].emp_name, rec[j].emp_add, rec[j].emp_age, rec[j].emp_salary );
    } 

return 0;

}

