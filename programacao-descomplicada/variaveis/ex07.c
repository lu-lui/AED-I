//7. Leia uma temperatura em graus Fahrenheit e apresente-a convertida em graus Celsius. A formula de conversão é: C = 5.0 ∗ (F − 32.0)/9.0, sendo C a temperatura em Celsius e F a temperatura em Fahrenheit.

#include <stdio.h>

int main(){
    float C, F;

    printf("Digite uma temperatura em graus Fahrenheit: ");
    scanf("%f", &F);

    C = 5.0 * (F - 32.0) / 9.0;

    printf("A temperatura %.2f °F corresponde a %.2f °C\n", F, C);

    return 0;
}