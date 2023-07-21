#include <stdio.h>

void trocastring(char *ponteiro);

int main(){ 

    char string[7] = "passaro";
    printf("%s\n", string);

    trocastring(string);
   
    printf("%s\n", string);

    return 0;
}

void trocastring(char *ponteiro){ 
    int i;

    for (i = 0; i < 7; i++){
      *ponteiro = '*';
      *ponteiro ++;
      *ponteiro = '\0';
    }
    

}