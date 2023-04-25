#include <stdio.h>

int main(){

  int number = 0, i, number_pairs = 0, sum = 0;
  double evarege = 0;

  scanf("%d", &number);

  int vector[number];

  for (i = 0; i < number; i++){
    scanf("%d", &vector[i]);
    if (vector[i] % 2 == 0) {
      sum = sum + vector[i];
      number_pairs++;

    }

  }

  if ( number_pairs == 0){ 
    printf("NENHUM NUMERO PAR\n");

  } else { 
    evarege = sum / number_pairs;

    printf("MEDIA DOS PARES = %.2lf\n", evarege);

  }

  return 0;

}