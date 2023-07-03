#include <stdio.h>
#include <math.h>

void pg(int vector[], int numero_inicial, int razao);

int main(){

int vector[10], razao, numero_inicial;

  scanf("%d%d", &numero_inicial, &razao);
  pg(vector, numero_inicial, razao);

  return 0;

}

void pg(int vector[], int numero_inicial, int razao){
  int  i;

  for(i = 0; i < 10; i++){ 
   
    vector[i] = numero_inicial * (pow(razao, i ));
    printf("%d\n", vector[i]);
    
  }



}