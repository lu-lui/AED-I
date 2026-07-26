//3. Peça ao usuario para digitar três valores inteiros e imprima a soma deles.

#include <stdio.h>

int main(){
    int soma = 0, c;
    printf("Digite três valores a serem somados: \n");

    for (int i = 1; i <= 3; i++){
        printf("Valor %d: ", i);
        scanf("%d", &c);
        soma += c;
    }
    
    printf("Soma dos três valores digitados: %d", soma);

    return 0;
}