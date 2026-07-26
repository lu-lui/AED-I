//31. Leia um numero inteiro e imprima o seu antecessor e o seu sucessor.

#include<stdio.h>

int main(){
    int x;

    printf("Digite um número inteiro: ");
    scanf("%d", &x);
    
    printf("Antecessor: %d \nSucessor: %d\n", x - 1, x + 1);
    
    return 0;
}