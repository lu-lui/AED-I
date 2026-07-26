//30. Leia um valor em real e a cotação do dólar. Em seguida, imprima o valor correspondente em dolares. ´

#include<stdio.h>

int main(){
    float x, cotacao;

    printf("Valor em R$: ");
    scanf("%f", &x);
    
    printf("Cotaação só dólar hoje: ");
    scanf("%f", &cotacao);
    
    printf("Valor convertido: $%.2f\n", x / cotacao);
    
    return 0;
}