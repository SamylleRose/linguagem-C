#include <stdio.h>

int main(){

  int i, number, vector_position = 0;

  scanf("%d", &number);

  char name[number][50];
  double evaluation_score1[number], evaluation_score2[number], evarege[number];

  for(i = 0; i < number; i++){
    printf("Digite nome, primeira e segunda nota do %d° aluno: \n", i + 1);
    scanf("%s", &name[i][0]);
    scanf("%lf", &evaluation_score1[i]);
    scanf("%lf", &evaluation_score2[i]);

  }

  
    for(i = 0; i < number; i++){
      evarege[i] = (evaluation_score1[i] + evaluation_score2[i]) / 2;

    }

  printf("Alunos aprovados:\n");

  for(i = 0; i < number; i++){
    if (evarege[i] >= 6){
      printf("%s\n", name[i]);

    }

  }

  return 0;

}

void ler_texto(char *buffer, int length) {
    fgets(buffer, length, stdin);
    strtok(buffer, "\n");
}