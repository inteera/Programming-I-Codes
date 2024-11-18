#include <stdio.h>

int main(){

    FILE *answerKeys = fopen("AnswerKeys.txt", "r");
    FILE *cards = fopen("Cards.txt", "r");
    FILE *grades = fopen("Grades.txt", "w");
    FILE *statistics = fopen("Statistics.txt", "w");

    char answers[104];
    char card[143];
    short int order = 1;

    
    fgets(answers, 103, answerKeys);
    fprintf(grades, "sn. ID        Name                 MT");
    fprintf(grades, "\n");
    while(fgets(card, 143, cards) != NULL){
        fprintf(grades, "%03d ", order);
        order++;

        for(int i = 31; i < 40; i++){
            fprintf(grades, "%c", card[i]);
        }
        
        fprintf(grades, " ");

        for(int i = 0; i < 20; i++){
            fprintf(grades, "%c", card[i]);
        }

        short int mt = 0;
        int temp = 0;
        while(temp < 50){
            if(answers[temp] == card[42 + temp]){
                printf("%c: %c, ", answers[temp], card[42 + temp]);
                mt += 2;
            }
            temp++;
        }
        printf("\n");
        fprintf(grades, " ");
        fprintf(grades, "%d", mt);

        fprintf(grades, "\n");
    }

    return 0;
} 