#include<stdio.h>
#include<stdlib.h>

#define LEN 10

int main (void)
{
    int array[LEN];

    for (int i = 0; i < 10; i++)
    {
        printf("Array[%d]",i);
        scanf("%d%*c",&array[i]);
    }
}