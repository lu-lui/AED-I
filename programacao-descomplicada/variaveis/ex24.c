//24. Leia um valor de area em metros quadrados m2 e apresente-o convertido em acres. A fórmula de conversão é: A = M ∗ 0.000247, sendo M a area em metros quadrados e A a area em acres. 

#include<stdio.h>

int main(){
    float A, M;

    printf("Digite um valor em metros quadrados: ");
    scanf("%f", &M);
    
    A = M * 0.00024;
    
    printf("%f acres = %.2f metros quadrados\n", A, M);
    
    return 0;
}