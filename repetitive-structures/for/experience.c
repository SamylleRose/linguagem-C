#include <stdio.h>

int main(){ 

  double total_guinea_pigs = 0, total_c = 0, total_r = 0, total_s = 0, i, case_quantity = 0, amount_guinea_pigs = 0;
  double percentage_c = 0, percentage_r = 0, percentage_s = 0;
  char digit = ' ';
  scanf("%lf", &case_quantity);

  for (i = 1; i <= case_quantity; i++){ 

    printf("Quantidade de cobaias:\n");
    scanf("%lf", &amount_guinea_pigs);
    printf("Tipo de cobaia:\n");
    scanf(" %c", &digit);

    if (digit == 'c'){
      total_c = amount_guinea_pigs + total_c;

    }

    if(digit == 'r'){
      total_r = amount_guinea_pigs + total_r;

    }

    if(digit == 's'){
      total_s = amount_guinea_pigs + total_s;
      
    }

    total_guinea_pigs = amount_guinea_pigs + total_guinea_pigs;
    
  }

  percentage_c = (100 * total_c)/ total_guinea_pigs;
  percentage_r = (100 * total_r)/ total_guinea_pigs;
  percentage_s = (100 * total_s)/ total_guinea_pigs;

  printf("========RELATORIO FINAL========\n");
  printf("|TOTAL DE COBAIAS:     %.0lf    |\n", total_guinea_pigs);
  printf("|TOTAL DE COELHOS:     %.0lf    |\n", total_c);
  printf("|TOTAL DE RATOS        %.0lf    |\n", total_r);
  printf("|TOTAL DE SAPOS:       %.0lf    |\n", total_s);
  printf("|PERCETUAL DE COELHOS: %.2lf  |\n", percentage_c);
  printf("|PERCENTUAL DE RATOS:  %.2lf  |\n", percentage_r);
  printf("|PERCENTUAL DE SAPOS:  %.2lf  |\n", percentage_s);
  printf("===============================\n");

  return 0;
}