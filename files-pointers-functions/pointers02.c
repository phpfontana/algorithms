/*

POINTERS 02:

*/

#include<stdio.h>

void sumprod(int a, int b, int *p, int *q)
{
    *p = a + b;
    *q = a * b;
}

int main (void)
{
    int s,p;

    sumprod(3,5,&s,&p);
    printf("Sum: %d\nPruduct: %d\n",s,p);
}