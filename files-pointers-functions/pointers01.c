 /*
 
 POINTERS 01:
 
 */

#include<stdio.h>

int main (void)
{
    int a; // integer type variable
    int *p; // pointer for integer type variable

    p = &a;  // points to the memory of "a"
    *p = 2;  // Modifies a

    printf("a = %d\n*p = %d\np = %d\n",a,*p,p);
    return 0; 
}