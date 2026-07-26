## Luísa Passos Neutzling
## Matrícula: 25101673
## Turma: M1

### 18. 4Sum ( Soma de Quatro )

Dado um array nums de n inteiros, retorne um array com todas as quadruplas **UNICAS** [ `nums[a]`, `nums[b]`, `nums[c]`, `nums[d]` ] tais que:

-> 0 <= `a`, `b`, `c`, `d` < n

-> `a`, `b`, `c` e `d` são distintos

-> `nums[a]` + `nums[b]` + `nums[c]` + `nums[d]` == **target**

Voce pode retornar a resposta em qualquer ordem.
		

## Exemplo 1:

Entrada: nums = [1,0,-1,0,-2,2], target = 0

Saida: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
		

## Exemplo 2:

Entrada: nums = [2,2,2,2,2], target = 8

Saida: [[2,2,2,2]]


## Testes:
`[1, 0, -1, 0, -2, 2]` - Exemplo 1 do enunciado 

`[2, 2, 2, 2, 2]` - Exemplo 2 do enunciado - duplicatas extremas

`[1, 2, 3 ]` - Menos de 4 elementos - resposta vazia

`[1000000000, 1000000000, 1000000000, 1000000000]` - Overflow - 4 * 10^9 com int estoura para -294967296

`[-3, -2, -1, 0, 0, 1, 2, 3]` - Negativos e simetrias - 8 quadruplas

`[1, 2, 3, 4]` - Negativos e simetrias - 8 quadruplas

`[1, 2, 3, 4]` - Exatamente 4 elementos que NAO somam o alvo

`[0, 0, 0, 0, 0, 0]` - Todos iguais a zero - deve sair UMA quadrupla, nao varias 

`[-5, -4, -3, -2, -1]` - Todos negativos com alvo negativo

`[4, 3, 3, 4, 4, 2, 1, 2, 1, 1]` - Duplicatas espalhadas e desordenadas         

 
## Restricoes:
-> 1 <= nums.length <= 200

-> -10^9 <= nums[i] <= 10^9

->-10^9 <= target <= 10^9