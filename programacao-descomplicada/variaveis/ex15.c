//15. Leia um angulo em radianos e apresente-o convertido em graus. A fórmula de conversão é: G = R ∗ 180/π, sendo G o angulo em graus e ˆ R em radianos e π = 3.14.

#include<stdio.h>

int main(){
    float R;
    int G;

    printf("Digite um ângulo em radianos: ");
    scanf("%f", &R);
    
    G = R * 180 / 3.14;
    
    printf("%d graus = %.2f radianos\n", G, R);
    
    return 0;
}