#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int *nums, int inicio, int fim);

int main(){
    srand(time(NULL));
    int V[] = {0, -9, -3, 5, 34, 22, -1, 1, -67};
    
    printf("Vetor desordenado: \n");
    for (int i = 0; i < 9; i++)
        printf("%d ", V[i]);
    printf("\n");
    
    quicksort(V, 0, 9);

    printf("Vetor ordenado: \n");
    for (int i = 0; i < 9; i++)
        printf("%d ", V[i]);
    printf("\n");

    return 0;
}
    

void quicksort(int *nums, int inicio, int fim){
    int meio, temp, i, j, numeAleatorio;
    numeAleatorio = inicio + rand() % (fim - inicio + 1);
    i = inicio;
    j = fim;
    meio = nums[numeAleatorio];

    do{
        while (nums[i] < meio){
            i++;
        }
        while (nums[j] > meio){
            j--;
        }
        
        if(i <= j){
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);

    if(j > inicio){         
        quicksort(nums, inicio, j);     
    } 
    
    if(i < fim){         
        quicksort(nums, i, fim);     
    } 
}
