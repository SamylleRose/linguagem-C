#include <stdio.h>

int main() {

    int number, count_numberes = 0;

    printf("Informe um numero:\n");
    scanf("%d", &number);

    if (number != 0){
         count_numberes = count_numberes + 1;
         number = number / 10;

     }
     
     if (number != 0){
        count_numberes = count_numberes + 1;
        number = number / 10;

     }

     if (number != 0){
          count_numberes = count_numberes + 1;
          number = number / 10;
     
     } 
          
     if (number != 0){
          count_numberes = count_numberes + 1;
          number = number / 10;
          
     } 
            
     if (number != 0){
          count_numberes = count_numberes + 1;
          number = number / 10;
            
     } 
              
     if (count_numberes == 5){ 
          printf("Esta na casa acima dos milhares.\n");       
     } else if (count_numberes == 4){ 
          printf("Esta na casa dos milhares.\n");;                         
     } else if (count_numberes == 3){ 
          printf("Esta na casa das centenas.\n");           
     }  else if (count_numberes == 2){ 
          printf("Esta na casa das dezenas.\n");            
     }  else if (count_numberes == 1){ 
          printf("Esta na casa das unidades.\n");                 
     } 

    return 0;
}