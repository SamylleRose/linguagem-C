#include <stdio.h>

int main(){

  int number = 0, i;
  double average = 0, sum = 0 ;

  scanf("%d", &number);

 double vector[number];

  for (i = 0; i < number; i++){
    scanf("%lf", &vector[i]);
    sum = sum + vector[i];

  }
 
  average = sum / number;

  printf("MEDIA DO VETOR = %.3lf\n", average);
  printf("ELEMENTOS ABAIXO DA MEDIA:\n");

  for (i = 0; i < number; i++){ 
    if (average > vector[i]){
    printf("%.2lf\n", vector[i]);

    }
   
  }

  return 0;

}