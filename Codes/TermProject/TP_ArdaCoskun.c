#include <stdio.h>
#include <ctype.h>

struct Student{
    char name[20];
    char number[10];
    char nationalID[12];
    char bookletType;
    char answers[101];
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
    int key = 0;
    int temp;
    char tempc[143];
    int error = 0;
    
    fgets(answers[0], 53, answerKeys);
    fgets(answers[1], 53, answerKeys);

    fprintf(grades, "sn. ID        Name                 MT");
    fprintf(grades, "\n");

    for(int i = 0; i < stdno; i++){
        fgets(students[i].name, 20, cards);
        fgets(students[i].nationalID, 13, cards);
        fgets(students[i].number, 10, cards);
        fgets(&students[i].bookletType, 2, cards);
        fgets(students[i].answers, 103, cards);

        for (int j = 0; j < 20; j++) {
            if (!isprint(students[i].name[i])) {
                error = 1;
            }
        }

        students[i].grade = 0;
        key = students[i].bookletType == 'A' ? 0 : 1;
        for(int temp = 0; temp < 50; temp++){
            if(answers[key][temp + 1] == students[i].answers[temp]) students[i].grade += 2;
        }

    }
    for(int i = 0; i < stdno; i++){
        fprintf(grades, "%03d %s %-20s %3d\n", i + 1, students[i].number, students[i].name, students[i].grade);
        printf("%03d %s %-20s %3d\n", i + 1, students[i].number, students[i].name, students[i].grade);
    }

    return 0;
} 