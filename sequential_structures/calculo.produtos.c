#include <stdio.h>

int main() {
    int c1, c2, np1, np2; 
    double vt, v1, v2;

    scanf("%d%d%lf", &c1, &np1, &v1);
    scanf("%d%d%lf", &c2, &np2, &v2);

    vt = (np1 * v1) + (np2 * v2);

    printf("VALOR A PAGAR: R$ %.2lf\n", vt);
    return 0;
}
