## Luísa Passos Neutzling
## Turma: M1

### 503. Próximo Elemento Superior II

Dado um array circular de inteiros `nums`(ou seja, o próximo elemento de nums[nums.length - 1]é nums[0]), retorne o **próximo número maior** para cada elemento em `nums`.

O **próximo número maior** que um número `x` é o primeiro número maior que ele encontra na ordem de busca do array, o que significa que você pode fazer uma busca circular para encontrar o próximo número maior. Se ele não existir, retorne `-1` para esse número.

 
## Exemplo 1:

Entrada: nums = [1,2,1]
 Saída: [2,-1,2]

**Explicação:** O próximo número maior que o primeiro 1 é 2. O número 2 não pode encontrar um número maior seguinte. O próximo número maior que o segundo 1 precisa de uma busca circular, que também é 2.

## Exemplo 2:

Entrada: nums = [1,2,3,4,3]
 Saída: [2,3,4,-1,4]


## Testes:
Entrada: nums = [6,5,3,2]
 Saída: [-1,6,6,6]

Entrada: nums = [7,8,9]
 Saída: [8,9,-1]

 Entrada: nums = [-5,-1,0,1,5,10]
 Saída: [-1,0,1,5,10,-1]