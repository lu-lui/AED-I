// 32. Leia um numero inteiro e imprima a soma do sucessor de seu triplo com o antecessor de seu dobro.

#include <stdio.h>

int main(){
    int x, y;

    printf("Digite um numero inteiro: ");
    scanf("%d", &x);

    y = ((x * 3) + 1) + ((x * 2) - 1);

    printf("Resultado: %d\n", y);

    return 0;
}