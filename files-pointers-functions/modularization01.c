/*

MODULARIZATION 01:

*/
#include<stdio.h>

float celsius_to_fahrenheit(float celsius)
{
    // Input: Celsius
    // Output: Fahrenheit

    float fahrenheit;
    fahrenheit = 1.8 * celsius + 32;

    return fahrenheit;
}

int main (void)
{
    float c, f;

    printf("Celsius:");
    scanf("%f%*c", &c);

    f = celsius_to_fahrenheit(c);

    printf("Temp in fahrenheit: %0.2f\n",f);
    return 0;
}