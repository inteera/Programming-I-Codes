#include <stdio.h>

int main(){

    FILE *answerKeys = fopen("AnswerKeys.txt", "r");
    FILE *cards = fopen("Cards.txt", "r");
    FILE *grades = fopen("Grades.txt", "w");
    FILE *statistics = fopen("Statistics.txt", "w");

    char answers[2][52];
    char card[143];
    short int order = 1;
    short int mt;
    short int temp;
    char a[2];
    
    fgets(answers[0], 52, answerKeys);
    fgets(a, 2, answerKeys);
    fgets(answers[1], 52, answerKeys);

    printf("---\n");
    for(int i = 0; i < 51; i++){
        printf("%c", answers[0][i]);
    }
    printf("\n---\n");
    for(int i = 0; i < 51; i++){
        printf("%c", answers[1][i]);
    }
    printf("\n---\n");

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
        printf("Booklet: %c, ", card[40]);
        mt = 0;
        temp = 0;
        for(int temp = 1; temp <= 50; temp++){
            switch (card[40]){
                case 'A':
                    if(answers[0][temp] == card[40 + temp]) mt += 2;
                case 'B':
                    if(answers[1][temp] == card[40 + temp]) mt += 2;
            }
        }
        printf("%d", mt);
        printf("\n");
        fprintf(grades, " ");
        fprintf(grades, "%2d", mt);

        fprintf(grades, "\n");
    }

    //230508027

    return 0;
} 