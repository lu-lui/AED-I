//26. Leia um valor de area em hectares e apresente-o convertido em m2. A formula de conversão é: M = H * 10000, sendo M a area em metros quadrados e H a area em hectares. 

#include<stdio.h>

int main(){
    float H, M;

    printf("Digite um valor em hectares: ");
    scanf("%f", &H);
    
   M = H * 10000;
    
    printf("%.2f hectares = %.2f metros quadrados\n", H, M);
    
    return 0;
}