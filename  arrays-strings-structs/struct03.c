/*

STRUCT 03:

*/
#include<stdio.h>
#include<string.h>

#define LEN 5
#define BUFFER_LEN 50

struct employee
{
    char name[BUFFER_LEN];
    int age;
    float salary;
};
typedef struct employee Employee;

int main (void)
{
    Employee e[LEN];

    printf("\nInput Employee Information\n");
    for (int i = 0; i < LEN; i++)
    {
        printf("Employee[%d]\n",i) ;      
        printf("Name: ");
        fgets(e[i].name,BUFFER_LEN,stdin);
        printf("Age:");
        scanf("%d%*c",&e[i].age);
        printf("salary:");
        scanf("%f%*c",&e[i].salary);
    }

    for (int i = 0; i < LEN; i++)
    {
        printf("\nEmployee[%d]\nName:%s\nAge:%d\nSalary: %.02f",i,e[i].name,e[i].age,e[i].salary);
    }

    return 0;
}