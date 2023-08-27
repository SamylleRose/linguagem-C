#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sorteio_numerico(int *numero_sorteado);
void numero_do_jogador(int numero_sorteado);

int main()
{

  int numero_sorteado = 0;
  printf("\nBem-vindo ao Jogo de Adivinhação de Números!\n");
  sorteio_numerico(&numero_sorteado);
  numero_do_jogador(numero_sorteado);

  return 0;
}

void sorteio_numerico(int *numero_sorteado)
{
  srand(time(NULL));
  *numero_sorteado = rand() % 100;
  // printf("%d\n", *numero_sorteado);
}

void numero_do_jogador(int numero_sorteado)
{

  int numero_do_palpite;
  printf("Tente adivinhar o número secreto entre 1 e 100.\n");
  for (int i = 0; i < 5; i++)
  {

    printf("Tentativa %d de 5: Insira seu palpite: ", i + 1);
    scanf("%d", &numero_do_palpite);

    if (i == 4)
    {
      printf("\nInfelizmente suas tentativas acabaram.\n");
    }

    else if (numero_do_palpite > numero_sorteado)
    {
      printf("\nTente um número menor!\n");
    }
    else if (numero_do_palpite < numero_sorteado)
    {
      printf("\nTente um número maior!\n");
    }
    else if (numero_do_palpite == numero_sorteado)
    {

      printf("Parabéns! Você acertou o número secreto %d em %d tentativas. \n", numero_sorteado, i + 1);
      break;
    }
  }
}