#include <stdio.h>

int main(){

  int i, number, major_position = 0;

  scanf("%d", &number);

  double vector[number];

  for (i = 0; i < number; i++){
    scanf("%lf", &vector[i]);
     
  }

  double major = vector[0];

  for (i = 1; i < number; i++){
    if (vector[i] > major){
      major = vector[i];
      major_position = i + 1;

    }
  
  }

  printf("MAIOR VALOR: %.2lf\n", major);
  printf("POSIÇÃO DO MAIOR VALOR: %d\n", major_position);

  return 0;
}