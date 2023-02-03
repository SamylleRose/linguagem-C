#include <stdio.h>

int main() {

  int x, y;


  while (x != y) {
    scanf("%d%d", &x, &y);

    if (x > y){
      printf("Ordem descrente\n");
    } else if ( x < y) {
      printf("Ordem crescente\n");
    }
  }


  return 0;
}