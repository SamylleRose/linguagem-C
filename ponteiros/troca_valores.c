// Escreva um programa em C que troque o valor de duas variáveis usando ponteiros.

#include <stdio.h>

void troca_com_ponteiro(int *ponteironumber1, int *ponteironumber2);

int main(){

  int number1 = 12, number2 = 17;

  printf("valor %d %d\n", number1, number2);

  int *ponteironumber1 = &number1;
  int *ponteironumber2 = &number2;

  troca_com_ponteiro(ponteironumber1,ponteironumber2);

  printf("valor alterado %d %d \n", number1, number2);

  return 0;

}

void troca_com_ponteiro(int *ponteironumber1, int *ponteironumber2){

  *ponteironumber1 = 30;
  *ponteironumber2 = 100;

}