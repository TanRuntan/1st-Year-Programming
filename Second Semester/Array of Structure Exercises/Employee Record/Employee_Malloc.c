#include<stdio.h>
#include<stdlib.h>

struct employee
{
    char name[80];
    char address[80];
    int age;
    float salary;
};

int main()
{
    int n;
    float totalsalary = 0;

    printf("Please enter number of employee: ");
    scanf("%d", &n);

    struct employee *rec;

    rec = (struct employee *)malloc(sizeof(struct employee) * n);

    for(int i = 0; i < n; i++)
    {
        printf("\n\tEnter name of employee: ");
        scanf(" %[^\n]", rec -> name);

        printf("\tEnter address of employee: ");
        scanf(" %[^\n]", rec -> address);

        printf("\tEnter age of employee: ");
        scanf("%d", &rec -> age);

        printf("\tEnter salary of employee: ");
        scanf("%f", &rec -> salary);

        totalsalary += rec -> salary;
    }

    float avesalary = totalsalary / n;

    printf("\nAverage Salary: %.2f", avesalary);

    free(rec);

    return 0;


}