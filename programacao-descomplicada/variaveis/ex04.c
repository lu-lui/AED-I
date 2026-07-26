//4. Leia um numero real e imprima o resultado do quadrado desse número.

#include <stdio.h>

int main(){
    double n;

    printf("Digite um número real: ");
    scanf("%lf", &n);

    printf("Quadrado do número digitado: %lf\n", n * n);

    return 0;
}