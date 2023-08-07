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

} tipo_cliente;

void carregar_arquivo_dos_produtos(tipo_produto *produto, int *quantidade_de_produtos); // função que carrega o arquivo estoque
void salvar_arquivo_dos_produtos(tipo_produto *produto, int quantidade_de_produtos);    // função que salva o arquivo estoque
void cadastrar_produto(tipo_produto *produto, int *quantidade_de_produtos);             // função que cadastra os produtos no arquivo estoque
void consultar_produto(tipo_produto *produto, int quantidade_de_produtos);              // função que consulta os produtos no arquivo estoque
void editar_produto(tipo_produto *produto, int quantidade_de_produtos);                 // função edita o produto do arquivo estoque
void excluir_produto(tipo_produto *produto, int *quantidade_de_produtos);               // função que exclui o produto do arquivo estoque

void carregar_arquivo_dos_clientes(tipo_cliente *cliente, int *quantidade_de_clientes); // função que carrega o arquivo cliente
void salvar_arquivo_dos_clientes(tipo_cliente *cliente, int quantidade_de_clientes);    // função que salva o arquivo cliente
void cadastrar_cliente(tipo_cliente *cliente, int *quantidade_de_cliente);              // função que cadastra os clientes no arquivo cliente
void consultar_cliente(tipo_cliente *cliente, int quantidade_de_clientes);              // função que consulta os clientes no arquivo cliente
void editar_cliente(tipo_cliente *cliente, int quantidade_de_clientes);                 // função edita o cliente do arquivo cliente
void excluir_cliente(tipo_cliente *cliente, int *quantidade_de_clientes);               // função que exclui o cliente do arquivo cliente

void carregar_arquivo_do_caixa(double *valor_do_caixa, int *quantidade_de_vendas_realizadas, int *quantidade_de_produtos_vendidos, char cpfs[][20], int *quantidade_de_cpf_adicionado);                                                                                           // função que carrega o arquivo caixa
void salvar_arquivo_do_caixa(double valor_do_caixa, int quantidade_de_vendas_realizadas, int quantidade_de_produtos_vendidos, char cpfs[][20], int quantidade_de_cpf_adcionado);                                                                                                  // função que salva o arquivo caixa
void realizar_venda(tipo_produto *produto, tipo_cliente *cliente, int quantidade_de_clientes, int *quantidade_de_vendas_realizadas, int *quantidade_de_produtos_vendidos, int *quantidade_de_cpf_adcionado, double *valor_do_caixa, char cpfs[][20], int quantidade_de_produtos); // função realiza a venda de produtos, decrementa o produto vendido, faz o calculo do caixa, da quantidade de produtos vendidos e quantas vendas foram feitas.
void total_do_caixa(double valor_do_caixa);// printa apenas o que a variavel  armazena
void total_de_vendas_realizadas(int quantidade_de_vendas_realizadas);// printa apenas o que a variavel armazena
void total_de_produtos_vendidos(int quantidade_de_produtos_vendidos); // printa apenas oq a variavel armazena

void menu_principal(tipo_produto *produto, int *quantidade_de_produtos, tipo_cliente *cliente, int *quantidade_de_clientes, int *quantidade_de_vendas_realizadas, int *quantidade_de_produtos_vendidos, int *quantidade_de_cpf_adcionado, double *valor_do_caixa, char cpfs[][20]); // menu principal recebe os outros menus.
void menu_estoque(tipo_produto *produto, int *quantidade_de_produtos);
void menu_cliente(tipo_cliente *cliente, int *quantidade_de_clientes);
void menu_caixa(tipo_cliente *cliente, int quantidade_de_clientes, tipo_produto *produto, int *quantidade_de_vendas_realizadas, int *quantidade_de_produtos_vendidos, int *quantidade_de_cpf_adcionado, double *valor_do_caixa, int quantidade_de_produtos, char cpfs[][20]);

