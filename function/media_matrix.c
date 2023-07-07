#include <stdio.h>

int soma_matrix(int matrix[][3]);
void inserir_dados(int matrix[][3]);

int main(){

  int matrix[3][3];
  double resultado;

  inserir_dados(matrix);
  resultado = soma_matrix(matrix);
  printf("A media da matriz é %.2lf\n", resultado);

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

int soma_matrix(int matrix[][3]){
  int line, column, sum = 0, contador = 0;
  double media;
    
  for(line = 0; line < 3; line++){
    for(column = 0; column < 3; column++){
      sum += matrix[line][column];
      contador += 1;
      
    }

  }

  media = sum / contador;

  return media;

}