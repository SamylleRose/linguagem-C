#include <stdio.h>

void ler_arquivo(char *nome);

int main(){

  char *nome = "teste.txt";
  ler_arquivo(nome);

  return 0;
}

void ler_arquivo(char *nome){

  FILE *arquivo;

  arquivo = fopen(nome, "r");

  if(arquivo == NULL){
    printf("Erro na leitura do arquivo!\n");

  } else {
    printf("Leitura concluida com sucesso!\n");

  }

  fclose(arquivo);

}

