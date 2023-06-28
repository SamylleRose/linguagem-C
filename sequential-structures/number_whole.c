#include <stdio.h>
// #include <string.h>

int main(){

    char CDU[3];
    char UDC[3];

    printf("Informe um número na ordem : dezena, centena e unidade.\n");
    scanf("%s", CDU);

    // strcpy(RECEBE, TRANSFERE);
    UDC[0] = CDU[2];
    UDC[1] = CDU[1];
    UDC[2] = CDU[0]; 

    printf("O número na ordem, unidade, dezena e centena é: %s\n", UDC);

    return 0;
}