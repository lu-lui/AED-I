// 9. Leia uma temperatura em graus Celsius e apresente-a convertida em graus Kelvin. A formula de conversão é: K = C + 273.15, sendo C a temperatura em Celsius e K a temperatura em Kelvin.

#include <stdio.h>

int main(){
    float C, K;

    printf("Digite uma temperatura em graus Celsius: ");
    scanf("%f", &C);

    K = C + 273.15;

    printf("A temperatura %.2f °C corresponde a %.0f K\n", C, K);

    return 0;
}