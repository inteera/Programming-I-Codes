#include <stdio.h>

int main()
{
  int numbers[10];
  int largestNumber;
  int smallestNumber;

  //User input for numbers
  for(int i = 0; i < 10; i++)
  {
    printf("Enter %d. number\n>", (i+1));
    scanf("%d", &numbers[i]);
  }
  //Assigning the first value for both lragest and smallest for algorithm
  largestNumber = numbers[0];
  smallestNumber = numbers[0];

  for(int i = 0; i < (sizeof(numbers) / sizeof(numbers[0])); i++)
  {
    //Finding largest number
    if(numbers[i] >= largestNumber)
    {
      largestNumber = numbers[i];
    }

    //Finding smallest number
    if(numbers[i] <= smallestNumber)
    {
      smallestNumber = numbers[i];
    }
  }

  printf("Largest number => %d\n", largestNumber);
  printf("Smallest number => %d", smallestNumber);

  return 0;
}
