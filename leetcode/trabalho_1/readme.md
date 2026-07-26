## Luísa Passos Neutzling
## Turma: M1

### 498. Travessa Diagonal

Dada uma `m x n` matriz `mat`, retorne um array contendo todos os elementos da matriz em ordem diagonal .

 
## Exemplo 1:

Entrada: mat = [[1,2,3],[4,5,6],[7,8,9]]
 Saída: [1,2,4,7,5,3,6,8,9]

## Exemplo 2:

Entrada: mat = [[1,2],[3,4]]
 Saída: [1,2,3,4]


## Testes:
Entrada: mat = { { 7, 8, 9, 8, 7 }, 
                 { 3, 3, 3, 2, 1 } }

Saída: { 7, 8, 3, 3, 9, 8, 3, 2, 7, 1 }


 Entrada: mat = { { 1, 2, 6 }, 
                  { 3, 5, 7 },
                  { 4, 8, 9 } }

 Saída: { 1, 2, 3, 4, 5, 6, 7, 8, 9 }


  Entrada: mat = { { 1, 1 }, 
                   { 2, 3 }, 
                   { 2, 3 },
                   { 4, 4 }}

 Saída: { 1, 1, 2, 2, 3, 3, 4, 4, }

## Restrições:

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
-105 <= mat[i][j] <= 105