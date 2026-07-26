#include <stdio.h>
#include <stdlib.h>

int* nextGreaterElements (int* nums, int numsSize, int* returnSize);

int main () {
    int nums[] = {1, 2, 3, 4, 5};
    int *result;
    int returnSize;

    result = nextGreaterElements( nums, 5, &returnSize );

    for ( int i = 0; i < 5; i++ ) {
        printf ("%d\n", result[i]);
    }

    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements ( int* nums, int numsSize, int* returnSize ) {
    int *result = ( int * ) malloc ( numsSize * sizeof(int) );
    *returnSize = numsSize;
    int x;

    for ( int i = 0; i < numsSize; i++ ) {
        x = nums[i];
        for ( int j = i; j < numsSize; j++ ) {
            //tem que comparar com nums[i]
            if ( nums[j] > x && j+1 < numsSize ) {  //&& j+1 < numsSize faz parte de um codigo anterior onde estava usando uma abordagem diferente, nao é necessario e faz com que alguns casos não funcionem
                x = nums[j];
                break;
            } else { //recebe -1 se não encontra, na proxima repetição do loop estaria comparando com o -1 do x, não com o valor real
                x = -1;
            }
        }

        if ( x == -1 ) { //essa comparação é invalida, porque o -1 pode ser um elemento do vetor
            for ( int j = 0; j < i; j++ ) {
                if ( nums[j] > nums[i] ){
                    x = nums[j];
                    break;
                }
                
            }
            
        }
        result[i] = x;
    }
    
    return result;
}