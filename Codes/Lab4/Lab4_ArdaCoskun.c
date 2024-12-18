#include <stdio.h>

int main(){

  int numbers[10], sum = 0, avg, maximum, minimum, lengthOfArray;

  lengthOfArray = sizeof(numbers) / sizeof(numbers[0]);
  
  //Take all of the numbers
  for(int i = 0; i < lengthOfArray; i++){
    printf("Enter %d. number\n>", (i+1));
    scanf("%d", &numbers[i]);
  }

  //Analyse numbers[]
  maximum = numbers[0];
  minimum = numbers[0];
  for(int i = 0; i < lengthOfArray; i++){
    sum += numbers[i];
    if(numbers[i] >= maximum){
      maximum = numbers[i];
    }
    if(numbers[i] <= minimum){
      minimum = numbers[i];
    }
    printf("%d\n", sum);
  }

  avg = sum / lengthOfArray;

  printf("\nMaximum value: %d\n", maximum);
  printf("Minimum value: %d\n", minimum);
  printf("Average: %d", avg);
  
  return 0;
}
