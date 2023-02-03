#include <stdio.h>

int main(){

    double grades1, grades2, grades3, grades4, average;

    printf("Digite a primeira nota:\n");
    scanf("%lf", &grades1);
    printf("Digite a segunda nota:\n");
    scanf("%lf", &grades2);
    printf("Digite a terceira nota:\n");
    scanf("%lf", &grades3);
    printf("Digite a quarta nota:\n");
    scanf("%lf", &grades4);

    average = (grades1 + grades2 + grades3 +grades4)/4;

    printf("A media das quatro notas é: %.2lf\n", average);

    return 0;
}