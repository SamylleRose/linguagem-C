#include <stdio.h>

int main(){

  int number = 0, i = 0, sum = 0;
  double average = 0, total_height = 0;
  void limpar_entrada();
  void ler_texto(char *buffer, int length) {
  fgets(buffer, length, stdin);
       
  }
  
  printf("Quantas pessoas serao digitadas? ");
  scanf("%d", &number);

  char name[number][50];
  int age[number], minor = 0;
  double height[number], percentage = 0;

  for (i = 0; i < number; i++){
    printf("Dados da %d° pessoa:", i + 1);
    limpar_entrada();
    ler_texto(name[i], 50);
    printf("Idade: ");
    scanf("%d", &age[i]);
    printf("Altura: ");
    scanf("%lf", &height[i]); 

  }

  for (int i = 0; i < number; i++) {
    if (age[i] < 16) {
      minor++;
    }
       total_height = total_height + height[i];
    }

  average = total_height / number;
  printf("ALTURA MEDIA: %.2lf\n", average);

  percentage = (minor/ number) * 100.0;
  printf("PORCENTAGEM DE MENORES DE 16 ANOS %.2lf%%\n", percentage);

  for(int i = 0; i < number; i++) {
        if (age[i] < 16) {
            printf("%s", name[i]);
        }
    }

  return 0;

} 

void limpar_entrada() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

