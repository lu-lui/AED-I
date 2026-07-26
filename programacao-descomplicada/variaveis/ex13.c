// 13. Leia uma distancia em quilômetros e apresente-a convertida em milhas. A fórmula de conversão é:  M = K / 1,61, sendo K a distancia em quilômetros é M em milhas.   

#include <stdio.h>

int main(){
    float M, K;

    printf("Digite uma distância  em quilomêtros: ");
    scanf("%f", &K);

    M = K / 1.61;

    printf("A distância %.2f quilõmetros corresponde a %.2f milhas\n", K, M);

    return 0;
}