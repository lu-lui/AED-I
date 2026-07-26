//25. Leia um valor de area em acres e apresente-o convertido em m2. A fórmula de conversão é: M = A ∗ 4048, 58, sendo M a area em metros quadrados e A a area em acres. 

#include<stdio.h>

int main(){
    float A, M;

    printf("Digite um valor em acres: ");
    scanf("%f", &A);
    
    M = A * 4048.58;
    
    printf("%f acres = %.2f metros quadrados\n", A, M);
    
    return 0;
}