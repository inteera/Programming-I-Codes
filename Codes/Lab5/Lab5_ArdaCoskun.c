#include <stdio.h>

int main(){
    FILE *file = fopen("file.txt", "w+");
    char firstName[15];
    char fileFirstName[15];

    printf("Enter your name => ");
    scanf("%s", firstName);

    fprintf(file, "%s", firstName);

    fclose(file);

    FILE *readFile = fopen("file.txt", "r");

    fgets(fileFirstName, 15, readFile);

    printf("Readed value => %s", fileFirstName);

    return 0;
}