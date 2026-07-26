// 45. Faça um programa para converter uma letra maiúscula em letra minúscula. Use a tabela ASCII para resolver o problema.

#include <stdio.h>

int main(){
    char C;

    printf("Digite uma letra MAIÚSCULA: ");
    scanf("%c", &C);

     printf("Letra minúscula %c: ", C + 32);

    return 0;
}