// 12. Leia uma distancia em milhas e apresente-a convertida em quilômetros. A fórmula de conversão é:  K = 1, 61 ∗ M, sendo K a distancia em quilômetros e M em milhas.

#include <stdio.h>

int main(){
    float M, K;

    printf("Digite uma distância  em milhas: ");
    scanf("%f", &M);

    K = 1.61 * M;

    printf("A distância %.2f milhas corresponde a %.2f quilômetros\n", M, K);

    return 0;
}