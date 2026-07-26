/*39. A importância de R$ 780.000,00 será dividida entre três ganhadores de um concurso. Sendo que da quantia total: 
    O primeiro ganhador receberá 46%; 
    O segundo receberá 32%; 
    O terceiro receberá o restante;
Calcule e imprima a quantia ganha por cada um dos ganhadores.*/

#include <stdio.h>

int main(){
    float i = 780000;

    printf("Valor total do prêmio: R$%.2f: \n", i);
    printf("Quantia recebida pelo ganhador 1:  R$%.2f \n", i * 0.46);
    printf("Quantia recebida pelo ganhador 2:  R$%.2f \n", i * 0.32);
    printf("Quantia recebida pelo ganhador 2:  R$%.2f \n", i * 0.22);

    return 0;
}