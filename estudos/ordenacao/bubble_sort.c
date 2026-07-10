//implementação do algorítmo de ordenação bubble sort
//versão estática

#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *V, int n);

int main(){
    int V[] = {0, -9, -3, 5, 34, 22, -1, 1, -67};
    
    printf("Vetor desordenado: \n");
    for (int i = 0; i < 9; i++)
        printf("%d ", V[i]);
    printf("\n");
    
    bubble_sort(V, 9);

    printf("Vetor ordenado: \n");
    for (int i = 0; i < 9; i++)
        printf("%d ", V[i]);
    printf("\n");

    return 0;
}

void bubble_sort(int *V, int n) {
    int i, continua, aux, fim = n;

    do {
        continua = 0;
        for ( i = 0; i < fim - 1; i++){
            if (V[i] > V[i+1]){
                aux = V[i];
                V[i] = V[i+1];
                V[i+1] = aux;
                continua = 1;
            }
        }
        fim--;
    } while (continua != 0);
    
}