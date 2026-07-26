// 22. Leia um valor de comprimento em jardas e apresente-o convertido em metros. A formula de conversão é:  M = 0, 91 ∗ J, sendo J o comprimento em jardas e M o comprimento em metros.


#include<stdio.h>

int main(){
    float J, M;

    printf("Digite um valor em jardas: ");
    scanf("%f", &J);
    
    M = 0.91 * J;
    
    printf("%.2f jardas = %.2f metros\n", J, M);
    
    return 0;
}