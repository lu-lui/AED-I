// 36. Leia a altura e o raio de um cilindro circular e imprima o volume do cilindro. O volume de um cilindro circular e calculado por meio da seguinte fórmula: V = π ∗ raio² ∗ altura, onde π = 3.141592.

#include <stdio.h>

int main(){
    double  r, h, pi = 3.141592;

    printf("Valor do raio: ");
    scanf("%lf", &r);

    printf("Valor do altura: ");
    scanf("%lf", &h);

    printf("Volume do cilindro: %lf\n", pi * (r * r) * h);

    return 0;
}