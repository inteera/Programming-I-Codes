#include <stdio.h>

#define PI 3.1415926

int main() 
{
    float radius, area, circumference;

    printf("Enter radius of the circle => ");
    scanf("%f", &radius);

    area = PI * radius * radius;
    circumference = 2 * PI * radius;

    printf("Circumference: %f\n", circumference);
    printf("Area: %f", area);    

    return 0;
}