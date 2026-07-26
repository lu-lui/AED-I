//28. Faça a leitura de tres valores e apresente como resultado a soma dos quadrados dos tres valores lidos. 

#include<stdio.h>

int main(){
    int x[3], soma = 0;

    for(int i = 0; i < 3; i++){
        printf("Valor %d: ", i+1);
        scanf("%d", &x[i]);
        soma += x[i] * x[i];
    }
    
    printf("Soma dos quadrados de %d, %d e %d = %d", x[0], x[1], x[2], soma);
    
    return 0;
}