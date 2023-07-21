// Escreva um programa em C que encontre o maior valor presente no array utilizando
// ponteiros. O usuário deve digitar o tamanho do vetor e os seus elementos.
#include <stdio.h>

int main(){

  int vector[5] = {1,2,4,5,70}, number= vector[0];

  for (int i = 0; i < 5; i++){
    if (number < *vector + i){
      number = vector[i]; 

    }

  }

  printf("O maior numero é: %d\n", number);

  return 0;
}




