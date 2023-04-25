#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 3

void menu();

int main(){
  
  int codigo, i, j, quantidade_de_paes_para_venda, quantidade_de_paes_vendidos;;
  char tipo_de_paes_disponiveis[10][50], produtos_para_fabricacao_de_paes[10][50];

  menu();
  
  printf("\nDÍGITE UM CÓDIGO:");
  scanf("%d", &codigo);
  
  while (codigo != 7){

    switch(codigo){

      case 1: 
        if ( quantidade_de_paes_para_venda == 0){ 
          printf("NENHUM DADO INSERIDO, POR FAVOR INSIRA OS DADOS EM \"EDITAR INFORMAÇÕES.\" ");
          printf("\n");
          menu();
          printf("\n");
          printf("DÍGITE UM CÓDIGO:");
          scanf("%d", &codigo);
        } else { 
          printf(" Quantidade de pães a venda: %d\n", quantidade_de_paes_para_venda);
          menu();
          printf("\n");
          printf("DÍGITE UM CÓDIGO:");
          scanf("%d", &codigo);
        }

      break;

      case 2:

        if ( quantidade_de_paes_vendidos == 0){ 
          printf("NENHUM DADO INSERIDO, POR FAVOR INSIRA OS DADOS EM \"EDITAR INFORMAÇÕES.\" ");
          printf("\n");
          menu();
          printf("\n");
          printf("DÍGITE UM CÓDIGO:");
          scanf("%d", &codigo);

        } else { 
          printf(" Quantidade de pães a vendidos: %d\n", quantidade_de_paes_vendidos);
          menu();
          printf("\n");
          printf("DÍGITE UM CÓDIGO:");
          scanf("%d", &codigo);

        }

      break;

      case 3:

        if ( tipo_de_paes_disponiveis [0][0] == ' '){ 
          printf("NENHUM DADO INSERIDO, POR FAVOR INSIRA OS DADOS EM \"EDITAR INFORMAÇÕES.\" ");
          printf("\n");
          menu();
          printf("\n");
          printf("DÍGITE UM CÓDIGO:");
          scanf("%d", &codigo);

        } else { 

          printf(" Tipos de pães disponíveis:");
          for(i = 0; i < 10;i++){
            for(j = 0; j < 50; j++){ 
              printf("%c\n", tipo_de_paes_disponiveis[i][j]);

            }

          } 

        }

        menu();
        printf("\n");
        printf("DÍGITE UM CÓDIGO:");
        scanf("%d", &codigo);

      break;

      case 4:

        printf("Margem de lucro:");

      break;
    }
  }
  
  return 0;

}

void menu() {

  printf("=================================MENU =============================\n");
  printf("|            OPÇÃO                                 CÓDIGO         |\n");
  printf("|   Quandidade de pães a venda                        1           |\n");
  printf("|   Quantidade de pães vendidos                       2           |\n");
  printf("|   Tipo de pães disponíveis                          3           |\n");
  printf("|   Margem de Lucro                                   4           |\n");
  printf("|   Editar informações                                5           |\n");
  printf("|   Sair                                              6           |\n");
  printf("===================================================================\n");
}
