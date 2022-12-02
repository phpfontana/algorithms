/*

POINTERS 03:

*/
#include<stdio.h>

#define LEN 3

float mean(float *x)
{
    float m = 0.0f;
    for (int i = 0; i < LEN; i++)
    {
        m +=x[i];
    }

    m = m/LEN;

    return m;
}

int main (void)
{
    float x[LEN];
    printf("input the values\n");

    for (int i = 0; i < LEN; i++)
    {
        scanf("%f%*c",&x[i]);
    }

    float m = mean(x);
    printf("Mean: %0.2f",m);
}
