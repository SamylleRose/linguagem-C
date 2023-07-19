#include <stdio.h>

void matrixinversa2x2( int number, float matrix[][number]);
void matrixidentidade2x2( int number,float matrix[][number]);
void printar(int number, float matrix[][number]);
int menu();
void calculo(int codigo, int number ,float matrix[][number]);
void inserir_dados(int number, float matrix[][number]);

int main(){

  int number, codigo;

  scanf("%d", &number);

  float matrix[number][number];
  printf("\n");

  inserir_dados(number, matrix);
  printf("\n");
  codigo = menu();
  calculo(codigo, number, matrix);
  printar(number, matrix);


  return 0;

}

void inserir_dados(int number, float matrix[][number]){
  int i, j;

  for(i = 0; i < number; i++){
    for(j = 0; j <number; j++){
      scanf("%f", &matrix[i][j]);

    }
  }
 printf("\n");
}

int menu(){
  int codigo;

  printf("=================================MENU =============================\n");
  printf("|            OPÇÃO                                 CÓDIGO         |\n");
  printf("|   Matriz inversa                                    1           |\n");
  printf("|   Matriz identidade                                 2           |\n");
  printf("|   Matriz transposta                                 3           |\n");
  printf("===================================================================\n");

  printf("\n");
  scanf("%d", &codigo);

  return codigo;
}

void calculo(int codigo, int number, float matrix[][number]){

  if ( codigo == 1){
   matrixinversa2x2(number, matrix);

  }

  else if(codigo == 2){
    matrixidentidade2x2(number,matrix);

  }

  else if(codigo == 3){

  }

}

void printar(int number, float matrix[][number]){
  int i, j;

  for(i = 0; i < number; i++){
    for(j = 0; j < number;j++){
      printf("%.2f ",matrix[i][j]);

    }

    printf("\n");
    
  }

}

void matrixinversa2x2( int number, float matrix[][number]){
  int diagonal1, diagonal2, determinante, i, j, troca;
 
  diagonal1 = matrix[0][0] * matrix[1][1];
  diagonal2 = matrix[0][1]* matrix[1][0];

  determinante = diagonal1 - diagonal2;

  for(i = 0; i < number; i++){
    for(j = 0; j < number; j++){
      matrix[i][j] = matrix[i][j] / determinante;

    }

  }

  troca = matrix[0][0];
  matrix[0][0] = matrix[1][1];
  matrix[1][1] = troca;

  for(i = 0; i < number; i++){
    for(j = 0; j < number; j++){
     matrix[i][j] = matrix[i][j] * -1;

    }

  }


  
}
 
void matrixidentidade2x2( int number, float matrix[][number]){ 
  int i, j;

  for(i = 0; i < number; i++){
    for(j = 0; j < number; j++){
      
      if (i==j){
        matrix[i][j] = 1;

      }

      else { 
        matrix[i][j] = 0;

      } 

    }
    
  }

}