// 37. Faça um programa que leia o valor de um produto e imprima o valor com desconto, tendo em vista que o desconto foi de 12%

#include <stdio.h>

int main(){
    float p;

    printf("Valor do produto (R$): ");
    scanf("%f", &p);

    printf("Valor com desconto: R$%.2f\n", p - (p * 0.12));

    return 0;
}