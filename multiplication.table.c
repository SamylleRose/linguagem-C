#include <stdio.h>

int main(){

  int number, mul_table, i;

  scanf("%d", &number);

  for (i = 1; i <= 10; i++) {
    mul_table = number * i;
    printf("%d X %d = %d\n", number, i, mul_table);

  }  

  return 0;
}
