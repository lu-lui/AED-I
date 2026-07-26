// 18. Leia um valor de volume em metros cubicos m3 e apresente-o convertido em litros. A formula de conversão é: L = 1000 ∗ M, sendo L o volume em litros e M o volume em metros cubicos. 

#include<stdio.h>

int main(){
    float L, M;

    printf("Digite um valor em metros cúbicos: ");
    scanf("%f", &M);
    
    L = 1000 * M;
    
    printf("%.2f metros cubicos = %.2f litros\n", M, L);
    
    return 0;
}