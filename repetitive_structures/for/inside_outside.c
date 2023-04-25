#include <stdio.h>

int main(){

int amount_of_values, number, inside = 0, outside = 0, i;

  scanf("%d", &amount_of_values);

  for (i = 1; i <= amount_of_values; i++){

    scanf("%d", &number);

    if (( number >= 10) && ( number <= 20)){
      inside += 1;

    } else{
      outside += 1;
    }
  }

  printf("%d Dentro\n", inside);
  printf("%d Fora\n", outside);


  return 0;
}