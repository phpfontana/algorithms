#include<stdio.h>
#include<stdlib.h>


// 02 Read Array
void read_array(int*array,int n)
{
    printf("\nInput array\n");
    for (int i = 0; i < n; i++)
    {
        printf("Array[%d]: ",i);
        scanf("%d%*c",&array[i]);
    }
}

// 03 print array
void print_array(int *array, int n)
{
    printf("\nArray:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",array[i]);
        
    }
}

// 04 Mean of array
float mean_array(int*array,int n)
{
    float mean = 0.0f;

    for (int i = 0; i < n; i++)
    {
        mean += array[i];
    }
    mean = mean/n;
    return mean;
}

// 05 Memory Allocation
int * array_alloc(int n)
{
    int * array = (int *)malloc(n*sizeof(int));
    if(array == NULL)
        printf("ERROR!");
    
    return array;
}

// 06 Min value
int array_min(int *array, int n)
{
    int min = array[0];
    for(int i = 0; i < n; i++)
    {
        if (array[i] < array[0])
        {
            min = array[i];
        }
    }
    return min;
}
// max value
int array_max(int *array, int n)
{
    int max = array[0];
    for(int i = 0; i < n; i++)
    {
        if (array[i] > array[0])
        {
            max = array[i];
        }
    }
    return max;
}

// 07 how many even numbers
int count_even(int *array, int n)
{
    int count = 0;
    for ( int i = 0; i < n; i ++)
    {
        if (array[i] % 2 == 0)
            count ++;
    }
    return count;
}

// 08 Array of only the even number
int * array_even(int * array, int n)
{
    int even_qtd = count_even(array,n);
    int * even_array = array_alloc(even_qtd);
    if (even_array==NULL)
        return even_array;

    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (array[i] % 2 == 0)
        {
            even_array[j] = array[i];
            j++;
        }

    }
    return even_array;
}

int main (void)
{
    int n;
    float mean;

    printf("How many inputs: ");
    scanf("%d%*c", &n);

    // creating array
    int * array = array_alloc(n);
    if (array==NULL)
        return -1;

    // reading array
    read_array(array,n);

    // print array
    print_array(array,n);
    
    //even array
    int * even = array_even(array,n);

    int n_even = count_even(array,n);

    // print array
    print_array(even,n_even);

    // MEAN, MAX, MIN

    int max,min;
    float mean_arr;

    max = array_max(array,n);
    min = array_min(array,n);
    mean_arr = mean_array(array,n);

    printf("\nMean:%.2f\nMIN:%d\nMAX:%d\n",mean_arr,min,max);

    free(array);
    free(even);
    return 0;
}
