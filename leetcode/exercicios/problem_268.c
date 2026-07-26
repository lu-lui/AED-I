//Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int missingNumber(int* nums, int n);
void merge_sort(int *V, int inicio, int fim);
void merge(int *V, int inicio, int meio, int fim);

int main(){
    int *nums;
    int n;
    int result;

    printf("Intervalo do vetor: [0, __]?\n");
    scanf("%d", &n);

    nums = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++){
        printf("Elemento %d: ", i);
        scanf("%d", &nums[i]);
    }
    
    result = missingNumber(nums, n);

    printf("Elemento faltante: %d\n", result);

    free(nums);
    return 0;
}

int missingNumber(int* nums, int n) {
    merge_sort(nums, 0, n - 1);

    if (nums[0] != 0)
        return 0;

    for (int i = 1; i < n; i++) {
        if (nums[i] != nums[i - 1] + 1)
            return nums[i - 1] + 1;
    }

    return n;
}

void merge(int *V, int inicio, int meio, int fim){
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim-inicio+1;
    p1 = inicio;
    p2 = meio+1;
    temp = (int *)malloc(tamanho * sizeof(int));
    if (temp != NULL){
        for ( i = 0; i < tamanho; i++){
            if (!fim1 && !fim2){
                if (V[p1] < V[p2])
                    temp[i] = V[p1++];
                else
                    temp[i] = V[p2++];

                if(p1 > meio)
                    fim1 = 1;
                if(p2 > fim)
                    fim2 = 1;
            } else {
                if (!fim1)
                    temp[i] = V[p1++];
                else
                    temp[i] = V[p2++];
            }
        }
        for ( j = 0, k = inicio; j < tamanho; j++, k++)
            V[k] = temp[j];
    }
    free(temp);
}

void merge_sort(int *V, int inicio, int fim){
    int meio;
    if (inicio < fim) {
        meio = floor((inicio+fim)/2);

        merge_sort(V, inicio, meio);
        merge_sort(V, meio + 1, fim);
        merge(V, inicio, meio, fim);
    }
}
