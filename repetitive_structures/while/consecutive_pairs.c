#include <stdio.h>

int main(){

 int pairs, sum;

 scanf("%d", &pairs);

  while(pairs != 0){

  if (pairs % 2 == 0) {
    sum = pairs + (pairs +2) + (pairs + 4) + (pairs +6) + (pairs + 8);
    printf("SOMA = %d\n", sum);

  } else if (pairs % 2 == 1) {
    sum = (pairs + 1) + (pairs +3) + (pairs + 5) + (pairs +7) + (pairs + 9);
    printf("SOMA = %d\n", sum);
  }

  scanf("%d", &pairs); 

  }

  return 0;
  
}