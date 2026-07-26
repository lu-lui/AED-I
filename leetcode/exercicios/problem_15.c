/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge(int *V, int inicio, int meio, int fim);
void merge_sort(int *V, int inicio, int fim);

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);

int main(){
    int** result;
    int* returnColumnSizes;
    int *nums; 
    int returnSize;
    int numsSize;

    printf("Digite o número de valores a serem inseridos no vetor: ");
    scanf("%d", &numsSize);

    nums = (int *)malloc(numsSize * sizeof(int));

    for (int i = 0; i < numsSize; i++){
        printf("Elemento %d: ", i);
        scanf("%d", &nums[i]);
    }    
    
    result = threeSum(nums, numsSize, &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; i++){
          for (int j = 0; j < returnColumnSizes[i]; j++){
               printf("%d ", result[i][j]);
          }
          printf("\n");
     }

    for (int i = 0; i < returnSize; i++)
        free(result[i]);

    free(result);
    free(returnColumnSizes);
    free(nums);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int **result = NULL;
    *returnSize = 0;
    *returnColumnSizes = NULL;

    merge_sort(nums, 0, numsSize - 1);

    for (int i = 0; i < numsSize; i++){
        for (int j = i+1; j < numsSize; j++){
            for (int k  = numsSize; k > 1; k--){
                if (j == k)
                    return;
                if(nums[i] + nums[j] + nums[k] == 0){
                    result = realloc(result, (*returnSize + 1) * sizeof(int *)); //aloca 1 linha matriz
                    result[*returnSize] = (int *)malloc(3 * sizeof(int)); //aloca espaco para 3 ints
                    
                    result[*returnSize][0] = nums[i];
                    result[*returnSize][1] = nums[j];
                    result[*returnSize][2] = nums[k];

                    *returnColumnSizes = realloc(*returnColumnSizes, (*returnSize + 1) * sizeof(int));

                    (*returnColumnSizes)[*returnSize] = 3;
                    (*returnSize)++;
                }
            }
        } 
    }
    
    return result;
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