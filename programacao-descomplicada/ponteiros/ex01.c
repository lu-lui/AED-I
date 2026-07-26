//1. Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro, real, e char. Associe as variaveis aos ponteiros (use &). Modifique os valores de cada variavel usando os ponteiros. Imprima os valores das variáveis antes e depois da modificação. 

#include <stdio.h>

int main (){
    int I = 1, *i;
    float F = 0.5, *f;
    char C = 'L', *c;

    printf("INTEIRO: %d \nREAL: %.2f \nCHAR: %c\n", I, F, C);

    i = &I;
    f = &F;
    c = &C;

    *i = 555;
    *f = 1.23;
    *c = 'Z';

    printf("-----Após modificação-----\n");
    printf("INTEIRO: %d \nREAL: %.2f \nCHAR: %c \n", I, F, C);

    return 0;
}