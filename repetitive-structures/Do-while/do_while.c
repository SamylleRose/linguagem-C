#include <stdio.h>

int main (){

  double c, f;
  char resp;
  void clear_entry();

  do {
    printf("Digite a temperatura em Celsius: ");
    scanf("%lf", &c);
    f = 9.0 * c / 5.0 + 32.0;
    printf("Equivalente em Fahrenheit: %.1lf\n", f);
    printf("Deseja repetir (s/n)? ");
    clear_entry();
    scanf("%c", &resp);
  } while (resp == 's');

  return 0;
}

void  clear_entry() {
char c;
while ((c = getchar()) != '\n' && c != EOF) {}

} 

