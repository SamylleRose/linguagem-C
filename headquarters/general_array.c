#include <stdio.h>
#include <math.h>

int main(){

  int l, c, number, line_choice, column_choice;

  scanf("%d", &number);

  double matriz[number][number], sum_of_positives = 0;

  for (l = 0; l < number; l++){
    for (c = 0; c < number; c++){
      scanf("%lf", &matriz[l][c]);

    }

  }

  for (l = 0; l < number; l++){
    for (c = 0; c < number; c++){
      if ( matriz[l][c] > 0 ){

        sum_of_positives = sum_of_positives + matriz[l][c];
      }

    }

  }

  printf("\nSOMA DOS POSITIVOS: %.0lf\n", sum_of_positives);
  printf("\nESCOLHA UMA LINHA:");
  scanf("%d", &line_choice);
  printf("\nLINHA ESCOLHIDA:\n");

  for (c = 0; c < number; c++){
    printf("%.1lf ", matriz[line_choice][c]);

  }

  printf("\n\nESCOLHA UMA COLUNA:");
  scanf("%d", &column_choice);
  printf("\nCOLUNA ESCOLHIDA:\n");

  for (l = 0; l < number; l++){
    printf("%.1lf ", matriz[l][column_choice]);

  }
  
  printf("\n\nDIAGONAL PRINCIPAL\n");

  for (l = 0; l < number; l++){
    printf("%.1lf ", matriz[l][l]);

  }

  printf("\n");

  for (l = 0; l < number; l++){
    for (c = 0; c < number; c++){
      if ( matriz[l][c] < 0 ){

        matriz[l][c] =  pow(matriz[l][c], 2);

      }

    }

  }

  printf("MATRIZ ALTERADA:\n");
  for (l = 0; l < number; l++){
    for (c = 0; c < number; c++){
      printf("%3.1lf ", matriz[l][c]);
    }

    printf("\n");

  }

  return 0;

}