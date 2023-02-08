#include <stdio.h>

int main(){

    int A, B, X;

    printf("Dígite um número: \n");
    scanf("%d", &A);
    printf("Dígite outro número: \n");
    scanf("%d", &B);
    
    X = A;
    A = B;
    B = X;

    printf("o valor de A: %d\n", A);
    printf("o valor de B: %d\n", B);

    return 0;
}