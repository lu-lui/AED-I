// 16. Leia um valor de comprimento em polegadas e apresente-o convertido em centímetros. A formula de conversão é: C = P ∗ 2, 54, sendo C o comprimento em cent´ımetros e P o comprimento em polegadas.
#include<stdio.h>

int main(){
    float P, C;

    printf("Digite um valor em polegadas: ");
    scanf("%f", &P);
    
    C = P * 2.54;
    
    printf("%.2f polegadas = %.2f centímetros\n", P, C);
    
    return 0;
}