//Implementação usando uma pilha

#include <stdio.h>
#include <stdlib.h>

int* nextGreaterElements(int* nums, int numsSize, int* returnSize);

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

    free (nums);
    free (result);
    
    return 0;
}

int* nextGreaterElements ( int* nums, int numsSize, int* returnSize ) {
    int *result = ( int * ) malloc ( numsSize * sizeof(int) );
    int *values = ( int * ) malloc ( numsSize * sizeof(int) );
    int *positions = ( int * ) malloc ( numsSize * sizeof(int) );
    int p;
    int top = -1;
    *returnSize = numsSize;

    for ( int i = 0; i < numsSize; i++ ) {
        result[i] = -1;
    }    

    for ( int i = 0; i < numsSize; i++ ) {
        while ( top >= 0 && values[top] < nums[i] ) {
            p = positions[top];
            result[p] = nums[i];
            top--;
        }
        
        top++;
        values[top] = nums[i];
        positions[top] = i;
    }

    for ( int i = 0; i < numsSize; i++ ) {
        if ( top < 0 ) {
            break;
        }

        while ( top >= 0 && values[top] < nums[i] ) {
            p = positions[top];
            result[p] = nums[i];
            top--;
        }
    }

    free (values);
    free (positions);
    return result;
}