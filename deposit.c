#include <stdio.h>

int main(){
 
    double deposit, fees, income, totalincome;

    printf("Informe o valor do depósito e a taxa de juros, respectivamente:\n");
    scanf("%lf%lf", &deposit, &fees);

    income = deposit * (fees / 100);
    totalincome = income + deposit;

    printf("O rendimento foi de %.2lf, e o valor total é de %.2lf\n", income, totalincome);
    
    return 0;
}