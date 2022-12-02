/*

DYNAMIC MEMORY ALLOCATION 01:

*/
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int n;
    printf("How many inputs: ");
    scanf("%d%*c",&n);

    int *arr;

    arr = (int *)malloc(n * sizeof(int));
    if (arr==NULL)
    {
        printf("ERROR!\n");
        return -1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Input arr[%d]: ", i);
        scanf("%d",&arr[i]);
    }

    printf("Array: ");
    for (int i = 0; i < n; i ++)
    {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;

}