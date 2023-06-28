#include <stdio.h>

int main(){

  int i, number = 0;
  double everage = 0, sum = 0;

  scanf("%d", &number);

  double vector[number];

  for (i = 0; i < number; i++){
    scanf("%lf", &vector[i]); 

  }

  printf("VALORES: " );

  for (i = 0; i < number; i++) {
   
    printf("%.1lf  ", vector[i]);
  }
  
  for (i = 0; i < number; i++) {
    sum = sum + vector[i];
  }

  printf("\nSOMA: %.1lf\n", sum);

    everage = sum / number;

  printf("MEDIA: %.1lf\n", everage);

  return 0;

}