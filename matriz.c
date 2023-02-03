#include <stdio.h>

int main(){
    int mat[3][3], l, c;
    
    printf("informe a matriz:\n");
    for (l=0; l<3; l++){
        for (c=0; c<3; c++){
            printf("informe o elemento da linha %d, coluna %d:\n", l+1, c+1);
            scanf("%d", &mat[l][c]);
        }
    } 
    printf("---------MATRIZ----------\n");
    for (l=0; l<3; l++){
        for (c=0; c<3; c++){
            printf("%d\t", mat[l][c]);  
        }
        printf("\n");     
    }
    
    return 0;
}