int main()
{
  int quantidade_de_produtos = 0, quantidade_de_clientes = 0, quantidade_de_vendas_realizadas = 0, quantidade_de_produtos_vendidos = 0, quantidade_de_cpf_adcionado = 0;
  char cpfs[1000][20];
  double valor_do_caixa = 0;

  tipo_produto produto[1000];
  tipo_cliente cliente[1000];

  carregar_arquivo_dos_produtos(produto, &quantidade_de_produtos);
  salvar_arquivo_dos_produtos(produto, quantidade_de_produtos);

  carregar_arquivo_dos_clientes(cliente, &quantidade_de_clientes);
  salvar_arquivo_dos_clientes(cliente, quantidade_de_clientes);

  carregar_arquivo_do_caixa(&valor_do_caixa, &quantidade_de_vendas_realizadas, &quantidade_de_produtos_vendidos, cpfs, &quantidade_de_cpf_adcionado);
  salvar_arquivo_do_caixa(valor_do_caixa, quantidade_de_vendas_realizadas, quantidade_de_produtos_vendidos, cpfs, quantidade_de_cpf_adcionado);

  menu_principal(produto, &quantidade_de_produtos, cliente, &quantidade_de_clientes, &quantidade_de_vendas_realizadas, &quantidade_de_produtos_vendidos, &quantidade_de_cpf_adcionado, &valor_do_caixa, cpfs);

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

  printf("Produto cadastrado com sucesso!\n");

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

void carregar_arquivo_dos_clientes(tipo_cliente *cliente, int *quantidade_de_clientes)
{
  int i;
  char linha[150];
  FILE *fp;
  fp = fopen("clientes.txt", "r");

  for (i = 0; fgets(linha, sizeof(linha), fp) != NULL; i++)
  {
    sscanf(linha, "%[^;];%[^;];%[^;];%s", cliente[i].nome, cliente[i].RG, cliente[i].CPF, cliente[i].data_de_nascimento);
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

void editar_produto(tipo_produto *produto, int quantidade_de_produtos)
{
  if (quantidade_de_produtos == 0)
  {

    // interrompe o código e printa a mensagem da função consultar_produto
  }
  else
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
    printf("Produto alterado com sucesso!\n\n");
  }
}

void consultar_produto(tipo_produto *produto, int quantidade_de_produtos)
{
  if (quantidade_de_produtos == 0)
  {
    printf("Nenhum produto cadastrado no estoque. Não é possivel continuar!\n\n"); //printa a mensagem indicando que está sem produtos
  }
  else
  {
    printf("========================= CONSULTAR PRODUTOS ========================\n\n");
    for (int i = 0; i < quantidade_de_produtos; i++)
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
  }
}

void excluir_produto(tipo_produto *produto, int *quantidade_de_produtos)
{
  int numero_do_produto;

  if (*quantidade_de_produtos == 0)
  {
    // interrompe o código e printa a mensagem da função consultar_produto
  }
  else

  {
    printf("Qual item deseja excluir? ");
    scanf("%d", &numero_do_produto);
    if (numero_do_produto <= 0 || numero_do_produto > *quantidade_de_produtos)
    {
      printf("\nNúmero de produto inválido!\n");
    }
    else
    {

      for (int i = numero_do_produto - 1; i < *quantidade_de_produtos - 1; i++) // a posição escolhida é trocada de valor
      {
        produto[i] = produto[i + 1];
      }

      (*quantidade_de_produtos)--; // no final é feito uma decrementação.

      printf("\nProduto excluido com sucesso!\n\n");
    }
  }
}

void menu_principal(tipo_produto *produto, int *quantidade_de_produtos, tipo_cliente *cliente, int *quantidade_de_clientes, int *quantidade_de_vendas_realizadas, int *quantidade_de_produtos_vendidos, int *quantidade_de_cpf_adcionado, double *valor_do_caixa, char cpfs[][20])
{
  int codigo;
  do
  {
    printf("==============================MENU=================================\n");
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
      menu_estoque(produto, quantidade_de_produtos); // o menu principal recebe o menu estoque

      break;

    case 2:
      menu_cliente(cliente, quantidade_de_clientes); // o menu cliente também

      break;

    case 3:
      menu_caixa(cliente, *quantidade_de_clientes, produto, quantidade_de_vendas_realizadas, quantidade_de_produtos_vendidos, quantidade_de_cpf_adcionado, valor_do_caixa, *quantidade_de_produtos, cpfs); // e por fim o menu caixa

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

    printf("============================ESTOQUE================================\n");
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
      cadastrar_produto(produto, quantidade_de_produtos);            // onde possui alguma alteração é chamada a função salvar
      salvar_arquivo_dos_produtos(produto, *quantidade_de_produtos); // salva as alterações
      break;

    case 2:
      consultar_produto(produto, *quantidade_de_produtos);

      break;

    case 3:
      consultar_produto(produto, *quantidade_de_produtos);
      editar_produto(produto, *quantidade_de_produtos);
      salvar_arquivo_dos_produtos(produto, *quantidade_de_produtos);

      break;

    case 4:
      consultar_produto(produto, *quantidade_de_produtos);
      excluir_produto(produto, quantidade_de_produtos);
      salvar_arquivo_dos_produtos(produto, *quantidade_de_produtos);
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
    printf("============================CLIENTES===============================\n");
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
      consultar_cliente(cliente, *quantidade_de_clientes);
      break;

    case 3:
      consultar_cliente(cliente, *quantidade_de_clientes);
      editar_cliente(cliente, *quantidade_de_clientes);
      salvar_arquivo_dos_clientes(cliente, *quantidade_de_clientes);
      break;

    case 4:
      consultar_cliente(cliente, *quantidade_de_clientes);
      excluir_cliente(cliente, quantidade_de_clientes);
      salvar_arquivo_dos_clientes(cliente, *quantidade_de_clientes);
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

void menu_caixa(tipo_cliente *cliente, int quantidade_de_clientes, tipo_produto *produto, int *quantidade_de_vendas_realizadas, int *quantidade_de_produtos_vendidos, int *quantidade_de_cpf_adcionado, double *valor_do_caixa, int quantidade_de_produtos, char cpfs[][20])
{
  int codigo;
  do
  {
    printf("==============================CAIXA================================\n");
    printf("|            OPÇÃO                                 CÓDIGO         |\n");
    printf("|   Realizar venda                                    1           |\n");
    printf("|   Vendas Realizadas                                 2           |\n");
    printf("|   Quantidade de produtos vendidos                   3           |\n");
    printf("|   Valor do caixa                                    4           |\n");
    printf("|   Voltar ao menu principal                          5           |\n");
    printf("===================================================================\n");

    printf("Digite o código: ");
    scanf("%d", &codigo);
    printf("\n");

    switch (codigo)
    {
    case 1:
      consultar_produto(produto, quantidade_de_produtos); // consulta para mostra a tabela ao usuario

      realizar_venda(produto, cliente, quantidade_de_clientes, quantidade_de_vendas_realizadas, quantidade_de_produtos_vendidos, quantidade_de_cpf_adcionado, valor_do_caixa, cpfs, quantidade_de_produtos); // realiza as vendas

      salvar_arquivo_do_caixa(*valor_do_caixa, *quantidade_de_vendas_realizadas, *quantidade_de_produtos_vendidos, cpfs, *quantidade_de_cpf_adcionado);

      salvar_arquivo_dos_produtos(produto, quantidade_de_produtos);
      break;

    case 2:
      total_de_vendas_realizadas(*quantidade_de_vendas_realizadas);

      break;

    case 3:
      total_de_produtos_vendidos(*quantidade_de_produtos_vendidos);

      break;

    case 4:
      total_do_caixa(*valor_do_caixa);
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

void consultar_cliente(tipo_cliente *cliente, int quantidade_de_clientes)

{

  if (quantidade_de_clientes == 0)
  {
    printf("Nenhum cliente cadastrado no sistema!\n\n"); // verificação
  }
  else
  {

    printf("========================= CONSULTAR CLIENTES ======================\n\n");
    for (int i = 0; i < quantidade_de_clientes; i++)
    {
      printf("===================================================================\n");
      printf("                           CLIENTE %d\n", i + 1);
      printf("===================================================================\n");
      printf("NOME: %s\n", cliente[i].nome);
      printf("RG: %s\n", cliente[i].RG);
      printf("CPF: %s\n", cliente[i].CPF);
      printf("DATA DE NASCIMENTO: %s\n", cliente[i].data_de_nascimento);
      printf("===================================================================\n\n");
    }
  }
}

void editar_cliente(tipo_cliente *cliente, int quantidade_de_clientes)
{
  if (quantidade_de_clientes == 0)
  {
    // interrompe o código e printa a mensagem da função consultar_cliente
  }
  else
  {
    int numero_do_cliente, codigo;
    printf("informe o número do cliente a ser editado: ");
    scanf("%d", &numero_do_cliente);
    printf("\n");
    printf("Edite as novas informações do cliente:\n");

    printf("Novo nome do cliente: ");
    scanf("%s", cliente[numero_do_cliente - 1].nome);

    printf("Novo número do RG: ");
    scanf("%s", cliente[numero_do_cliente - 1].RG);

    printf("Novo número do CPF: ");
    scanf("%s", cliente[numero_do_cliente - 1].CPF);

    printf("Nova data de nascimento: ");
    scanf("%s", cliente[numero_do_cliente - 1].data_de_nascimento);
    printf("\n");
  }
}

void excluir_cliente(tipo_cliente *cliente, int *quantidade_de_clientes)
{
  int numero_do_cliente;
  if (*quantidade_de_clientes == 0)
  {
    // interrompe o código e printa a mensagem da função consultar_produto
  }
  else
  {

    printf("Insira o numero do cliente que deseja excluir? ");
    scanf("%d", &numero_do_cliente);
    if (numero_do_cliente <= 0 || numero_do_cliente > *quantidade_de_clientes)
    {
      printf("Número do cliente inválido!\n");
    }
    else
    {

      for (int i = numero_do_cliente - 1; i < *quantidade_de_clientes - 1; i++)
      {
        cliente[i] = cliente[i + 1];
      }

      (*quantidade_de_clientes)--;

      printf("\nCliente excluido com sucesso!\n\n");
    }
  }
}

void realizar_venda(tipo_produto *produto, tipo_cliente *cliente, int quantidade_de_clientes, int *quantidade_de_vendas_realizadas, int *quantidade_de_produtos_vendidos, int *quantidade_de_cpf_adcionado, double *valor_do_caixa, char cpfs[][20], int quantidade_de_produtos)
{
  if (quantidade_de_produtos == 0)
  {
    // interrompe o código e printa a mensagem da função consultar_produto
  }
  else
  {
    int numero_do_produto = 0, i, numero_da_quantidade_de_produto = 0;
    char numero_do_CPF[20];
    printf("Insira o numero do item que o cliente deseja comprar: ");
    scanf("%d", &numero_do_produto);
    printf("Insira a quantidade que cliente deseja comprar: ");
    scanf("%d", &numero_da_quantidade_de_produto);

    if (((produto[numero_do_produto - 1].quantidade) - numero_da_quantidade_de_produto) < 0) // verificação da quantidade de produto
    {
      printf("\nvenda não realizada, quantidades de produtos insuficientes! A quantidade de %s no estoque é %d.\n\n", produto[numero_do_produto - 1].nome, produto[numero_do_produto - 1].quantidade);
    }
    else
    {
      printf("Insira o número do CPF do cliente: ");
      scanf("%s", numero_do_CPF);

      for (int i = 0; i < quantidade_de_clientes; i++)
      {
        if (strcmp(numero_do_CPF, cliente[i].CPF) == 0)
        {

          (*quantidade_de_vendas_realizadas)++; // em forma de contador ele armazena a quantidade de vendas

          *quantidade_de_produtos_vendidos += numero_da_quantidade_de_produto; // armazena a quantidade de produtos vendidos e faz a soma

          strcpy(cpfs[*quantidade_de_cpf_adcionado], numero_do_CPF); // armazena os cpf dos clientes que realizaram as comprar em uma matriz

          (*quantidade_de_cpf_adcionado)++; // em forma de contador ele armazena quantos cpf foram armazenados na matriz

          *valor_do_caixa += produto[numero_do_produto - 1].valor; // é feito a soma do valor dos produtos

          produto[numero_do_produto - 1].quantidade -= numero_da_quantidade_de_produto; // atualiza a nova quantidade de produtos em forma de decrementação
          printf("\nVenda realizada com sucesso!\n\n");

          break;
        }

        else
        {
          printf("\nCliente não cadastrado, realize o cadastro do cliente, para realiza a venda do produto!\n\n");
        }
      }
    }
  }
}

void carregar_arquivo_do_caixa(double *valor_do_caixa, int *quantidade_de_vendas_realizadas, int *quantidade_de_produtos_vendidos, char cpfs[][20], int *quantidade_de_cpf_adicionado)
{
  int i;
  char linha[150];
  FILE *fp;
  fp = fopen("caixa.txt", "r");

  fgets(linha, sizeof(linha), fp);
  sscanf(linha, "%lf;%d;%d", valor_do_caixa, quantidade_de_vendas_realizadas, quantidade_de_produtos_vendidos);
  for (i = 0; fgets(linha, sizeof(linha), fp) != NULL; i++)
  {
    sscanf(linha, "%s", cpfs[i]);
  }

  *quantidade_de_cpf_adicionado = i;

  fclose(fp);
}

void salvar_arquivo_do_caixa(double valor_do_caixa, int quantidade_de_vendas_realizadas, int quantidade_de_produtos_vendidos, char cpfs[][20], int quantidade_de_cpf_adcionado)
{

  FILE *fp;
  fp = fopen("caixa.txt", "w");

  fprintf(fp, "%.2lf;%d;%d\n", valor_do_caixa, quantidade_de_vendas_realizadas, quantidade_de_produtos_vendidos); // na primeira linha
  for (int i = 0; i < quantidade_de_cpf_adcionado; i++)
  {
    fprintf(fp, "%s\n", cpfs[i]); // a partir da primeira linha
  }

  fclose(fp);
}

void total_do_caixa(double valor_do_caixa)
{

  printf("O valor total do caixa é: R$ %.2lf\n\n", valor_do_caixa);
}

void total_de_vendas_realizadas(int quantidade_de_vendas_realizadas)
{

  printf("A quantidade de vendas realizadas foi de: %d vendas.\n\n", quantidade_de_vendas_realizadas);
}

void total_de_produtos_vendidos(int quantidade_de_produtos_vendidos)
{

  printf("A quantidade de produtos vendidos foi de: %d produtos.\n\n", quantidade_de_produtos_vendidos);
}
