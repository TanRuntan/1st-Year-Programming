#include <stdio.h>
#include <string.h>

/* Write a program to read the name, address, and salary of employee using array of structure.
Display the average salary of the employee*/

struct employee
{
    char emp_name[80];
    char emp_address[80];
    int emp_age;
    float emp_salary;
};

int main()
{
    int n;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct employee rec[n];
    float totalemp_salary = 0;

    for(int i = 0; i < n; i++)
    {
        printf("\nEnter Employee Record [%i]", i + 1);

        printf("\n\tName: ");
        scanf(" %[^\n]", rec[i].emp_name);

        printf("\n\tAddress: ");
        scanf(" %[^\n]", rec[i].emp_address);

        printf("\n\tAge: ");
        scanf("%d", &rec[i].emp_age);

        printf("\n\tSalary: ");
        scanf("%f", &rec[i].emp_salary);

        totalemp_salary += rec[i].emp_salary;
    }

    float aveemp_salary = totalemp_salary / n;

    printf("\nAverage Salary: %.2f", aveemp_salary);

    return 0;
}
