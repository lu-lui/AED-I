//Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
//You must write an algorithm with O(log n) runtime complexity.

int searchInsert(int* nums, int numsSize, int target);

#include <stdio.h>
#include <stdlib.h>

int main(){
    int *nums;
    int numsSize, target, result;

    printf("Numero de elementos: ");
    scanf("%d", &numsSize);

    nums = (int *)malloc( numsSize * sizeof(int));

    for (int i = 0; i < numsSize; i++){
        printf("Elemento %d: ", i);
        scanf("%d", &nums[i]);
    }

    printf("Valor alvo: ");
    scanf("%d", &target);
    
    result = searchInsert(nums, numsSize, target);

    printf("Indice: %d\n", result);

    return 0;
}

int searchInsert(int* nums, int numsSize, int target) {
    int result;
    int meio;
    int inicio = 0;
    int fim = numsSize - 1;

    while (inicio <= fim) {
        meio = inicio + (fim - inicio) / 2;

        if (nums[meio] == target) {
            result = meio;          
        }
        else if (nums[meio] < target) {
            inicio = meio + 1;  
        }
        else {
            fim = meio - 1;    
        }
    }
    
    result = inicio;
    return result;
}