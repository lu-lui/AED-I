// 46. Faça um programa que leia um número inteiro positivo de três dígitos (de 100 a 999). Gere outro número formado pelos dígitos invertidos do número lido. Exemplo: nro digitado: 123   nero mostrado: 321

#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);

    while (n > 0) {
        printf("%d", n % 10);
        n = n / 10;
    }

    printf("\n");

    return 0;
}