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
void verificacao(int tamanho_da_palavra, int numero_aleatorio, char matriz[][50], char palavra_criptografada[]);
void desenho_da_forca(int erro);

int main()
{
  int quantidade_de_palavras_de_frutas, quantidade_de_palavras_de_paises, quantidade_de_palavras_de_animais;
  char matrizfrutas[20][50], matrizpaises[20][50], matrizanimais[20][50];

  carregar_arquivo_frutas(&quantidade_de_palavras_de_frutas, matrizfrutas);
  carregar_arquivo_paises(&quantidade_de_palavras_de_paises, matrizpaises);
  carregar_arquivo_animais(&quantidade_de_palavras_de_animais, matrizanimais);
  printf("\n\n");
  printf("    Bem-vindo ao jogo da forca!\n\n");
  programa(quantidade_de_palavras_de_frutas, quantidade_de_palavras_de_paises, quantidade_de_palavras_de_animais, matrizfrutas, matrizpaises, matrizanimais);

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
  printf("4. Sair                                                       |\n");
  printf("=================================                         =========\n");
}

void programa(int quantidade_de_palavras_de_frutas, int quantidade_de_palavras_de_paises, int quantidade_de_palavras_de_animais, char matrizfrutas[][50], char matrizpaises[][50], char matrizanimais[][50])
{

  int numero_aleatorio = 0, numero_do_tema = 0, i;
  int tamanho_da_palavra = 0;
  char palavra_a_ser_criptografada[50], resposta;

  while (numero_do_tema != 4)
  {

    menu();
    printf("\nInsira o número correspondente a sua escolha: ");
    scanf("%d", &numero_do_tema);
    srand(time(NULL));

    switch (numero_do_tema)
    {
    case 1:
      numero_aleatorio = rand() % quantidade_de_palavras_de_frutas;
      tamanho_da_palavra = strlen(matrizfrutas[numero_aleatorio]);

      // printf("%s\n", matrizfrutas[numero_aleatorio]);

      criptografar_palavra(tamanho_da_palavra, palavra_a_ser_criptografada);
      verificacao(tamanho_da_palavra, numero_aleatorio, matrizfrutas, palavra_a_ser_criptografada);

      break;

    case 2:
      numero_aleatorio = rand() % quantidade_de_palavras_de_paises;
      tamanho_da_palavra = strlen(matrizpaises[numero_aleatorio]);

      // printf("%s\n", matrizpaises[numero_aleatorio]);

      criptografar_palavra(tamanho_da_palavra, palavra_a_ser_criptografada);
      verificacao(tamanho_da_palavra, numero_aleatorio, matrizpaises, palavra_a_ser_criptografada);
      break;
    case 3:
      numero_aleatorio = rand() % quantidade_de_palavras_de_animais;
      tamanho_da_palavra = strlen(matrizanimais[numero_aleatorio]);

      // printf("%s\n", matrizanimais[numero_aleatorio]);

      criptografar_palavra(tamanho_da_palavra, palavra_a_ser_criptografada);
      verificacao(tamanho_da_palavra, numero_aleatorio, matrizanimais, palavra_a_ser_criptografada);

      break;

    default:
      printf("Número inválido, tente novamente.");
      break;
    }
  }
}

void criptografar_palavra(int tamanho_da_palavra, char *palavra_a_ser_criptografada)
{

  for (int i = 0; i < tamanho_da_palavra; i++)
  {
    palavra_a_ser_criptografada[i] = '_';
    printf("%5c", palavra_a_ser_criptografada[i]);
  }
}

