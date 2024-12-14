#include <stdio.h>
#include <ctype.h>

struct Student{
    unsigned char name[20];
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
    int answerStatistics[2][100] = {0};
    int countOfBooklets[2] = {0};
    int minGrade;
    int maxGrade;
    int avgGrade = 0;
    Student students[stdno];
    int key = 0;
    int temp = 0;
    char tempc[143];
    int error = 0;
    
    fgets(answers[0], 53, answerKeys);
    fgets(answers[1], 53, answerKeys);

    fprintf(grades, "sn. ID        Name                 MT");
    fprintf(grades, "\n");

    for(int i = 0; i < stdno; i++){
        fgets(students[i].name, 20, cards);
        for(int j = 0; j < 20; j++){
            if(students[i].name[j] > 128){
                 temp = 1;
                 /*switch (students[i].name[j]){
                    case 128:
                        students[i].name[j] = 67;
                    case 129:
                        students[i].name[j] = 117;
                    case 135:
                        students[i].name[j] = 99;
                    case 153:
                        students[i].name[j] = 79;
                    case 154:
                        students[i].name[j] = 85;
                    default: 
                        break;
                 }*/
            }
        }
        fgets(students[i].nationalID, 13 + temp, cards);
        fgets(students[i].number, 10, cards);
        fgets(&students[i].bookletType, 2, cards);
        fgets(students[i].answers, 103, cards);
        temp = 0;
        for (int j = 0; j < 20; j++) {
            if (!isprint(students[i].name[i])) {
                error = 1;
            }
        }

        students[i].grade = 0;
        key = students[i].bookletType == 'A' ? 0 : 1;
        countOfBooklets[key] += 1;
        for (int j = 0; answers[key][j + 1] != '\0'; j++) {
            if (answers[key][j + 1] == students[i].answers[j]) {
                students[i].grade += 2;
                answerStatistics[key][j] += 1;
            }
        }
    }

    minGrade = students[0].grade;
    maxGrade = students[0].grade;
    int sum = 0;
    for(int i = 0; i < stdno; i++){
        if(students[i].grade < minGrade) minGrade = students[i].grade;
        if(students[i].grade > maxGrade) maxGrade = students[i].grade;
        sum += students[i].grade;
    }
    avgGrade = sum / stdno;
    for(int i = 0; i < stdno; i++){
        fprintf(grades, "%03d %s %-20s %3d\n", i + 1, students[i].number, students[i].name, students[i].grade);
        printf("%03d %s %-20s %3d\n", i + 1, students[i].number, students[i].name, students[i].grade);
    }
    /*for(int i = 0; i < 100; i++){
        printf("%d. - %d\n", i + 1, answerStatistics[i]);
    }*/
    printf("%d, %d, %d", minGrade, maxGrade, avgGrade);

    return 0;
} 