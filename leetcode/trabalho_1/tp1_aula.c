/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {
   int m = matSize;
   int n = *matColSize;
   int x = 0;
   int v[m*n];
   
    for(int l = 0; l < m; l++){
        for(int c = 0; c < n; c++){
           while(x <= *returnSize){ 
            v[x] = mat[l][c]; // *
            x++;
           }
        }
    }

    return v;
}

//0.0 -> 0.1 -> 1.0 -> 2.0 -> 1.1 -> 0.2 -> 1.2 -> 2.1 -> 2.2
