#include <stdio.h>

int main(){

  int L,C, i, j;

   
  scanf("%d", &L);
  scanf("%d", &C);

  int a[L][C], b[L][C], c[L][C];


  
  printf("Matriz A:\n");
  for (i = 0; i < L; i++){
    for (j = 0; j < C; j++){
      scanf("%d", &a[i][j]);

    }

  }

  printf("Matriz B:\n");
  for (i = 0; i < L; i++){
    for (j = 0; j < C; j++){
      scanf("%d", &b[i][j]);

    }

  }

  printf("Matriz C:\n");

  for (i = 0; i < L; i++){ 
    for (j = 0; j < C; j++){
      c[i][j] =  a[i][j] + b[i][j];
      printf("%3d", c[i][j]);

    }

  printf("\n");

  }

  
  return 0;

}