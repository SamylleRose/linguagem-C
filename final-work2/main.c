#include <stdio.h>
#include <string.h>

typedef struct
{
  char nome[50];
  char tipo[50];
  int quantidade;
  double valor;

} tipo_produto;

typedef struct
{
  char nome[50];
  char RG[20];
  char CPF[20];
  char data_de_nascimento[20];
  
}tipo_cliente;


void carregar_arquivo_dos_produtos(tipo_produto *produto, int *quantidade_de_produtos);
void cadastrar_produto(tipo_produto *produto, int *quantidade_de_produtos);
void salvar_arquivo_dos_produtos(tipo_produto *produto, int quantidade_de_produtos);
void editar_produto(tipo_produto *produto, int quantidade_de_produtos);
void consultar_produto(tipo_produto *produto, int quantidade_de_produtos);
void menu_principal(tipo_produto *produto, int *quantidade_de_produtos, tipo_cliente *cliente, int *quantidade_de_clientes);
void menu_estoque(tipo_produto *produto, int *quantidade_de_produtos);
void menu_cliente();
void menu_caixa();
void carregar_arquivo_dos_clientes(tipo_cliente *cliente, int *quantidade_de_clientes);
void salvar_arquivo_dos_clientes(tipo_cliente *cliente, int quantidade_de_clientes);
void cadastrar_cliente(tipo_cliente *cliente, int *quantidade_de_cliente);

int main()
{
  int quantidade_de_produtos = 0;
  int quantidade_de_clientes = 0;
  tipo_produto produto[1000];
  tipo_cliente cliente[1000];

  carregar_arquivo_dos_produtos(produto, &quantidade_de_produtos);
  salvar_arquivo_dos_produtos(produto, quantidade_de_produtos);
  carregar_arquivo_dos_clientes(cliente, &quantidade_de_clientes);
  salvar_arquivo_dos_clientes(cliente, quantidade_de_clientes);
  menu_principal(produto, &quantidade_de_produtos, cliente, &quantidade_de_clientes);

  // editar_produto(produto, quantidade_de_produtos);
  // printf("%s\n", produto[1].nome);
  // printf("%s\n", produto[0].tipo);
  // printf("%d\n", produto[0].quantidade);
  // printf("%lf\n", produto[0].valor);

  return 0;
}

void cadastrar_produto(tipo_produto *produto, int *quantidade_de_produtos)
{
  printf("Digite o dados do produto: \n");
  printf("Nome: ");
  scanf("%s", produto[*quantidade_de_produtos].nome);

  printf("Tipo: ");
  scanf("%s", produto[*quantidade_de_produtos].tipo);

  printf("Quantidade: ");
  scanf("%d", &produto[*quantidade_de_produtos].quantidade);

  printf("Valor: R$ ");
  scanf("%lf", &produto[*quantidade_de_produtos].valor);
  printf("\n");
  (*quantidade_de_produtos)++;

}

void carregar_arquivo_dos_produtos(tipo_produto *produto, int *quantidade_de_produtos)
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

void salvar_arquivo_dos_produtos(tipo_produto *produto, int quantidade_de_produtos)
{

  FILE *fp;
  fp = fopen("estoque.txt", "w");

  for (int i = 0; i < quantidade_de_produtos; i++)
  {

    fprintf(fp, "%s;%s;%d;%.2f\n", produto[i].nome, produto[i].tipo, produto[i].quantidade, produto[i].valor);
  }

  fclose(fp);
}

void editar_produto(tipo_produto *produto, int quantidade_de_produtos)
{

  int numero_do_item, codigo;
  printf("informe o número do item a ser editado: ");
  scanf("%d", &numero_do_item);
  printf("\n");
  printf("Edite as novas informações do produto:\n");

  printf("Novo nome do produto: ");
  scanf("%s", produto[numero_do_item - 1].nome);

  printf("Novo tipo do produto: ");
  scanf("%s", produto[numero_do_item - 1].tipo);

  printf("Nova quantidade do produto: ");
  scanf("%d", &produto[numero_do_item - 1].quantidade);

  printf("Novo valor do produto: ");
  scanf("%lf", &produto[numero_do_item - 1].valor);
  printf("\n");
  salvar_arquivo_dos_produtos(produto, quantidade_de_produtos);
}

void  consultar_produto(tipo_produto *produto, int quantidade_de_produtos)

{
  char linha[150];
  FILE *fp;
  fp = fopen("estoque.txt", "r");

  printf("========================= CONSULTAR PRODUTOS ========================\n\n");
  for (int i = 0; fgets(linha, sizeof(linha), fp) != NULL; i++)
  {
    printf("===================================================================\n");
    printf("                           ITEM %d\n", i + 1);                                       
    printf("===================================================================\n");
    printf("NOME: %s\n", produto[i].nome);
    printf("TIPO: %s\n", produto[i].tipo);
    printf("QUANTIDADE: %d\n", produto[i].quantidade);
    printf("VALOR: R$%.2f\n", produto[i].valor);
    printf("===================================================================\n\n");
  }

  fclose(fp);
}

