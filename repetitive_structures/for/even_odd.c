#include <stdio.h>

int main(){

int amount_of_values, number, i;

  scanf("%d", &amount_of_values);

  for (i = 1; i <= amount_of_values; i++){

    scanf("%d", &number);

    if (number == 0){
      printf("Nulo\n");

    } else { 

      if ( number % 2 == 0) {
        printf("Par ");

      } else {
        printf("Impar ");

      }

     if (number > 0){
        printf("positivo\n");

      } else {
        printf("Negativo\n");

      } 
    }
  }

  return 0;
}

 
