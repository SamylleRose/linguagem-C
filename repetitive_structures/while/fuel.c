#include <stdio.h>

int main(){

  int code,alcohol = 0, gasoline = 0, diesel =0;
  void menu(void);

  menu();
  scanf("%d", &code);

 
  while(code != 4){ 

    switch (code)
    {
    case 1:
      alcohol = alcohol + 1;
      menu();
      printf("\n");
      scanf("%d", &code);
      break;

    case 2:
      gasoline = gasoline + 1;
      menu();
      printf("\n");
      scanf("%d", &code);
      break;
    case 3:
      diesel = diesel + 1;
      menu();
      printf("\n");
      scanf("%d", &code);
      break;

    default:
      printf("TENTE NOVAMENTE!\n");
      menu();
      printf("\n");
      scanf("%d", &code);
      break;

    }
 }
      printf("Obrigada!\n");
      printf("Alcool: %d\nGasolina: %d\nDiesel: %d\n", alcohol, gasoline, diesel);

  return 0;
    
}

void menu(void) {

  printf("========== MENU ==========\n");
  printf("|  CÓDIGO        PRODUTO |\n");
  printf("|    1           ALCOOL  |\n");
  printf("|    2           GASOLINA|\n");
  printf("|    3           DIESEL  |\n");
  printf("|    4           FIM     |\n");
  printf("==========================\n");

}
  