#include <stdio.h>

int main(){

    char digit[3];

    printf("Informe um número de três algarismos:\n");
    scanf("%s", digit);

    printf("%c %c %c\n", digit[0], digit[1], digit[2]);

    return 0;
}