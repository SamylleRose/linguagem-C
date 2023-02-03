#include <stdio.h>

int main(){

  int value;

  printf("Dígite um número:\n");
  scanf ("%d", &value);

  if(value % 3 == 0) {
    printf("É multiplo de 3\n");
  } else {
    printf("Não é multiplo de 3.\n");
  }

  if(value % 5 == 0){
    printf("É divísivel por 5.\n");
  } else {
    printf("Não é divísivel por 5.\n");
  } 
       
  if(value % 3 == 0 && value % 7 == 0){
    printf("É divísivel por 3 e por 7 ao mesmo tempo.\n");
  } else{
    printf("Não é divísivel por 3 e por 7 ao mesmo tempo.\n");
  }

    return 0;
}