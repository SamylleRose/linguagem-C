#include <stdio.h>

void inserir_dados(int line, int column, int matrix[line][column]);
int menu();
void calculo(int codigo, int line, int column, int matrix[line][column]);
void printar(int column, int line, int matrix[line][column]);
void matrixidentidade( int line, int column, int matrix[line][column]);

int main(){

  int line, column, codigo;

  scanf("%d%d", &line, &column);

  int matrix[line][column];
  printf("\n");

  inserir_dados(line, column, matrix);
  printf("\n");
  codigo = menu();
  calculo(codigo, line, column, matrix);
  printar(column, line, matrix);


  return 0;

}

void inserir_dados(int line, int column, int matrix[line][column]){
  int i, j;

  for(i = 0; i < line; i++){
    for(j = 0; j < column; j++){
      scanf("%d", &matrix[i][j]);

    }
  }

}

int menu(){
  int codigo;

  printf("=================================MENU =============================\n");
  printf("|            OPÇÃO                                 CÓDIGO         |\n");
  printf("|   Matriz inversa                                    1           |\n");
  printf("|   Matriz identidade                                 2           |\n");
  printf("|   Matriz transposta                                 3           |\n");
  printf("===================================================================\n");

  scanf("%d", &codigo);

  return codigo;
}

void calculo(int codigo, int line, int column, int matrix[line][column]){

  if ( codigo == 1){

   

  }

  else if(codigo == 2){

    matrixidentidade(line, column,matrix);

  }

  else if(codigo == 3){


  }


}

void printar(int column, int line, int matrix[line][column]){
  int i, j;

  for(i = 0; i < line; i++){
    for(j = 0; j < column; j++){
      printf("%d",matrix[i][j]);

    }

    printf("\n");
    
  }

}

void matrixinversa( int line, int column, int matrix[line][column]){
  int i, j, diagonal1, diagonal2;

  for(i = 0; i < line; i++){
    diagonal1 = matrix[i][i] * matrix[i + 1][i + 1];

  }


    
  
}
 



void matrixidentidade( int line, int column, int matrix[line][column]){ 
  int i, j;

  for(i = 0; i < line; i++){
    for(j = 0; j < column; j++){
      
      if (i==j){
        matrix[i][j] = 1;

      }

      else { 
        matrix[i][j] = 0;

      }
      

    }
    
  }


}