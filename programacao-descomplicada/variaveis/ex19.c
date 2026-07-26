// 19. Leia um valor de volume em litros e apresente-o convertido em metros cubicos m3 .A formula de conversão é: M = L / 1000, sendo L o volume em litros e M o volume em metros cubicos. 

#include<stdio.h>

int main(){
    float L, M;

    printf("Digite um valor em litros: ");
    scanf("%f", &L);
    
    M = L / 1000;
    
    printf("%.2f metros cubicos = %.2f litros\n", M, L);
    
    return 0;
}