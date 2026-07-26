// 21. Leia um valor de massa em libras e apresente-o convertido em quilogramas. A formula de conversão é: K = L ∗ 0, 45, sendo K a massa em quilogramas e L a massa em libras.

#include<stdio.h>

int main(){
    float L, K;

    printf("Digite um valor em libras: ");
    scanf("%f", &L);
    
   K = L * 0.45;
    
    printf("%.2f quilogramas = %.2f libras\n", K, L);
    
    return 0;
}