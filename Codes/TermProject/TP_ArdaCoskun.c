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
    short int key;
    short int error = 0;
    char a[2];
    
    fgets(answers[0], 52, answerKeys);
    fgets(a, 2, answerKeys);
    fgets(answers[1], 52, answerKeys);

    //Header
    fprintf(grades, "sn. ID        Name                 MT");
    fprintf(grades, "\n");
    while(fgets(card, 143, cards) != NULL){
        //Is the name writable
        for (int i = 0; i < 20; i++) {
            if (isprint(card[i])) {
                
            } else {
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
                fprintf(grades, "?"); // Bozuk karakter yerine '?' koyabilirsiniz
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
    }

    //230508027

    return 0;
} 