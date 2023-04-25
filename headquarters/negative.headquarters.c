#include <stdio.h>

int main(){

  int L, C, i, j, negative = 0;

  scanf("%d", &L);
  scanf("%d", &C);

  int matriz[L][C];
  

  for (i = 0; i < L; i++){
    for (j = 0; j < C; j++){
      scanf("%d", &matriz[i][j]);

    }

  }

  printf("VALORES NEGATIVOS:\n");

  for (i = 0; i < L; i++){
    for (j = 0; j < C; j++){
      if ( matriz[i][j] < 0){ 
        negative = matriz [i][j];
        printf("%d\n", negative);
      }

    }

  }

  return 0;

}