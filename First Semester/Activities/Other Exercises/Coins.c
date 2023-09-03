#include <stdio.h>

int main()
{
    int a, b, c, d , e, f, g, sum;
    float amount;
    char name[80];

    printf("Name please:\t");
    scanf("%s",name);

    printf("%s, please enter your coins:\n",name);
    printf("\t5 centavo:\t");
    scanf("%d",&a);
    printf("\t10 centavo:\t");
    scanf("%d",&b);
    printf("\t25 centavo:\t");
    scanf("%d",&c);
    printf("\t1 peso:\t\t");
    scanf("%d",&d);
    printf("\t5 peso:\t\t");
    scanf("%d",&e);
    printf("\t10 peso:\t");
    scanf("%d",&f);
    printf("\t20 peso:\t");
    scanf("%d",&g);

    sum = a + b + c + d + e + f + g;
    amount = (a * 0.5)+(b * .10)+(c * .25)+(d * 1)+(e * 5)+(f * 10)+(g * 20);
    
    printf("\n%s your %d coins is Php %.2f\n",name,sum,amount);
    return 0;
}