#include <stdio.h>

int main() {

  int dish, dessert, drink,drink_calorie, dish_calorie, dessert_calorie, total_calories;

  printf("\n");
  printf("================= MENU =================\n");
  printf("|                                      |\n");
  printf("|  PRATOS:                 DIGITE:     |\n");
  printf("|                                      |\n");
  printf("|  Vegetariano               01        |\n");
  printf("|  Peixe                     02        |\n");
  printf("|  Frango                    03        |\n");
  printf("|  Carne                     04        |\n");
  printf("|                                      |\n");
  printf("|  SOBREMESA               DIGITE:     |\n");
  printf("|                                      |\n");
  printf("|  Abacaxi                   05        |\n");
  printf("|  Sorvete Diet              06        |\n");
  printf("|  Mousse Diet               07        |\n");
  printf("|  Mousse de Chocolate       08        |\n");
  printf("|                                      |\n");
  printf("|  BEBIDAS                 DIGITE:     |\n");
  printf("|  Chá                       09        |\n");
  printf("|  Suco de Laranja           10        |\n");
  printf("|  Suco de Melão             11        |\n");
  printf("|  Refrigerante Diet         12        |\n");
  printf("|                                      |\n");
  printf("========================================\n");
  printf("\n");

  scanf("%d", &dish);
  scanf("%d", &dessert);
  scanf("%d", &drink);

  if (dish == 1) {
    dish_calorie = 180; 
  } else if (dish == 2) {
    dish_calorie = 230;
  } else if (dish == 3) {
    dish_calorie = 250;
  } else if (dish == 4) {
    dish_calorie = 350;
  }
  
  if (dessert == 5) {
    dessert_calorie = 75; 
  } else if (dessert == 6) {
    dessert_calorie = 110;
  } else if (dessert == 7) {
    dessert_calorie = 170;
  } else if (dessert == 8) {
    dessert_calorie = 200;
  }

  if (drink == 1) {
    drink_calorie = 20;  
  } else if (drink == 2) {
    drink_calorie = 70;
  } else if (drink == 3) {
    drink_calorie = 100;
  } else if (drink == 4) {
    drink_calorie = 65;
  }

  total_calories = drink_calorie + dish_calorie + dessert_calorie;

  printf(" Total de calorias é: %dcal\n", total_calories);

  return 0;

}