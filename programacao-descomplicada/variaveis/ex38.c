// 38. Leia o salário de um funcionário. Calcule e imprima o valor do novo salário, sabendo que ele recebeu um aumento de 25%.

#include <stdio.h>

int main(){
    float p;

    printf("Valor do salário (R$): ");
    scanf("%f", &p);

    printf("Salário após o aumento: R$%.2f\n", p + (p * 0.25));

    return 0;
}