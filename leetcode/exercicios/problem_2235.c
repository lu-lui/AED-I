//Given two integers num1 and num2, return the sum of the two integers.

#include <stdio.h>

int sum(int num1, int num2) {
    return num1 + num2;
}

//teste da implemetação da função, não aparece no LeetCode
int main(){
    int num1, num2, s;

    printf("Number 1: ");
    scanf("%d", &num1);

    printf("Number 2: ");
    scanf("%d", &num2);

    s = sum(num1, num2);

    printf("Sum: %d\n", s);
    return 0;
}