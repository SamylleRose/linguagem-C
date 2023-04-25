#include <stdio.h>

int main(){

  int number = 0, i;
 
  scanf("%d", &number);

  int vect[number];

  for (i = 0; i < number; i++){
    scanf("%d", &vect[i]);

  }
  printf("\n");

  for (i = 0; i < number; i++){
    if ( vect[i] < 0){
      printf("%d\n", vect[i]);
    }
  }

  return 0;
}