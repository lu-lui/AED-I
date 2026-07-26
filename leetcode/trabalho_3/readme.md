## Luísa Passos Neutzling
## Turma: M1

### 775. Inversões Globais e Locais ( Global and Local Inversions )
## Use avl na solucao

Voce recebe um array de inteiros nums de comprimento n que representa uma permutacao de todos os inteiros no intervalo `[0, n - 1]`.

O numero de inversoes GLOBAIS e o numero de pares ( i, j ) diferentes onde:
	`0 <= i < j < n  e  nums[i] > nums[j]`

O numero de inversoes LOCAIS e o numero de indices i onde:
    `0 <= i < n - 1  e  nums[i] > nums[i + 1]`

Retorne true se o numero de inversoes globais for igual ao numero de inversoes locais.
 

## Exemplo 1:

Entrada: nums = [1,0,2]
 Saida: true
		
**Explicação:** Há 1 inversão global e 1 inversão local.

## Exemplo 2:

Entrada: nums = [1,2,0]
 Saida: false
		
**Explicacao:** Há 2 inversões globais e 1 inversão local.


## Testes:
`[1, 0, 2 ]` exemplo 1 do enunciado        

`[1, 2, 0 ]` exemplo 2 do enunciado        

`[0]`	 elemento unico                

`[0, 1, 2, 3, 4]`	identidade: zero inversoes    

`[1, 0, 3, 2, 4 ]` trocas adjacentes disjuntas     

`[2, 0, 1 ]` valor a 2 posicoes do lugar       

`[4, 3, 2, 1, 0 ]` permutacao reversa             

`[0, 2, 1]` uma troca adjacente no fim       

`[1, 0, 2, 4, 3]` trocas nas duas pontas         

`[3, 0, 1, 2 ]` 3 globais, 1 local              

 
## Restricoes:
-> n == nums.length

-> 1 <= n <= 10^5

-> 0 <= nums[i] < n

-> Todos os inteiros de nums sao distintos

-> nums e uma permutacao de todos os numeros no intervalo [0, n - 1]


**Nota:** existe solucao mais eficiente, esta versao e para estudar a tecnica de árvore avl.
