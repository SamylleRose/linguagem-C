#include <stdio.h>

int main(){

  int n, factorial = 1, i;

  scanf("%d", &n);

    for (i = n; i > 0; i--) {  
    factorial = factorial * i;

    }  

  printf("%d\n", factorial);

  return 0;

}
