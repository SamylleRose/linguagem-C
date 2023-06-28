#include <stdio.h>

int main(){

  int number = 0, i, sum = 0;
  
  scanf("%d", &number);

  int vector[number];

  for (i = 0; i < number; i++){

    scanf("%d", & vector[i]);

  }

  printf("NUMEROS PARES:\n");

  for (i = 0; i < number; i++){
    if (vector[i] % 2 == 0){

      printf("%d ", vector[i]);
    }

  }

  for (i = 0; i < number; i++){
    if (vector[i] % 2 == 0){
      sum += 1;
      
    }

  }

  printf("QUANTIDADE DE PARES: %d\n", sum );

  return 0;
}