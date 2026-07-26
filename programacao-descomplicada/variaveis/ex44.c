//44. Receba a altura do degrau de uma escada e a altura que o usuário deseja alcançar subindo a escada. Calcule e mostre quantos degraus o usuário deverá subir para atingir seu objetivo.

#include <stdio.h>
#include <math.h>

int main(){
    float altura_degrau, objetivo, total_degraus;

    printf("Altura do degrau (m): ");
    scanf("%f", &altura_degrau);

    printf("Que altura deseja alcançar (m)? ");
    scanf("%f", &objetivo);


    total_degraus = ceil(objetivo / altura_degrau);

    printf("Será necessário subir %.0f degraus para se chegar a %.2f metros\n", total_degraus, objetivo);

    return 0;
}