#include <stdio.h>

int main(){
    int array[10];
    for(int i = 0; i < 10; i++){
        printf("Enter %d. number => ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("\n");

    for(int i = 0; i < 10; i++){
        printf("%d ", array[i]);
    }

    int temp;

    for(int i = 0; i < 3; i++){
        temp = array[i];
        array[i] = array[7 + i];
        array[7 + i] = temp;
    }

    printf("\n--\n");
    for(int i = 0; i < 10; i++){
        printf("%d ", array[i]);
    }
    printf("\n--");

    return 0;
}