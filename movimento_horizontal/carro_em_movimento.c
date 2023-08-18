#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void clearScreen()
{
  printf("\033[H\033[J");
}

int main()
{
  int movimento_horizontal = 130;
  int posicao_do_carro = 0;
  while (1)
  {
    clearScreen();
  

    for (int i = 0; i < posicao_do_carro; i++)
    {
      printf(" ");
    }

    printf("  ______\n");
    for (int i = 0; i < posicao_do_carro; i++)
    {
      printf(" ");
    }
    printf(" /|_||_\\`.__\n");

    for (int i = 0; i < posicao_do_carro; i++)
    {
      printf(" ");
    }
    printf("(   _    _ _\\\n");

   
    for (int i = 0; i < posicao_do_carro; i++)
    {
      printf(" ");
    }
    printf("=`-(_)--(_)-'\n");

    posicao_do_carro = (posicao_do_carro + 1) % movimento_horizontal;
    usleep(100000);
  }

  return 0;
}
