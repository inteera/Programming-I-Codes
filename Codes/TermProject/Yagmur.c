#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define allstndt 385


int grdclcltr(char answers[52], char answerkey[52]) {
    int grade = 0;
    
    for (int i = 0; i < 50; i++) {
        if (answers[i] == answerkey[i + 1]) {
            grade += 2;
        }
    }
    return grade;
}

int main() {
    char firstName[21];
    char tc[12];
    char id[10];
    char bookletType[2];
    char answer[52];
    char answerkeyA[52];
    char answerkeyB[52];
    char temp[4];


    FILE *inputFile = fopen("Cards.txt", "r");
    FILE *inputFile3 = fopen("AnswerKeys.txt", "r");

    if (inputFile == NULL || inputFile3 == NULL) {
        perror("Failed to open file");
        return 1;
    }


    fgets(answerkeyA, 52, inputFile3);
    fgets(temp, 4, inputFile3);
    fgets(answerkeyB, 52, inputFile3);

    printf("%-20s %-12s %-10s %-2s %-51s %-5s\n", "Name", "TC", "ID", "BT", "Answers", "Grade");
    printf("-------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < allstndt; i++) {

        fgets(firstName, sizeof(firstName), inputFile);
        fgets(tc, sizeof(tc), inputFile);
        fgets(id, sizeof(id), inputFile);
        fgets(bookletType, sizeof(bookletType), inputFile);
        fgets(answer, sizeof(answer), inputFile);


        firstName[strcspn(firstName, "\n")] = '\0';
        tc[strcspn(tc, "\n")] = '\0';
        id[strcspn(id, "\n")] = '\0';
        bookletType[strcspn(bookletType, "\n")] = '\0';
        answer[strcspn(answer, "\n")] = '\0';

        if (strlen(tc) > 12) {
            tc[12] = '\0';
        }
        if (strlen(id) > 9) {
            id[9] = '\0';
        }

        int grade = 0;
        if (bookletType[0] == 'A') {
            grade = grdclcltr(answer, answerkeyA);
        } else if (bookletType[0] == 'B') {
            grade = grdclcltr(answer, answerkeyB);
        }

        printf("%-20s %-12s %-10s %-2s %-51s %-5d\n", firstName, tc, id, bookletType, answer, grade);
    }

    fclose(inputFile);
    fclose(inputFile3);

    return 0;
}