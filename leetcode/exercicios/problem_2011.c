/*There is a programming language with only four operations and one variable X:
++X and X++ increments the value of the variable X by 1.
--X and X-- decrements the value of the variable X by 1.
Initially, the value of X is 0.
Given an array of strings operations containing a list of operations, return the final value of X after performing all the operations.*/

#include <stdio.h>
#include <stdlib.h>

int finalValueAfterOperations(char **operations, int operationsSize);

int main() {
    char *operations[] = {"--X", "X++", "X++"};
    int operationsSize = sizeof(operations) / sizeof(operations[0]);

    int result = finalValueAfterOperations(operations, operationsSize);

    printf("Resultado: %d\n", result);

    return 0;
}

int finalValueAfterOperations(char **operations, int operationsSize) {
    int x = 0;

    for (int i = 0; i < operationsSize; i++) {
        if (operations[i][1] == '+')
            x++;
        else
            x--;
    }

    return x;
}