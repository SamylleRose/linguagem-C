#include <stdio.h>

int main(){

  int age, cont;
  double sum;
  scanf("%d", &age);

  if (age < 0) {
    printf("Impossivel de Calcular!\n");
    }

  while (age >= 0){
    cont = cont + 1;
    sum = age + sum;
    scanf("%d", &age);   
  }
  
  printf("%.2lf\n", sum / cont);

  return 0;
}