## Luísa Passos Neutzling
## Turma: M1

28. Encontre o índice da primeira ocorrência em uma string

Dadas duas strings `needlee` e `haystack`, retorne o índice da primeira ocorrência de `needle` em `haystack`, ou -1 se `needle` não fizer parte de `haystack`.

 
## Exemplo 1:

Entrada: haystack = "sadbutsad", needle = "sad"
Saída: 0

Explicação: "sad" ocorre nos índices 0 e 6.

A primeira ocorrência está no índice 0, então retornamos 0.


## Exemplo 2:

Entrada: haystack = "leetcode", needle = "leeto"
Saída: -1

Explicação: "leeto" não ocorreu em "leetcode", então retornamos -1.

## Restrições:

1 <= haystack.length, needle.length <= 10^4 (10.000)

`haystack` e `needle` consistem apenas em caracteres minúsculos do alfabeto inglês.

## Testes
`haystack` = "morango"
`needlee` = "rango"
saida: 2    esperado: 2 

`haystack` = "algoritmo"
`needlee` = "algarismo"
saida: -1    esperado: -1 

`haystack` = "luisa"
`needlee` = "lui"
saida: 0    esperado: 0 
    
`haystack` = "p"
`needlee` = "pato"
saida: -1    esperado: -1 
