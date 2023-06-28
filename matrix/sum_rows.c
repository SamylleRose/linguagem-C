#include <stdio.h>

int main(){

  int L,C, i, j, sum1 = 0, sum2 = 0;

  scanf("%d", &L);
  scanf("%d", &C);

  int matriz[L][C];
  

  for (i = 0; i < L; i++){
    for (j = 0; j < C; j++){
      scanf("%d", &matriz[i][j]);

    }

  }

  for(j = 0; j > C; j++){
     sum1 = sum1 + matriz[0][j];

  }

  for(j = 0; j > C; j++){
     sum2 = sum2 + matriz[1][j];

  }

  printf("VETOR GERADO:\n");
  printf("%d", sum1);
  printf("%d", sum2);
  
  return 0;

}