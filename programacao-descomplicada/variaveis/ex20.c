// 20. Leia um valor de massa em quilogramas e apresente-o convertido em libras. A formula de conversão é: L = K / 0.45, sendo K a massa em quilogramas e L a massa em libras.

#include<stdio.h>

int main(){
    float L, K;

    printf("Digite um valor em quilogramas: ");
    scanf("%f", &K);
    
    L = K / 0.45;
    
    printf("%.2f quilogramas = %.2f libras\n", K, L);
    
    return 0;
}