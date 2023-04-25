#include <stdio.h>

int main(){

  double number1, number2, number3, everage, case_quantity, i;

  scanf("%lf", &case_quantity);

    for (i = 1; i <= case_quantity; i++) {

      scanf("%lf", &number1);
      scanf("%lf", &number2);
      scanf("%lf", &number3);

      everage = ((number1 * 2) + (number2 * 3) + (number3 * 5)) / 10;
      
      printf("MEDIA = %.1lf", everage);

    }  

  return 0;
}
