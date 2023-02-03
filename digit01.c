#include <stdio.h>

int main(){

  int number, digit1, digit2, digit3;

  printf("Informe um numero de 3 digitos:\n");
  scanf("%d", &number);

  digit3 = number % 10;
  number = number / 10;
  digit2 = number % 10;
  number = number / 10;
  digit1 = number % 10;
   

  if(digit1 % 2 == 0) {
    printf("O primeiro algorismo é par, ");
  } else {
    printf("O primeiro algorismo é impar, ");
  }
  
  if(digit2 % 2 == 0){
    printf("o segundo algorismo é par, ");
  } else {
    printf("o segundo algorismo é impar, ");
  } 
  
  if(digit3 % 2 == 0){
    printf("e o terceiro algorismo é par, ");
  } else {
    printf("e o terceiro algorismo é impar. ");
  }

   

    return 0;

}