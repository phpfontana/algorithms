/*

01 Dynamic Memory Allocation: 

*/

#include<stdio.h>
#include<stdlib.h>

// 01 Read Array
void read_array(int *array, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("Input array[%d]: ",i);
        scanf("%d%*c",&array[i]);
    }
}

// 02 Print Array
void print_array(int *array, int n)
{
    printf("Array\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d",array[i]);
    }
}

// 03 Mean of the Array
float array_mean(int *array, int n)
{
    float mean = 0.0f;
    for(int i = 0; i < n; i++)
    {
        mean += array[i];
    }

    mean = mean/n;
    return mean;
}

// Memory Allocation
int* array_memory_aloc(int n)
{
    int *array = (int*)malloc(n*sizeof(int));
    if (array == NULL)
    {
        printf("Error!");
    }

    return array;
}


int main()
{
    int *array, n;
    float mean;

    printf("Input array size: ");
    scanf("%d%*c",&n);

    array = array_memory_aloc(n);
    if(array == NULL)
        return -1;

    read_array(array,n);
    
    print_array(array,n);
    
    mean = array_mean(array,n);
    
    printf("\nMean: %0.2f", mean);
    free(array);

    return 0;
}
