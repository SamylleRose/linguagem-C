#include <stdio.h>

int soma(int a, int b) {
    return a + b;
}

int main() {
    // Declaração do ponteiro para a função
    int (*ptr_soma)(int, int);
    
    // Atribuição do endereço da função 'soma' ao ponteiro
    ptr_soma= &soma;

    // Chamada da função através do ponteiro
    int resultado = ptr_soma(5, 7);

    printf("Resultado da soma: %d\n", resultado);

    return 0;
}
