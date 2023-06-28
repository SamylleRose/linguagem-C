#include <stdio.h>

int main(){

int password;

scanf("%d", &password);

while (password != 2002) {
  printf("Senha Invalida! Tente novamente:\n");
  scanf("%d", &password);

}

if (password = 2002){
  printf("Acesso Permitido!\n");
}

  return 0;

}