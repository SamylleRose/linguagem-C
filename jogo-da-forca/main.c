#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void carregar_arquivo_frutas(int *quantidade_de_palavras_de_frutas, char matrizfruta[][50]);
void carregar_arquivo_paises(int *quantidade_de_palavras_de_paises, char matrizpaises[][50]);
void carregar_arquivo_animais(int *quantidade_de_palavras_de_animais, char matrizanimais[][50]);
void programa(int quantidade_de_palavras_de_frutas, int quantidade_de_palavras_de_paises, int quantidade_de_palavras_de_animais, char matrizfrutas[][50], char matrizpaises[][50], char matrizanimais[][50]);
void menu();
void criptografar_palavra(int tamanho_da_palavra, char *palavra_a_ser_criptografada);
void verificacao(int tamanho_da_palavra, int numero_aleatorio, char matriz[][50], char palavra_criptografada[], int *erros);

int main()
{
  int quantidade_de_palavras_de_frutas, quantidade_de_palavras_de_paises, quantidade_de_palavras_de_animais;
  char matrizfrutas[20][50], matrizpaises[20][50], matrizanimais[20][50];

  carregar_arquivo_frutas(&quantidade_de_palavras_de_frutas, matrizfrutas);
  carregar_arquivo_paises(&quantidade_de_palavras_de_paises, matrizpaises);
  carregar_arquivo_animais(&quantidade_de_palavras_de_animais, matrizanimais);
  printf("\n\n\n\n");
  printf("    Bem-vindo ao jogo da forca!\n\n");
  programa(quantidade_de_palavras_de_frutas, quantidade_de_palavras_de_paises, quantidade_de_palavras_de_animais, matrizfrutas, matrizpaises, matrizanimais);
  // for (int i = 0; i < quantidade_de_palavras_de_frutas; i++) {
  //     printf("%s\n", matrizfrutas[i]);
  // }

  //  for (int i = 0; i < quantidade_de_palavras_de_paises; i++) {
  //     printf("%s\n", matrizpaises[i]);
  // }

  // for (int i = 0; i < quantidade_de_palavras_de_animais; i++) {
  //     printf("%s\n", matrizanimais[i]);
  // }

  return 0;
}

void carregar_arquivo_frutas(int *quantidade_de_palavras_de_frutas, char matrizfrutas[][50])
{
  int i;
  char linha[150];
  FILE *fp;
  fp = fopen("frutas.txt", "r");

  for (i = 0; fgets(linha, sizeof(linha), fp) != NULL; i++)
  {
    sscanf(linha, "%s", matrizfrutas[i]);
  }

  *quantidade_de_palavras_de_frutas = i;

  fclose(fp);
}

void carregar_arquivo_paises(int *quantidade_de_palavras_de_paises, char matrizpaises[][50])
{
  int i;
  char linha[150];
  FILE *fp;
  fp = fopen("paises.txt", "r");

  for (i = 0; fgets(linha, sizeof(linha), fp) != NULL; i++)
  {
    sscanf(linha, "%s", matrizpaises[i]);
  }

  *quantidade_de_palavras_de_paises = i;

  fclose(fp);
}

void carregar_arquivo_animais(int *quantidade_de_palavras_de_animais, char matrizanimais[][50])
{
  int i;
  char linha[150];
  FILE *fp;
  fp = fopen("animais.txt", "r");

  for (i = 0; fgets(linha, sizeof(linha), fp) != NULL; i++)
  {
    sscanf(linha, "%s", matrizanimais[i]);
  }

  *quantidade_de_palavras_de_animais = i;

  fclose(fp);
}

void menu()
{
  printf("=================================                         +---+\n");
  printf("         ESCOLHA UM TEMA                                  |   |\n");
  printf("=================================                         O   |\n");
  printf("1. Frutas                                                /|\\  |\n");
  printf("2. Paises                                                / \\  |\n");
  printf("3. Animais                                                    |\n");
  printf("=================================                         =========\n");
}

void programa(int quantidade_de_palavras_de_frutas, int quantidade_de_palavras_de_paises, int quantidade_de_palavras_de_animais, char matrizfrutas[][50], char matrizpaises[][50], char matrizanimais[][50])
{

  int numero_aleatorio = 0, numero_do_tema = 0, i;
  int tamanho_da_palavra = 0;
  char palavra_a_ser_criptografada[50], resposta;
  int erros = 0;

  menu();
  do
  {

    printf("\nInsira o número correspondente a sua escolha: ");
    scanf("%d", &numero_do_tema);
    srand(time(NULL));

    switch (numero_do_tema)
    {
    case 1:
      numero_aleatorio = rand() % quantidade_de_palavras_de_frutas;
      tamanho_da_palavra = strlen(matrizfrutas[numero_aleatorio]);

      printf("%s\n", matrizfrutas[numero_aleatorio]);

      criptografar_palavra(tamanho_da_palavra, palavra_a_ser_criptografada);
      verificacao(tamanho_da_palavra, numero_aleatorio, matrizfrutas, palavra_a_ser_criptografada, &erros);

      break;

    case 2:

      break;
    case 3:

      break;

    default:

      break;
    }
  } while (erros == 6);
}

void criptografar_palavra(int tamanho_da_palavra, char *palavra_a_ser_criptografada)
{

  for (int i = 0; i < tamanho_da_palavra; i++)
  {
    palavra_a_ser_criptografada[i] = '_';
    printf("%5c", palavra_a_ser_criptografada[i]);
  }
}

void verificacao(int tamanho_da_palavra, int numero_aleatorio, char matriz[][50], char palavra_criptografada[], int *erros)
{
  char letra_ou_palavra_do_usuario[20];

  for (int i = 0; i < 7; i++)
  {
    if (i < 6)
    {
      printf("\nEscreva uma letra ou uma palavra completa: ");
      scanf("%s", letra_ou_palavra_do_usuario);
      int verificar_tamanho = strlen(letra_ou_palavra_do_usuario);
      if (verificar_tamanho == 1) // entra se for uma letra digitada pelo usuario
      {
        for (int i = 0; i < tamanho_da_palavra; i++)
        {
          if (matriz[numero_aleatorio][i] == letra_ou_palavra_do_usuario[0]) // se essa letra estiver na palavra
          {
            palavra_criptografada[i] = letra_ou_palavra_do_usuario[0]; // ela é inserida na posição correta.
            
          }else

          {
            printf("\n\nOps! você errou hihihi.\n\n");
            printf("\n\n     +---+\n");
            printf("     |   |\n");
            printf("     O   |\n");
            printf("         |\n");
            printf("         |\n");
            printf("         |\n");
            printf("      =========\n");
            *erros++;
            
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
          if (matriz[numero_aleatorio][i] != letra_ou_palavra_do_usuario[i]) // verifica se a palavra digitada pelo usuario é diferente
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
          *erros++;
        }
      }
    }
    else
    {
      {
        printf("\n\n     +---+\n");
        printf("     |   |\n");
        printf("     O   |\n");
        printf("    /|\\  |\n");
        printf("    / \\  |\n");
        printf("         |\n");
        printf("      =========\n");
        printf("\n VOCÊ FOI ENFORCADO!\n");
      }
    }
  }
}
