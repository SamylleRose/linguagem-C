#include <stdio.h>

int main(){

    double salaryminimum, salary, amount;

    printf("Informe o valor do seu salário: \n");
    scanf("%lf", &salary);
    printf("Informe o valor do salário mínimo: \n");
    scanf("%lf", &salaryminimum);

    amount = salary / salaryminimum;

    printf("você recebe%2.lf salários mínimos: \n", amount);

    return 0;
}