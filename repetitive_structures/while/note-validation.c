#include <stdio.h>

int main(){

  double first_note, last_note, everage;

  scanf("%lf", &first_note);

  while((first_note < 0 )||( first_note > 10) ){
    printf("Nota Invalida, Tente Novamente!\n");
    scanf("%lf", &first_note);
  }

  scanf("%lf", &last_note);

  while((last_note < 0 )||( last_note > 10) ){
    printf("Nota Invalida, Tente Novamente!\n");
    scanf("%lf", &last_note);
  }
  everage = (last_note + first_note)/2;
  printf("Média: %.2lf\n", everage);

  return 0;
}