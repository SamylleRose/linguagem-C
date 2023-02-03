#include <stdio.h>

int main(){

    double balance, readjustment;

    printf("Digite seu saldo:\n");
    scanf("%lf", &balance);

    readjustment = (balance * 0.10) + balance;

    printf("Seu novo saldo é de: %.2lf\n", readjustment);

    return 0;
}