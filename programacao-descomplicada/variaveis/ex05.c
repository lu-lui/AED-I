//5. Leia um numero real e imprima a quinta parte deste número. 

#include <stdio.h>

int main(){
    float n, n5;

    printf("Digite um número real: ");
    scanf("%f", &n);

    n5 = n / 5;

    printf("A quinta parte de %f é %f", n, n5);

    return 0;
}