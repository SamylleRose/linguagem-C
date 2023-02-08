#include <stdio.h>

int main(){

    int quantity, quantity_total;
    double value_rent, late_overdue, quantity_rent, yearly, reset, spoil;

    printf("Informe a quantidade de DVDs e o valor por aluguel, respectivamente:\n");
    scanf("%d%lf", &quantity, &value_rent);

    quantity_rent = (quantity/3) * value_rent;
    late_overdue = ((quantity/10) * 9) * (value_rent + (value_rent * 0.10)); 
    yearly = (quantity_rent + late_overdue) * 12;

    printf("O faturamento anual é de R$ %.2lf\n", yearly);
    
    spoil = quantity * 0.02;
    reset = spoil/10;
    quantity_total = quantity - ((spoil + reset) * 12);

    printf("a quantidade total de DVDs da locadora após um ano é de %d\n", quantity_total);
       
    return 0;
}
