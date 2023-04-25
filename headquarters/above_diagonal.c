#include <stdio.h>

 int main(){

  int number, l, c, sum = 0;

  scanf("%d", &number);

  int matriz[number][number];

  for (l = 0; l < number; l++){
    for (c = 0; c < number; c++){

     scanf("%d", &matriz[l][c]);

    }

  }

  for (l = 0; l < number; l++){
    for (c = 0; c < number; c++){
      if (l < c){ 
      sum = sum + matriz [l][c];

      }

    }

  }
   
  printf("SOMA DOS ELEMENTOS ACIMA DA DIAGONAL PRINCIPAL = %d\n", sum);

  return 0;

 }