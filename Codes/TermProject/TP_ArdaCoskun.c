#include <stdio.h>

#define STDNO 384

typedef struct {
    unsigned char name[20];
    char number[10];
    char nationalID[12];
    char bookletType;
    char answers[101];
    int grade;
} Student;

void readAnswerKeys(FILE *file, char answers[2][52]) {
    fgets(answers[0], 53, file);
    fgets(answers[1], 53, file);
}

void readCards(FILE *file, Student *students, int *countOfBooklets) {
    int temp = 0;
    for (int i = 0; i < STDNO; i++) {
        fgets(students[i].name, 20, file);
        for (int j = 0; j < 20; j++) {
            if (students[i].name[j] > 128) {
                temp = 1;
            }
        }
        fgets(students[i].nationalID, 13 + temp, file);
        fgets(students[i].number, 10, file);
        fgets(&students[i].bookletType, 2, file);
        fgets(students[i].answers, 103, file);
        temp = 0;
        
        int key = students[i].bookletType == 'A' ? 0 : 1;
        countOfBooklets[key] += 1;
    }
}

void calculateGrades(Student *students, char answers[2][52], int answerStatistics[2][100]) {
    for (int i = 0; i < STDNO; i++) {
        int key = students[i].bookletType == 'A' ? 0 : 1;
        students[i].grade = 0;
        for (int j = 0; answers[key][j + 1] != '\0'; j++) {
            if (answers[key][j + 1] == students[i].answers[j]) {
                students[i].grade += 2;
                answerStatistics[key][j] += 1;
            }
        }
    }
}

void calculateStatistics(Student *students, int *minGrade, int *maxGrade, int *avgGrade) {
    *minGrade = students[0].grade;
    *maxGrade = students[0].grade;
    int sum = 0;

    for (int i = 0; i < STDNO; i++) {
        if (students[i].grade < *minGrade) *minGrade = students[i].grade;
        if (students[i].grade > *maxGrade) *maxGrade = students[i].grade;
        sum += students[i].grade;
    }
    *avgGrade = sum / STDNO;
}

void writeGrades(FILE *gradesFile, Student *students, int minGrade, int maxGrade, int avgGrade) {
    fprintf(gradesFile, "sn. ID        Name                 MT\n");
    for (int i = 0; i < STDNO; i++) {
        fprintf(gradesFile, "%03d %s %-20s %3d\n", i + 1, students[i].number, students[i].name, students[i].grade);
    }
    fprintf(gradesFile, "              Average               %d\n", avgGrade);
    fprintf(gradesFile, "              Maximum               %d\n", maxGrade);
    fprintf(gradesFile, "              Minimum               %d\n", minGrade);
}

void writeStatistics(FILE *statisticsFile, int countOfBooklets[2], int answerStatistics[2][100]) {
    fprintf(statisticsFile, "Count of A booklets   = %d\n", countOfBooklets[0]);
    fprintf(statisticsFile, "Count of B booklets   = %d\n", countOfBooklets[1]);
    fprintf(statisticsFile, "Count of all booklets = %d\n\n", countOfBooklets[0] + countOfBooklets[1]);
    fprintf(statisticsFile, "Using Booklet A numbering:\n");
    fprintf(statisticsFile, "Q    NoC\n");
    for (int i = 0; i < 50; i++) {
        fprintf(statisticsFile, "%03d  %3d\n", i + 1, (i + 10 <= 50) ? 
        answerStatistics[0][i] + answerStatistics[1][i + 10] : answerStatistics[0][i] + answerStatistics[1][i - 40]);
    }
}

int main() {
    FILE *answerKeys = fopen("AnswerKeys.txt", "r");
    FILE *cards = fopen("Cards.txt", "r");
    FILE *grades = fopen("Grades.txt", "w");
    FILE *statistics = fopen("Statistics.txt", "w");

    if (!answerKeys || !cards || !grades || !statistics) {
        printf("Cannot open one or more of the files.");
        return 1;
    }

    char answers[2][52];
    int answerStatistics[2][100] = {0};
    int countOfBooklets[2] = {0};
    int minGrade, maxGrade, avgGrade;
    Student students[STDNO];

    readAnswerKeys(answerKeys, answers);
    readCards(cards, students, countOfBooklets);
    calculateGrades(students, answers, answerStatistics);
    calculateStatistics(students, &minGrade, &maxGrade, &avgGrade);
    writeGrades(grades, students, minGrade, maxGrade, avgGrade);
    writeStatistics(statistics, countOfBooklets, answerStatistics);

    fclose(answerKeys);
    fclose(cards);
    fclose(grades);
    fclose(statistics);

    return 0;
}
