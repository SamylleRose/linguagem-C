#include <stdio.h>

int main(){

  int i, case_quantity ;
  double denominator, numerator, division;

  scanf("%d", &case_quantity);
  
  for (i = 1; i <= case_quantity; i++) {
    
    scanf("%lf", &numerator);
    scanf("%lf", &denominator);
    if ( denominator == 0) {
      printf("Divisão Impossivel\n");
     
    } else { 
      division = numerator / denominator;

      printf("Divisão %.2lf\n", division);

    }

  }  

  return 0;

}
