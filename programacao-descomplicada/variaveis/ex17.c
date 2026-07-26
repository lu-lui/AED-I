// 17. Leia um valor de comprimento em centímetros e apresente-o convertido em polegadas. A formula de conversão é: P = C / 2.54, sendo C o comprimento em cent´ımetros e P o comprimento em polegadas

#include<stdio.h>

int main(){
    float P, C;

    printf("Digite um valor em centímetros: ");
    scanf("%f", &C);
    
    P = C / 2.54;
    
    printf("%.2f polegadas = %.2f centímetros\n", P, C);
    
    return 0;
}