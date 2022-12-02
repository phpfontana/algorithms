/*

MODUARIZATION 02:

*/

#include<stdio.h>

#define PI 3.14159

float cylinder_vol(float radius, float height)
{
    float volume;

    volume = PI * radius * radius * height;
    
    return volume;
}

int main (void)
{
    float radius, height, volume;
    printf("Input radius and height (x y):");
    scanf("%f%f%*c",&radius,&height);
    
    volume = cylinder_vol(radius,height);
    
    printf("The volume is %0.2f\n",volume);
}