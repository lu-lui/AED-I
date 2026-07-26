//6. Leia uma temperatura em graus Celsius e apresente-a convertida em graus Fahrenheit. A formula de conversão é: F = C∗(9.0/5.0)+32.0, sendo F a temperatura em Fahrenheit e C a temperatura em Celsius.

#include <stdio.h>

int main(){
    float C, F;

    printf("Digite uma temperatura em graus Celsius: ");
    scanf("%f", &C);

    F = C * (9.0 / 5.0) + 32;

    printf("A temperatura %.2f °C corresponde a %.2f °F\n", C, F);

    return 0;
}