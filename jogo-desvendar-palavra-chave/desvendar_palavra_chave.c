#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

void programa();
int main()
{

  char matriz[7][15] = {"semaforo", "elefante", "programador", "matagal", "amazonia", "girafa", "piloto"};
  int tempo = 1;

  char abertura[] =
      "                                       ____                              _           _       \n"
      "                                      |  _ |                            (_)         | |      \n"
      "                                      | |_) | ___ _ __ ___ ________    ___ _ __    _| |  ___ \n"
      "                                      |  _ < / _ | '_ ` _  |______| | / / | '_  |/ _` |/ _  |\n"
      "                                      | |_) |  __/ | | | | |      | V / | | | | | (_| | (_) |\n"
      "                                      |____/|___||_| |_| |_|      |_/   |_|_| |_||__,_||___/ \n";
  printf("%s\n\n", abertura);
  sleep(tempo);
  char ao[] =
      "                                                           __ _   ___                         \n"
      "                                                          / _` |/ _  |                        \n"
      "                                                         | (_| | (_) |                        \n"
      "                                                          |__,_||___/                         \n";
  printf("%s\n\n", ao);
  sleep(tempo);
  printf("                 _ _       _       _                              _                                   _                      \n");
  printf("                | (_)     (_)     | |                            | |                                 | |                     \n");
  printf("       / _` |/ _` | ||  / | | '_ || '_ - / _` | '__| | '_ | / _` | |/ _` | | / | '__|/ _` |______/ __| '_ - / _` | | // _ | \n");
  printf("      | (_| | (_| | || V /| | | | | | | | (_| | |    | |_) | (_| | | (_| || V /| |  | (_| |     | (__| | | | (_| || V | __/ \n");
  printf("       |__,_||__,_|_||_/  |_|_| |_|_| |_||__,_|_|    | .__/ |__,_|_||__,_||_/  |_|   |__,_|      |___|_| |_||__,_||_/ |___| \n");
  printf("                                                     |_|                                                                     \n");

  sleep(tempo);
  printf("\n\n\n\n\n");

  // programa(tamanho_da_palavra, palavra_criptografada, letra_ou_palavra_do_usuario, numero_aleatoria, matriz);

  int resposta;
  do
  {
    programa();
    printf("\n\nDeseja continuar jogando? (1- Sim/ 2 - Não): ");
    scanf("%d", &resposta);

    if (resposta == 2)
    {
      break;
    }

  } while (resposta != 2);
  // if (resposta == 's')
  // {
  //   srand(time(NULL));
  //   int numero_aleatoria = rand() % 6;
  //   int tamanho_da_palavra = strlen(matriz[numero_aleatoria]);
  //   char palavra_criptografada[tamanho_da_palavra], letra_ou_palavra_do_usuario[20], resposta;
  //   programa(tamanho_da_palavra, palavra_criptografada, letra_ou_palavra_do_usuario, numero_aleatoria, matriz);

  // }
  return 0;
}

void programa()
{
  char matriz[7][15] = {"semaforo", "elefante", "programador", "matagal", "amazonia", "girafa", "piloto"};
  int tempo = 1;

  srand(time(NULL));
  int numero_aleatoria = rand() % 7;
  int tamanho_da_palavra = strlen(matriz[numero_aleatoria]);
  char palavra_criptografada[tamanho_da_palavra], letra_ou_palavra_do_usuario[20], resposta;

  printf("Vamos lá, tente adivinhar qual é a palavra. Você tem 5 tentativas!\n\n");

  for (int i = 0; i < tamanho_da_palavra; i++)
  {
    palavra_criptografada[i] = '_';
    printf("%5c", palavra_criptografada[i]);
  }

  int t = 0;
  for (int i = 0; i < 6; i++) // repete o codigo 5 vezes
  {
    if (i < 5) // se a tentativa está dentro do limite ele continua o codigo normalmente.
    {
      printf("\n\nTentativa %d de 5 escreva uma letra ou uma palavra completa: ", i + 1);
      scanf("%s", letra_ou_palavra_do_usuario);

      int verificar_tamanho = strlen(letra_ou_palavra_do_usuario); // verifica o tamanho da palavra que está na matriz

      if (verificar_tamanho == 1) // entra se for uma letra digitada pelo usuario
      {
        for (int i = 0; i < tamanho_da_palavra; i++)
        {
          if (matriz[numero_aleatoria][i] == letra_ou_palavra_do_usuario[0]) // se essa letra estiver na palavra
          {
            palavra_criptografada[i] = letra_ou_palavra_do_usuario[0]; // ela é inserida na posição correta.
          }
        }
        for (int i = 0; i < tamanho_da_palavra; i++)
        {
          printf("%5c", palavra_criptografada[i]); // printa a palavra criptogravada com as letras adivinhadas reveladas.
        }
      }

      else // se for uma palavra digitada pelo usuario entra nessa condição.
      {

        int contador_de_letras_diferentes = 0;

        for (int i = 0; i < tamanho_da_palavra; i++)
        {
          if (matriz[numero_aleatoria][i] != letra_ou_palavra_do_usuario[i]) // verifica se a palavra digitada pelo usuario é diferente
          {
            contador_de_letras_diferentes++; // encrementa
            break;
          }
        }

        if (contador_de_letras_diferentes == 0) // verifica se o contador de erro é igual a zero, se sim...
        {
          printf("\n\nParabéns você acertou! a palavra correta é %s\n\n", letra_ou_palavra_do_usuario); // mensagem parabenizando o usuario pelo acerto.
          break;
        }
        else // se tiver alguma letra errada entra nessa condição e escreve a mensagem.
        {
          printf("\n\nUma pena você errou!\n\n");
        }
      }
    }
    else // se caso o numero de tentativas chegarem a 5 e o usuario não acerta ele encerra com a mensagem.
    {
      printf("\n\nSuas tentativas acabaram!\n\n");
    }
  }
}
