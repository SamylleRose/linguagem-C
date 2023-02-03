#include <stdio.h>

int main(){

    double weight, gramme;

    printf("Informe seu peso em quilos:\n");
    scanf("%lf", &weight);

    gramme = weight * 1000;

    printf("%3.lfkg em gramas é %3.lfg\n", weight, gramme);

    return 0;
} 