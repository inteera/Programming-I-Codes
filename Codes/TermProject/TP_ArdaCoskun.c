#include <stdio.h>
#include <ctype.h>

struct Student{
    char name[20];
    char number[10];
    char nationalID[12];
    char bookletType;
    char answers[51];
    int grade;
} typedef Student;

int main(){

    FILE *answerKeys = fopen("AnswerKeys.txt", "r");
    FILE *cards = fopen("Cards.txt", "r");
    FILE *grades = fopen("Grades.txt", "w");
    FILE *statistics = fopen("Statistics.txt", "w");

    int stdno = 384;
    char answers[2][52];
    Student students[stdno];
    int temp;
    int error = 0;
    
    fgets(answers[0], 53, answerKeys);
    fgets(answers[1], 53, answerKeys);

    //Header
    fprintf(grades, "sn. ID        Name                 MT");
    fprintf(grades, "\n");
    //143
    for(int i = 0; i < stdno; i++){
        fgets(students[i].name, 20, cards);
        fgets(students[i].nationalID, 13, cards);
        fgets(students[i].number, 10, cards);
        fgets(&students[i].bookletType, 2, cards);
        fgets(students[i].answers, 51, cards);
        printf("%s  %s  %s  %c  %s", students[i].name, students[i].nationalID, students[i].number, students[i].bookletType, students[i].answers);
        fprintf(grades, "%03d ", i + 1);
    }
        /*
        //Is the name writable
        fgets(card, 143, cards)
        for (int i = 0; i < 20; i++) {
            if (!isprint(card[i])) {
                error = 1;
            }
        }

        //Order number
        fprintf(grades, "%03d ", order);
        order++;

        //Student number
        for(int i = 31; i < 40; i++){
            int temp = i;
            if(error){
                temp += 1;
            }
            fprintf(grades, "%c", card[temp]);
        }
        fprintf(grades, " ");

        //Name
        for (int i = 0; i < 20; i++) {
            if (isprint(card[i])) {
                fprintf(grades, "%c", card[i]);
            } else {
                error = 1;
                fprintf(grades, "?");
            }
        }

        mt = 0;
        key = card[40] == 'A' ? 0 : 1;
        for(int temp = 1; temp < 51; temp++){
            if(answers[key][temp] == card[40 + temp]) mt += 2;
        }
        fprintf(grades, " ");
        fprintf(grades, "%2d", mt);

        fprintf(grades, "\n");

        if(error){
            fgets(card, 143, cards);
        }
        error = 0;
        */
        

    return 0;
} 