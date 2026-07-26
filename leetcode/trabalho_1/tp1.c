#include <stdio.h>
#include <stdlib.h>

int* findDiagonalOrder( int** mat, int matSize, int* matColSize, int* returnSize );

int main () {
    int m, n;
    int returnSize;
    int **mat;
    int *vet;

    printf ("Numero de linhas: ") ;
    scanf ("%d", &m) ;

    printf ("Numero de colunas: ") ;
    scanf ("%d", &n) ;

    mat = ( int** ) malloc ( m * sizeof( int* ) ) ;
    for ( int l = 0; l < m; l++ ) {
        mat[l] = ( int* ) malloc ( n * sizeof ( int ) ) ;
    }

    printf ( "Digite os valores da matriz:\n" ) ;
    for ( int l = 0; l < m; l++ ) {
        for ( int c = 0; c < n; c++ ) {
            printf ("Valor [%d][%d]: ", l, c) ;
            scanf ("%d", &mat[l][c]) ;
        }
    }

    vet = findDiagonalOrder ( mat, m, &n, &returnSize ) ;

    printf ("Vetor gerado: ") ;
    for ( int i = 0; i < returnSize; i++ ) {
        printf ("%d ", vet[i]) ;
    }
    printf ( "\n" ) ;

    free ( vet ) ;

    for ( int l = 0; l < m; l++ ) {
        free ( mat[l] ) ;
    }
    free ( mat ) ;

    return 0;
}


/*
====================
findDiagonalOrder
 Lê os valores da diagonal de uma matriz em zig-zag e escreve os mesmos em um vetor linear 
====================
*/

int* findDiagonalOrder ( int** mat, int matSize, int* matColSize, int* returnSize ) {
    int m = matSize;
    int n = *matColSize;
    int x = 0;
    int *v;

    *returnSize = m * n;

    v = malloc ( m * n * sizeof ( int ) ) ;

    for ( int d = 0; d < m + n - 1; d++ ) {

    if ( d % 2 == 0 ) {
        for ( int l = m - 1; l >= 0; l-- ) {
            int c = d - l;
            if ( c >= 0 && c < n ) {
                v[x] = mat[l][c];
                x++;
            }
        }
    } else {
        for ( int l = 0; l < m; l++ ) {
            int c = d - l;
            if ( c >= 0 && c < n ) {
                v[x] = mat[l][c];
                x++;
            }
        }
    }
}

    return v;
}