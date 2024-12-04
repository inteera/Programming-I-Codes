#include <stdio.h>

int main()
{
    
    int width, height, area;

    area = width*height;

    printf("Enter a width =>");
    scanf("%d", &width);
    printf("Enter a height =>");
    scanf("%d", &height);

    area = width * height;

    printf("Area is: %d", area);

    return 0;
}
