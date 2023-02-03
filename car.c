#include <stdio.h>

int main(){

    double averagespeed, travelhours, gasoline, distance;

    printf("Qual foi a velocidade média em km/h? \n");
    scanf("%lf", &averagespeed);
    printf("Quantas horas durou a viagem? \n ");
    scanf("%lf", &travelhours);

    distance = averagespeed * travelhours;

    gasoline = distance / 12;

    printf("A distancia percorrida será de %.2lfkm e serão gastos %.2lf litros de gasolina.\n", distance, gasoline);
    
    return 0;
}