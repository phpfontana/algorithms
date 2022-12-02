/*

STRUCT 02:

*/
#include<stdio.h>

#define LEN 10

struct space
{
    float x;
    float y;
};
typedef struct space Space;

int main (void)
{
    Space s[LEN];

    printf("Input Coordinates\n");

    for (int i = 0; i < LEN; i++)
    {
        printf("S[%d](x y): ",i);
        scanf("%f%f%*c",&s[i].x,&s[i].y);
    }

    printf("\nCoordinates\n");

    for (int i = 0; i < LEN; i++)
    {
        printf("S[%d]:(%0.2f %0.2f)\n",i,s[i].x,s[i].y);
    }

    return 0;
}