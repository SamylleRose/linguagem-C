#include <stdio.h>

void inserir_dados(int matrix[][3]);
int soma_diagonal(int matrix[][3]);

int main(){

  int matrix[3][3], resultado;

  inserir_dados(matrix);
  resultado = soma_diagonal(matrix);
  printf("A soma das diagonais é %d\n", resultado);


  return 0;
}

void inserir_dados(int matrix[][3]){
  int line, column;

  for(line = 0; line < 3; line++){
    for(column = 0; column < 3; column++){
      scanf("%d", &matrix[line][column]);

    }
  }

}

int soma_diagonal(int matrix[][3]){
  int i, sum = 0;

  for(i = 0; i < 3; i++){
    sum += matrix[i][i];
    
    
  }

  return sum;

}