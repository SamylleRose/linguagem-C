#include <stdio.h>

int main(){

  double n1, n2, m;

  printf("Digite a primeira nota:\n");
  scanf("%lf", &n1);
  printf("Digite a segunda nota:\n");
  scanf("%lf", &n2);

  m = (n1 + n2)/2;

  printf("A média aritmética das duas notas é: %.2lf\n", m);
  return 0;
}