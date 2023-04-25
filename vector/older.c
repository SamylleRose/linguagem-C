#include <stdio.h>

int main (){

  int number, i, dulthood = 0, vector_position = 0;
 
  scanf("%d", &number);

  char name[number] [50];
  int age[number];
  

  for (i = 0; i < number; i++){
    scanf("%s", &name[i][0]);
    scanf("%d", &age[i]);
   
  }

  for (i = 0; i < number; i++){
    if (age[i] > dulthood ){
      dulthood = age[i];
      vector_position = i;
  
    }
   
  }

  printf("PESSOA MAIS VELHA: %s\n", name[vector_position]);

  return 0;

}