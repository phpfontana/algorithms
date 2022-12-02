/*

DYNAMIC MEMORY ALLOCATION 02:

*/

#include<stdio.h>
#include<stdlib.h>

// reads Array
void read_array(int *array, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("input array[%d]: ",i);
        scanf("%d",&array[i]);
    }
}

// Prints array
void print_array(int * array, int n)
{
    printf("Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",array[i]);
    }
}

// Mean of Array
float array_mean(int * array, int n)
{
    float mean = 0.0f;

    for(int i = 0; i < n; i++)
        mean += array[i];
    
    mean = mean/n;

    return mean;
}

int* create_array(int* n)
{
    printf("How many inputs: ");
    scanf("%d",n);

    int *arr = (int *)malloc((*n)*sizeof(int));
    return arr;
}

int main (void)
{
    int *arr;
    int n;
    float mean;

    arr = create_array(&n);
    if (arr == NULL)
    {
        printf("ERROR!");
        return -1;
    }

    read_array(arr,n);
    print_array(arr,n);
    mean = array_mean(arr,n);
    printf("\nMean: %0.2f\n",mean);
    free(arr);

    return 0;
}