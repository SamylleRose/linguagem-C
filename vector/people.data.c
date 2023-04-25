#include <stdio.h>

int main(){

  int i, number, amount = 0, numberM = 0;
  char gender_vector[5];
  double height_vector[5], shorter_height, greater_height, average = 0, sum = 0;

  scanf("%d", &number);

  for (i = 0; i < number; i++){

    printf("Altura da %d° pessoa\n", i+1);
    scanf("%lf",&height_vector[i]);
    printf("Genero da %d° pessoa\n", i+1);
    scanf("%s",&gender_vector[i]);

  }

  greater_height = height_vector[0]; // MAIOR ALTURA
  shorter_height = height_vector[0]; // MENOR ALTURA

  for ( i = 0; i < number; i++){
    if ( height_vector[i] > greater_height ){
        greater_height = height_vector[i];
    }

    if( height_vector[i] < shorter_height){
      shorter_height = height_vector[i];
    }

  }

  for (i = 0;i < number; i++){ // MEDIA DE ALTURA DE MULHERES
    if(gender_vector[i] == 'F'){
      sum = sum + height_vector[i];
      amount += 1;
    }
  
  }
  
  average = sum / amount;

  for (i = 0;i < number; i++){ // QUANTIDADE DE HOMENS
    if ( gender_vector[i] == 'M'){
      
     numberM++;
    }
  
  }
  
  printf("Menor altura = %.2lf\n", shorter_height);
  printf("Maior altura = %.2lf\n", greater_height);
  printf("Media das alturas das mulheres = %.2lf\n", average);
  printf("Numero de homens = %d\n", numberM);

  return 0;
}