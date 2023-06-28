// Escreva um programa em C para ordenar um vetor de 5 elementos,
// onde os valores devem ser inseridos pelo usuário. O programa deve incluir 
// três funções: uma função para inserir os elementos no vetor, uma função para ler 
// e exibir os elementos inseridos, e uma função para ordenar o vetor em ordem crescente.
// Escreva o programa em C que atenda a esses requisitos, utilizando as funções solicitadas.

#include <stdio.h>

int ordenar(int vector[]);
void inserir_dados(int vector[]);
void printar(int vector[]);

int main(){

  int vector[4], i, j;

  inserir_dados(vector);
  ordenar( vector);
  printar(vector);

  return 0;
  
}

void inserir_dados(int vector[]){
  int i;

  for(i = 0; i < 5; i++){ 
    scanf("%d", &vector[i]);

  }
  
}

int ordenar( int vector[]){
 int value, i, j;
   for(j = 0; j < 5; j++ ) { 
    for(i = 0; i < 5 - 1; i++){
      if (vector[i] > vector[i +1]){
        value = vector[i];
        vector[i] = vector[i + 1];
        vector[i + 1] = value;
      }

    }

  }
 
}

void printar(int vector[]){
  int i;
  for(i = 0; i < 5; i++){ 
    printf("%d\t",vector[i]);

  }
  

}