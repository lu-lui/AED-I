// 23. Leia um valor de comprimento em metros e apresente-o convertido em jardas. A formula de conversão é: J = M / 0.91 , sendo J o comprimento em jardas e M o comprimento em metros

#include<stdio.h>

int main(){
    float J, M;

    printf("Digite um valor em metros: ");
    scanf("%f", &M);
    
    J = M / 0.91;
    
    printf("%.2f jardas = %.2f metros\n", J, M);
    
    return 0;
}