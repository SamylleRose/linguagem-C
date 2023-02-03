#include <stdio.h>

void main() {
  char name[20], surname[20];
    

  printf("Digite seu primeiro nome:\n");
  scanf("%s", name);
  printf("Digite seu sobrenome:\n");
  scanf("%s", surname);

  printf("%s %s\n", name, surname);
        
}