void menu_principal(tipo_produto *produto, int *quantidade_de_produtos, tipo_cliente *cliente, int *quantidade_de_clientes)
{
  int codigo;
  do
  {
    printf("=================================MENU==============================\n");
    printf("|            OPÇÃO                                 CÓDIGO         |\n");
    printf("|   Estoque                                           1           |\n");
    printf("|   Clientes                                          2           |\n");
    printf("|   Caixa                                             3           |\n");
    printf("|   Finalizar programa                                4           |\n");
    printf("===================================================================\n");

    printf("Digite o código: ");
    scanf("%d", &codigo);
    printf("\n");

    switch (codigo)
    {
    case 1:
      menu_estoque(produto, quantidade_de_produtos);

      break;

    case 2:
      menu_cliente(cliente, quantidade_de_clientes);

      break;

    case 3:
      menu_caixa();

      break;

    case 4:
      printf("PROGRAMA FINALIZADO!\n\n");

      break;

    default:
      printf("TENTE NOVAMENTE!\n");

      break;
    }
  } while (codigo != 4);
}

void menu_estoque(tipo_produto *produto, int *quantidade_de_produtos)
{
  int codigo;
  do
  {

    printf("==============================ESTOQUE==============================\n");
    printf("|            OPÇÃO                                 CÓDIGO         |\n");
    printf("|   Cadastra produto                                  1           |\n");
    printf("|   Consultar produtos                                2           |\n");
    printf("|   Editar produto                                    3           |\n");
    printf("|   Excluir produto                                   4           |\n");
    printf("|   Voltar ao menu principal                          5           |\n");
    printf("===================================================================\n");

    printf("Digite o código: ");
    scanf("%d", &codigo);
    printf("\n");

    switch (codigo)
    {
    case 1:
      cadastrar_produto(produto, quantidade_de_produtos);
      salvar_arquivo_dos_produtos(produto, *quantidade_de_produtos);
      break;

    case 2:
      consultar_produto(produto, *quantidade_de_produtos);

      break;

    case 3:
      editar_produto(produto, *quantidade_de_produtos);

      break;

    case 4:

      break;

    case 5:
      printf("Voltando ao menu principal...\n\n");
      break;

    default:
      printf("Opção inválida! Tente novamente.\n");
      break;
    }

  } while (codigo != 5);
}

void menu_cliente(tipo_cliente *cliente, int *quantidade_de_clientes)
{
  int codigo;
  do
  {
    printf("==============================CLIENTES=============================\n");
    printf("|            OPÇÃO                                 CÓDIGO         |\n");
    printf("|   Cadastra cliente                                  1           |\n");
    printf("|   Consultar clientes                                2           |\n");
    printf("|   Editar cliente                                    3           |\n");
    printf("|   Excluir cliente                                   4           |\n");
    printf("|   Voltar ao menu principal                          5           |\n");
    printf("===================================================================\n");

    printf("Digite o código: ");
    scanf("%d", &codigo);
    printf("\n");

    switch (codigo)
    {
    case 1:
      cadastrar_cliente(cliente, quantidade_de_clientes);
      salvar_arquivo_dos_clientes(cliente, *quantidade_de_clientes);
      break;

    case 2:

      break;

    case 3:

      break;

    case 4:

      break;

    case 5:
      printf("Voltando ao menu principal...\n\n");
      break;

    default:
      printf("Opção inválida! Tente novamente.\n");
      break;
    }

  } while (codigo != 5);
}

void menu_caixa()
{
  int codigo;
  do
  {
    printf("================================CAIXA==============================\n");
    printf("|            OPÇÃO                                 CÓDIGO         |\n");
    printf("|   Valor do caixa                                    1           |\n");
    printf("|   Vendas Realizadas                                 2           |\n");
    printf("|   Quantidade de produtos vendidos                   3           |\n");
    printf("|   Realizar venda                                    4           |\n");
    printf("|   Voltar ao menu principal                          5           |\n");
    printf("===================================================================\n");

    printf("Digite o código: ");
    scanf("%d", &codigo);
    printf("\n");

    switch (codigo)
    {
    case 1:

      break;

    case 2:

      break;

    case 3:

      break;

    case 4:

      break;

    case 5:
      printf("Voltando ao menu principal...\n\n");
      break;

    default:
      printf("Opção inválida! Tente novamente.\n");
      break;
    }

  } while (codigo != 5);
}

void carregar_arquivo_dos_clientes(tipo_cliente *cliente, int *quantidade_de_clientes){
int i;
  char linha[150];
  FILE *fp;
  fp = fopen("clientes.txt", "r");

  for (i = 0; fgets(linha, sizeof(linha), fp) != NULL; i++)
  {
    sscanf(linha, "%[^;];%[^;];%[^;];%[^;]", cliente[i].nome, cliente[i].RG, cliente[i].CPF, cliente[i].data_de_nascimento);
  }

  *quantidade_de_clientes = i;

  fclose(fp);
   
}

void salvar_arquivo_dos_clientes(tipo_cliente *cliente, int quantidade_de_clientes)
{

  FILE *fp;
  fp = fopen("clientes.txt", "w");

  for (int i = 0; i < quantidade_de_clientes; i++)
  {

    fprintf(fp, "%s;%s;%s;%s\n", cliente[i].nome, cliente[i].RG, cliente[i].CPF, cliente[i].data_de_nascimento);
  }

  fclose(fp);
}

void cadastrar_cliente(tipo_cliente *cliente, int *quantidade_de_cliente)
{
  printf("Digite os dados do cliente:\n");
  printf("Nome: ");
  scanf("%s", cliente[*quantidade_de_cliente].nome);

  printf("RG: ");
  scanf("%s", cliente[*quantidade_de_cliente].RG);

  printf("CPF: ");
  scanf("%s", cliente[*quantidade_de_cliente].CPF);

  printf("Data de nascimento: ");
  scanf("%s", cliente[*quantidade_de_cliente].data_de_nascimento);
  printf("\n");
  (*quantidade_de_cliente)++;

}