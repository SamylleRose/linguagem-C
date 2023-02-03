#include <stdio.h>

int main(){
    float salary, percentage, installment_amount, value_installment,  maximum_installment, value_borrowing;

    printf("informe seu salario:\n");
    scanf("%f", &salary);
    printf("Informe a quantidades de prestação:\n");
    scanf("%f", &installment_amount);
    printf("Informe o valor de cada prestação:\n");
    scanf("%f", &value_installment);
    printf("Informe a porcentagem do juros:\n");
    scanf("%f", &percentage);

    maximum_installment = salary * 0.3;
    value_borrowing = ((installment_amount * value_installment) * (percentage/ 100)) + (installment_amount * value_installment); 

    if(value_borrowing < maximum_installment ) {
        printf("O emprestimo e permitido!\n");
    } else {
        printf("O emprestimo nao foi permitido, o valor superou os 30 porcento do seu salario.\n");
    }

    return 0;
}