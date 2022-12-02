#include<stdio.h>
#include<stdlib.h>

#define LEN 5

float array_mean( float *array)
{
    float sum = 0, mean=0;

    for(int i = 0; i < LEN; i++)
    {
        sum += array[i];
    }

    mean = sum/LEN;

    return mean;
}

int main (void)
{
    float array[LEN];
    float mean;

    printf("Input array values\n");
    for(int i = 0; i < LEN; i++)
    {
        printf("Array[%d]: ", i);
        scanf("%f%*c",&array[i]);
    }

    mean = array_mean(array);
    printf("Mean:%0.2f\n",mean);

    return 0;
}
