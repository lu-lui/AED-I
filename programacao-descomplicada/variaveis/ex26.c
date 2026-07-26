//26. Leia um valor de area em metros quadrados  m2 e apresente-o convertido em hectares. A formula de conversão é: H = M ∗ 0, 0001, sendo M a area em metros quadrados e ´ H a area em hectares. 

#include<stdio.h>

int main(){
    float H, M;

    printf("Digite um valor em metros quadrados: ");
    scanf("%f", &M);
    
   H = M * 0.0001;
    
    printf("%f hectares = %.2f metros quadrados\n", H, M);
    
    return 0;
}