#include <stdio.h>
#include <stdlib.h>

int* nextGreaterElements ( int* nums, int numsSize, int* returnSize );

int main() {
    int *nums;
    int *result;
    int numsSize;
    int returnSize;

    printf ("Numero de elementos do vetor: ");
    scanf ("%d", &numsSize);

    nums = ( int * ) malloc ( numsSize * sizeof (int) );

    for ( int i = 0; i < numsSize; i++ ) {
        printf ("Indice %d: ", i);
        scanf ("%d", &nums[i]);
    }
    
    result = nextGreaterElements ( nums, numsSize, &returnSize );

    for ( int i = 0; i < returnSize; i++ ) {
        printf ("%d \n", result[i]);
    }

    free(nums);
    
    return 0;
}


int* nextGreaterElements ( int* nums, int numsSize, int* returnSize ) {
    int *result = ( int * ) malloc ( numsSize * sizeof(int) );
    *returnSize = numsSize;
    int x; 

    for ( int i = 0; i < numsSize; i++ ) {
        x = 0;
        result[i] = -1;

        for ( int j = i ; j < numsSize; j++ ) {
            if ( nums[j] > nums[i] ) {  
                result[i] = nums[j];
                x = 1;
                break;
            } 
        }

        if ( !x ) {
            for ( int j = 0; j < i; j++ ) {
                if ( nums[j] > nums[i] ) {
                    result[i] = nums[j];
                    break;
                }
            }
        }
    }
    return result;
}