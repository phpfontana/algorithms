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
    printf("\n");
    printf("Array\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d",array[i]);
    }
    printf("\n");
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

// 04 Memory Allocation
int* array_memory_alloc(int n)
{
    int *array = (int*)malloc(n*sizeof(int));
    if (array == NULL)
    {
        printf("Error!");
    }

    return array;
}

// 05 Max value
int array_max(int *array, int n)
{
    int max = array[0];
    for (int i = 0; i < n; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    return max;
}

// 06 Min value
int array_min(int *array, int n)
{
    int min = array[0];
    for (int i = 0; i < n; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }
    
    return min;
}

// 07 Even numbers
int count_even(int *array, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (array[i] % 2 == 0)
        {
            count++;
        }
    }
    return count;
}   

int* array_even(int *array, int n)
{
    int even_count = count_even(array,n);  // Count of even numbers inside array
    int *arr_even = array_memory_alloc(even_count);  // Dynamic array of even numbers
    if(arr_even == NULL)
        return arr_even;

    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if(array[i] % 2 == 0)
        {
            arr_even[j] = array[i];
            j++;
        }
    }
    return arr_even;
}

// MAIN
int main()
{
    int *array,*even_array, n, max, min, n_even;
    float mean;

    printf("Input array size: ");
    scanf("%d%*c",&n);

    array = array_memory_alloc(n);
    if(array == NULL)
        return -1;

    read_array(array,n);
    
    print_array(array,n);
    
    n_even = count_even(array,n);
    even_array = array_even(array,n);
    print_array(even_array,n_even);

    mean = array_mean(array,n);
    max = array_max(array,n);
    min = array_min(array,n);

    printf("\nMean: %0.2f", mean);
    printf("\nMax: %d", max);
    printf("\nMin: %d\n", min);
    free(array);
    free(even_array);

    return 0;
}
