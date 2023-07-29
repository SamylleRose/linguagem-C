#include <stdio.h>

int main(){

  int vector[5] = {1, 2, 3, 4, 5}, i, j, value;


  // for (i = 0; i < 5; i++) {
  //   for (j = 0; j < 5 - i - 1; j++) {
  //     if (vector[j] > vector[j + 1]) {
  //       value = vector[j];
  //       vector[j] = vector[j + 1];
  //       vector[j + 1] = value;
  //     }
  //   }
  // }

  for (i = 0; i < 5; i++) {
    for (j = 1; j < 5 - i; j++) {
      if (vector[j] > vector[j - 1]) {
        value = vector[j];
        vector[j] = vector[j - 1];
        vector[j - 1] = value;
      }
    }
  }

  for(i = 0; i < 5; i++){ 
    printf("%3d",vector[i]);

  }

  return 0;
}