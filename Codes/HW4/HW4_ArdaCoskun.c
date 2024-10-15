#include <stdio.h>
#include <ctype.h>

int main() {
    char message[20];
    char ch;
    int shift;
    int i = 0;

    printf("Enter a message to encrypt\n>");
    scanf("%s", message);

    printf("Enter shift value\n>");
    scanf("%d", &shift);
    
    while(message[i] != '\0')
    {
        ch = message[i];
        if(isupper(ch))
        {
            message[i] = ((ch - 65 + shift + 26) % 26) + 65;
        }
        else
        {
            message[i] = ((ch - 97 + shift + 26) % 26) + 97;
        }
        i++;
    }   

    printf("Encrypted message: %s", message);

    return 0;
}
