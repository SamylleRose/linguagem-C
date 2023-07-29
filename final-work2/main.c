#include <stdio.h>
#include <string.h>

typedef struct
{
  char nome[50];
  char tipo[50];
  int quantidade;
  double valor;

} tipo_produto;

void carregar_arquivo(tipo_produto *produto, int *quantidade_de_produtos);
void cadastrar_produto(tipo_produto *produto, int *quantidade_de_produtos);
void salvar_arquivo(tipo_produto *produto, int quantidade_de_produtos);
void editar_produto(tipo_produto *produto, int quantidade_de_produtos);
void consultar_produto(tipo_produto *produto, int quantidade_de_produtos);


int main()
{
  int quantidade_de_produtos = 0;
  tipo_produto produto[1000];
  carregar_arquivo(produto, &quantidade_de_produtos);
  cadastrar_produto(produto, &quantidade_de_produtos);
  salvar_arquivo(produto, quantidade_de_produtos);
  consultar_produto(produto, quantidade_de_produtos);
  // editar_produto(produto, quantidade_de_produtos);
  
  // printf("%s\n", produto[1].nome);
  // printf("%s\n", produto[0].tipo);
  // printf("%d\n", produto[0].quantidade);
  // printf("%lf\n", produto[0].valor);

  return 0;
}

void cadastrar_produto(tipo_produto *produto, int *quantidade_de_produtos)
{
  printf("Digite o nome do produto: ");
  scanf("%s", produto[*quantidade_de_produtos].nome);

  printf("Digite o tipo do produto: ");
  scanf("%s", produto[*quantidade_de_produtos].tipo);

  printf("Digite a quantidade do produto: ");
  scanf("%d", &produto[*quantidade_de_produtos].quantidade);

  printf("Digite o valor do produto: ");
  scanf("%lf", &produto[*quantidade_de_produtos].valor);
  printf("\n");
  (*quantidade_de_produtos)++;

  
}

void carregar_arquivo(tipo_produto *produto, int *quantidade_de_produtos)
{
  int i;
  char linha[150];
  FILE *fp;
  fp = fopen("estoque.txt", "r");

  for (i = 0; fgets(linha, sizeof(linha), fp) != NULL; i++)
  {
    sscanf(linha, "%[^;];%[^;];%d;%lf", produto[i].nome, produto[i].tipo, &produto[i].quantidade, &produto[i].valor);
  }

  *quantidade_de_produtos = i;
  

  fclose(fp);
}

void salvar_arquivo(tipo_produto *produto, int quantidade_de_produtos)
{

  FILE *fp;
  fp = fopen("estoque.txt", "w");

  for (int i = 0; i < quantidade_de_produtos; i++){

    fprintf(fp, "%s;%s;%d;%.2f\n", produto[i].nome, produto[i].tipo, produto[i].quantidade, produto[i].valor);

  }

  fclose(fp);
}

void editar_produto(tipo_produto *produto, int quantidade_de_produtos){


  int numero_do_item, codigo;
  printf("informe o número do item a ser editado:\n");
  scanf("%d", &numero_do_item);
  
  
  printf("Edite as novas informações do produto: ");

  printf("Novo nome do produto:");
  scanf("%s", produto[numero_do_item].nome);

  printf("Novo tipo do produto:");
  scanf("%s", produto[numero_do_item].tipo);

  printf("Nova quantidade do produto:");
  scanf("%d", &produto[numero_do_item].quantidade);

  printf("Novo valor do produto:");
  scanf("%lf", &produto[numero_do_item].valor);

  salvar_arquivo(produto, quantidade_de_produtos); 

}


void consultar_produto(tipo_produto *produto, int quantidade_de_produtos){
  char linha[150];
  FILE *fp;
  fp = fopen("estoque.txt", "r");

  for (int i = 0; fgets(linha, sizeof(linha), fp) != NULL; i++){

    printf("Item %d: \n", i + 1);
    printf("%s\n", produto[i].nome);
    printf("%s\n", produto[i].tipo);
    printf("%d\n", produto[i].quantidade);
    printf("%lf\n", produto[i].valor);
    printf("\n");
      
  }

  fclose(fp);


}