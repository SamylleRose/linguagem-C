#include <stdio.h>

int main() {

  int x, y, i, sum = 0, shift;

  scanf("%d%d", &x, &y);

  if (x > y) {
    shift = x;
    x = y;
    y = shift;

    }

    for (i = x + 1; i < y; i++) {
      
      if (i % 2 != 0) { 
        sum = sum + 1;
        
      } 
    }

  printf("%d\n", sum);

  return 0;

}
