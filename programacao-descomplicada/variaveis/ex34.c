// 34. Leia o valor do raio de um circulo e calcule e imprima a area do circulo correspondente. A area do circulo e π ∗ raio², considere π = 3.141592.

#include <stdio.h>

int main(){
    double x, pi = 3.141592;

    printf("Valor do raio: ");
    scanf("%lf", &x);

    printf("Área do círculo: %lf\n", pi * (x * x));

    return 0;
}