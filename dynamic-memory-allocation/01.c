/*

01 Dynamic Memory Allocation: 

*/

#include<stdio.h>

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
    for (int i = 0; i < n; i++)
    {
        printf(" %d",array[i]);
    }
}


int main()
{
    int *array, n;

    printf("Input array size: ");
    scanf("%d%*c",&n);
}