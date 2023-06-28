#include <stdio.h>

int main(){

  int array_order, i, j, negative = 0;

  scanf("%d", &array_order);

  int matriz[array_order][array_order];
  

  for (i = 0; i < array_order; i++){
    for (j = 0; j < array_order; j++){
      scanf("%d", &matriz[i][j]);

    }

  }

  printf("DIAGONAL PRINCIPAL:\n");

  for (i = 0; i < array_order; i++) {
    printf("%d ", matriz[i][i]);

  }

  for (i = 0; i < array_order; i++){
    for (j = 0; j < array_order; j++){
      if ( matriz[i][j] < 0){ 
        negative++;
      }

    }

  }

  printf("\nQUANTIDADE DE NEGATIVOS = %d\n", negative);

  return 0;

}