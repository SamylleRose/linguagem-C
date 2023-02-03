#include <stdio.h>

int main(){

    double valuetime, amounttime, valuegross, INSS, valueliquid; 

    printf("Digite o valor por hora:\n");
    scanf("%lf", &valuetime);
    printf("Digite a quantidade de horas trabalhada:\n");
    scanf("%lf", &amounttime);
    printf("Digite a porcentagem do seu INSS:\n");
    scanf("%lf", &INSS);

    valuegross = valuetime * amounttime;
    valueliquid = valuegross - INSS/100; 

    printf("O valor do seu sálario líquido é: %.2lf\n", valueliquid);

    return 0;
}