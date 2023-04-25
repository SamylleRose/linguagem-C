#include <stdio.h>

int main(){

  int number, i, j, purchase_price, selling_price = 0, percentage_profit = 0 ;

  scanf("%d", &number);

  char matriz_name[number][20];

  double vector_purchase_price[number], vector_selling_price[number], Profit_below_10 = 0, Profit_between_10_and_20 = 0, Profit_over_20 = 0, Total_purchase_amount = 0, total_sale_value = 0, total_profit = 0;

  for(i = 0; i < number; i++){
    printf("Produto %d:\n", i + 1);
    printf("Nome: ");
    scanf("%s", &matriz_name[i][0]);
    printf("Preco de compra: ");
    scanf("%lf", &vector_purchase_price[i]); // preco de compra
    printf("Preco de venda: ");
    scanf("%lf", &vector_selling_price[i]); //preco de venda
    
  }

  for(i = 0; i < number; i++){

    percentage_profit = ((vector_selling_price[i] - vector_purchase_price[i]) * 100) / vector_purchase_price[i];
     
    if (percentage_profit < 10){
      Profit_below_10++;

    } else if (percentage_profit >= 10 && percentage_profit <= 20){
      Profit_between_10_and_20++;

    } else if (percentage_profit > 20){
      Profit_over_20++;

    }

  }

  for(i = 0; i < number; i++){  // total de compra
    Total_purchase_amount = Total_purchase_amount + vector_purchase_price[i];

  }

  for(i = 0; i < number; i++){  // total de venda
    total_sale_value = total_sale_value + vector_selling_price[i];

  }

  for(i = 0; i < number; i++){  // lucro total
    total_profit = total_sale_value - Total_purchase_amount;

  }

  printf("RELATORIO\n");
  printf("Lucro abaixo de 10%%: %.2lf\n", Profit_below_10);
  printf("Lucro entre 10%% e 20%%: %.2lf\n",Profit_between_10_and_20);
  printf("Lucro acima de 20%%: %.2lf\n", Profit_over_20);
  printf("Valor total de compra: %.2lf\n", Total_purchase_amount);
  printf("Valor total de venda: %.2lf\n", total_sale_value);
  printf("Lucro total: %.2lf\n", total_profit);

  return 0;

}