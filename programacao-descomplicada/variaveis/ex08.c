// 8. Leia uma temperatura em graus Kelvin e apresente-a convertida em graus Celsius. A formula de conversão é: C = K − 273.15, sendo C a temperatura em Celsius e K a temperatura em Kelvin.

#include <stdio.h>

int main(){
    float C, K;

    printf("Digite uma temperatura em Kelvin: ");
    scanf("%f", &K);

    C = K - 273.15;

    printf("A temperatura %.2f K corresponde a %.2f °C\n", K, C);

    return 0;
}