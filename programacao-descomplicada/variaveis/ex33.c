//33. Leia o tamanho do lado de um quadrado e imprima como resultado a sua area

#include <stdio.h>

int main(){
    int l;

    printf("Informe o lado do quadrado: ");
    scanf("%d", &l);

    printf("Área: %d\n", l * l);

    return 0;
}