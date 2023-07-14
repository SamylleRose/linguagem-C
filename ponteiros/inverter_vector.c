#include <stdio.h>

int main(){

  int vector[5] = {1, 2, 3, 4, 5}, i, j, value;


  for(j = 0; j < 5; j++ ) { 
    for(i = 0; i < 5 - 1; i++){
      if (vector[i] > vector[i +1]){
        value = vector[i];
        vector[i] = vector[i + 1];
        vector[i + 1] = value;
        printf("%d\t",vector[i]);
      }

    }

  }

  for(i = 0; i < 5; i++){ 
    printf("%d\t",vector[i]);

  }

  return 0;

}