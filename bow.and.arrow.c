#include <stdio.h>

int main(){

    int player_one_score, player_two_score, player_three_score, sum;
    double mean=0.0;

    printf("Informe a pontuação de cada jogador:\n");
    scanf("%d", &player_two_score);
    scanf("%d", &player_one_score);
    scanf("%d", &player_three_score);

    if (player_one_score <= player_two_score) {
        if (player_two_score <= player_three_score) {
            printf("A ordem crescente: %d, %d, %d.\n", player_one_score, player_two_score, player_three_score);
        } 
        else if (player_three_score <= player_two_score){
            printf("A ordem crescente: %d, %d, %d.\n", player_one_score, player_three_score, player_two_score);
        }
    }

    if (player_two_score <= player_one_score) {
        if (player_one_score <= player_three_score){
            printf("A ordem crescente: %d, %d, %d.\n", player_two_score, player_one_score, player_three_score);
        }
        else if (player_three_score <= player_one_score){
            printf("A ordem crescente: %d, %d, %d.\n", player_two_score, player_three_score, player_one_score);
        }
    }

    if (player_three_score <= player_two_score) {
        if (player_two_score <= player_one_score) {
            printf("A ordem crescente: %d, %d, %d.\n", player_three_score, player_one_score, player_two_score);
        }
        else if (player_one_score <= player_two_score) {
            printf("A ordem crescente: %d, %d, %d.\n", player_three_score, player_two_score,player_one_score);
        }
    }

    sum = player_one_score + player_two_score + player_three_score;
    mean = sum / 3;

    if (sum >= 100) {
        
        printf("Média = %.2lf\n", mean);
    }
    else {
        printf("equipe desclassificada\n");
    }

    return 0;
}