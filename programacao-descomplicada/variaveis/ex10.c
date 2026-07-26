// 10. Leia uma velocidade em km/h (quilometros por hora) e apresente-a convertida em m/s (metros por segundo). A formula de conversão é:  M = K/3.6, sendo K a velocidade em km/h e M em m/s.

#include <stdio.h>

int main(){
    float M, K;

    printf("Digite uma velocidade em km/h: ");
    scanf("%f", &K);

    M = K / 3.6;

    printf("A velocidade %.2f km/h corresponde a %.2f m/s\n", K, M);

    return 0;
}