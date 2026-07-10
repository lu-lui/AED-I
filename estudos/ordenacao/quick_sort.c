//implementação do algorítmo de ordenação quick sort
//versão estática

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int particiona(int *V, int inicio, int final);
void quick_sort(int *V, int inicio, int fim);

int main(){
    int V[] = {0, -9, -3, 5, 34, 22, -1, 1, -67};
    
    printf("Vetor desordenado: \n");
    for (int i = 0; i < 9; i++)
        printf("%d ", V[i]);
    printf("\n");
    
    quick_sort(V, 0, 8);

    printf("Vetor ordenado: \n");
    for (int i = 0; i < 9; i++)
        printf("%d ", V[i]);
    printf("\n");

    return 0;
}

int particiona(int *V, int inicio, int final){
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = final;
    pivo = V[inicio];

    while (esq < dir){
        while (V[esq] <= pivo)
            esq++;
        while(V[dir] > pivo)
            dir--;

        if (esq < dir){
            aux = V[esq];
            V[esq] = V[dir];
            V[dir] = aux;       
        }
    }
    
    V[inicio] = V[dir];
    V[dir] = pivo;
    return dir;
}

void quick_sort(int *V, int inicio, int fim){
    int pivo;

    if (fim > inicio){
        pivo = particiona(V, inicio, fim);
        quick_sort(V, inicio,  pivo - 1);
        quick_sort(V, pivo + 1, fim);
    }   
}