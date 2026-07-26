//29. Leia quatro notas, calcule a media aritmética e imprima o resultado. ´

#include<stdio.h>

int main(){
    float n[4];
    int soma = 0;

    for(int i = 0; i < 4; i++){
        printf("Nota %d: ", i+1);
        scanf("%f", &n[i]);

        while (n[i] < 0 || n[i] > 10){
            printf("Nota inválida, tente novamente! \nNota %d: ", i);
            scanf("%f", &n[i]);
        }
        
        soma += n[i];
    }
    
    printf("Média final: %.2f\n", (float) soma/4);
    
    return 0;
}