void verificacao(int tamanho_da_palavra, int numero_aleatorio, char matriz[][50], char palavra_criptografada[])
{
  int acertos, erros = 0;
  char letra_ou_palavra_do_usuario[20];

  do
  {
    if (erros < 6)
    {
      printf("\n\nEscreva uma letra ou uma palavra completa: ");
      scanf("%s", letra_ou_palavra_do_usuario);
      int verificar_tamanho = strlen(letra_ou_palavra_do_usuario);

      if (verificar_tamanho == 1) // entra se for uma letra digitada pelo usuario
      {
        acertos = 0;
        for (int i = 0; i < tamanho_da_palavra; i++)
        {

          if (matriz[numero_aleatorio][i] == letra_ou_palavra_do_usuario[0]) // se essa letra estiver na palavra
          {
            palavra_criptografada[i] = letra_ou_palavra_do_usuario[0]; // ela é inserida na posição correta.
            acertos++;
          }
        }
        if (acertos != 0) // se os acertos forem diferente de 0 então a letra estava correta
        {
          printf("\n\nVocê acertou (👉ﾟヮﾟ)👉.\n\n");
          for (int i = 0; i < tamanho_da_palavra; i++)
          {
            printf("%5c", palavra_criptografada[i]); // printa a palavra criptogravada com as letras adivinhadas reveladas.
          }
        }
        else // se for igual a zero então a letra estava errada.
        {
          erros++;
          desenho_da_forca(erros);
          printf("\n");

          for (int i = 0; i < tamanho_da_palavra; i++)
          {
            printf("%5c", palavra_criptografada[i]); // printa a palavra criptogravada com as letras adivinhadas reveladas.
          }
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
          printf("\n\nParabéns você acertou! a palavra correta é %s 👏 ^_^ .\n\n", letra_ou_palavra_do_usuario); // mensagem parabenizando o usuario pelo acerto.
          break;
        }
        else // se tiver alguma letra errada entra nessa condição e escreve a mensagem.
        {
          erros++;
          desenho_da_forca(erros);
          printf("\n");
          for (int i = 0; i < tamanho_da_palavra; i++)
          {
            printf("%5c", palavra_criptografada[i]); // printa a palavra criptogravada com as letras adivinhadas reveladas.
          }
        }
      }
    }
    else // se as tentativas chegarem a 6 o jogo se encerra.
    {
      char forca[] = "\n\n     +---+\n""     |   |\n""     O   |\n""    /|\\  |\n""    / \\  |\n""         |\n""     =========\n";
      printf("%s", forca);
      printf("\nVOCÊ FOI ENFORCADO! (X_X).\n\n");
      erros++;
    }
  } while (erros != 7);
}

void desenho_da_forca(int erro)
{

  if (erro == 1)
  {
    printf("\n\nVocê errou hihi.\n\n");
    char forca[] = "\n\n     +---+\n""     |   |\n""     O   |\n""         |\n""         |\n""         |\n""     =========\n";
    printf("%s", forca);
  }
  else if (erro == 2)
  {
    printf("\n\nVocê errou denovo ( ´･･)ﾉ(._.`).\n\n");
    char forca[] = "\n\n     +---+\n""     |   |\n""     O   |\n""     |   |\n""         |\n""         |\n""     =========\n";
    printf("%s", forca);
  }

  else if (erro == 3)
  {
    printf("\n\nVocê errou ＞︿＜.\n\n");
    char forca[] = "\n\n     +---+\n""     |   |\n""     O   |\n""    /|   |\n""         |\n""         |\n""     =========\n";
    printf("%s", forca);
  }

  else if (erro == 4)
  {
    printf("\n\nVocê errou, suas tentativas estão quase acabando (´。＿。｀) .\n\n");
    char forca[] = "\n\n     +---+\n""     |   |\n""     O   |\n""    /|\\  |\n""         |\n""         |\n""     =========\n";
    printf("%s", forca);
  }

  else if (erro == 5)
  {
    printf("\n\nVocê errou, só tem mais uma chance (。﹏。*).\n\n");
    char forca[] = "\n\n     +---+\n""     |   |\n""     O   |\n""    /|\\  |\n""    /    |\n""         |\n""     =========\n";
    printf("%s", forca);
  }
}
