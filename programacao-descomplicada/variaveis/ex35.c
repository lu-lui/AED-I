// 35. Sejam a e b os catetos de um triangulo, onde a hipotenusa é obtida pela equação: hipotenusa = √(a² + b). Faça um programa que receba os valores de a e b e calcule o valor da hipotenusa atraves da equação. Imprima o resultado dessa operação

#include <stdio.h>
#include <math.h>

int main(){
    double a, b, h;

    printf("Valor de A: ");
    scanf("%lf", &a);

    printf("Valor de B: ");
    scanf("%lf", &b);

    h = (a * a) + (b * b); 

    printf("Hipotenusa: %.2lf\n", sqrt(h));

    return 0;
}