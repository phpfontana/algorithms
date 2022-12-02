/*

STRUCT 01:

*/
#include<stdio.h>

// defining a struct
struct space
{
    float x;
    float y;
};
typedef struct space Space;

int main (void)
{
    Space s; // declaring space type variable
    printf("Input coordinates (x y): ");
    scanf("%f %f%*c",&s.x,&s.y);
    printf("Space:(%0.2f,%0.2f)",s.x,s.y);
}
