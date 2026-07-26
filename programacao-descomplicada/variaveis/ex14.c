//14. Leia um angulo em graus e apresente-o convertido em radianos. A fórmula de conversão é: R = G ∗ π/180, sendo G o angulo em graus e R em radianos e π = 3.14.
#include<stdio.h>

int main(){
    int G;
    float R;

    printf("Digite um ângulo em graus: ");
    scanf("%d", &G);
    
    R = (float) G * 3.14 / 180;
    
    printf("%d graus = %.2f radianos\n", G, R);
    
    return 0;
}