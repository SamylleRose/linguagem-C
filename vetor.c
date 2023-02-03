#include <stdio.h>

int main(){

    int a=5, i, vet[a];

    for (i=0; i<a; i++){
        printf("\n digite o numero vetor %d: ", i+1);
        scanf("%d", &vet[i]);
    }

    for (i=0; i<a; i++){
        printf("%d\t", vet[i]);
    }
    
    printf("\n");

    return 0;
}
