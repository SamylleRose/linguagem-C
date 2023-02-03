#include <stdio.h>

int main(){

    double hour, minutes, seconds, milliseconds;

    printf("Digite a quantidade em horas:\n");
    scanf("%lf", &hour);

    minutes = hour * 60;
    seconds = minutes * 60;
    milliseconds = seconds * 1000;

    printf("%2.lf horas corresponde a %2.lf minutos %2.lf segundos e %2.lf milissegundos\n", 
    hour, minutes, seconds, milliseconds);

    return 0;
}