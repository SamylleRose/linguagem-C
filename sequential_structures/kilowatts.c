#include <stdio.h>

int main(){

    double salary, kilowatts, eachekilowatts, discount, account;

    printf("Informe seu sálario minimo:\n");
    scanf("%lf", &salary);
    printf("Informe a quantidade de quilowatts gastos:\n");
    scanf("%lf", &kilowatts);

    eachekilowatts = (salary/7)/100;
    account = kilowatts * eachekilowatts;
    discount = account - account * 0.10 ;

    printf("O valor de cada quilowatts é de %.2lf, o valor a pagar é de %.2lf, com o desconto, o valor total é de %.2lf\n", eachekilowatts, account, discount);

    return 0;
}