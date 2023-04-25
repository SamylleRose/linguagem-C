#include <stdio.h>

int main(){

  int i, number;

  scanf("%d", &number);

  int A[number], B[number], C[number];

  printf("VECTOR A:\n");

  for (i = 0; i < number; i++){ 
    scanf("%d", &A[i]);
     
  }

  printf("VECTOR B:\n");
  
  for (i = 0; i < number; i++){
    scanf("%d", &B[i]);
  
  }

  printf("VETOR RESULTANTE:\n");

  for (i = 0; i < number; i++){
    C[i] = A[i] + B[i];
    printf("%d\n", C[i]);
  
  }

  return 0;
}