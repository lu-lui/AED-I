//árvore binária
//processo de inserção curto
//descobrindo o tamanho
//busca de elemento

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *esquerda;
    struct no *direita;
}No;

No* inserir(No *raiz, int valor); //agora retorna um nó
void imprimir(No *arvore);
int tamanho(No *raiz);
int buscar(No *raiz, int chave);

int main(){
    int op, valor;
    No *raiz = NULL;
    
    do{
        printf("O - sair \n1 - inserir \n2 - imprimir \n3 - Buscar\n");
        scanf("%d", &op);

        switch (op){
        case 0:
            printf("Programa encerrado\n");
            break;

        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
            break;

        case 2:
            printf("Impressão da árvore binária: \n");
            imprimir(raiz);
            printf("\nTamanho da Árvore: %d\n", tamanho(raiz));
            break;

        case 3:
            printf("Digite um valor para busca: ");
            scanf("%d", &valor);
            printf("\nResultado da busca: %d\n", buscar(raiz, valor));
            break;
        
        default:
            printf("Opcao invalida\n");
            break;
        }
    } while ( op != 0);
    

    return 0;
}

No* inserir(No *raiz, int valor){
    //arvore vazia (raiz nula)
    if(raiz == NULL){ //árvore vazia
        No *novo = (No *)malloc(sizeof(No));
        novo->valor = valor;      //novo nó recebe o valor
        novo->esquerda = NULL;    //ponteiros não apontam para nada
        novo->direita = NULL;
        return novo;
    } else { //raiz não é nula
        if (valor < raiz->valor)
            raiz->esquerda = inserir(raiz->esquerda, valor); //chamada recursiva
        if (valor > raiz->valor)
            raiz->direita = inserir(raiz->direita, valor);
        return raiz;
    } 
}

void imprimir(No *raiz){
    if( raiz != NULL){
        imprimir(raiz->esquerda); //imprime esquerda
        printf("%d ", raiz->valor); //imprime raiz
        imprimir(raiz->direita); //imprime direita
    }
}

//chamada recursiva para descobrir o tamanho
int tamanho(No *raiz){
    if (raiz == NULL)
        return 0;
    else
        return 1 + tamanho(raiz->esquerda) + tamanho(raiz->direita);
    // 1 == nó raiz + soma dos nós da esquerda/direita
}

int buscar(No *raiz, int chave){
    if (raiz == NULL){
        return -1; //retornar número que nunca fará parte da árvore binária (ex: árvore de valores positivos)
    } else {
        if (raiz->valor == chave)
            return raiz->valor; // ou return chave;
        else {
            if (chave < raiz->valor) //aqui se elimina metade dads possibilidades, por isso a complexidade é O(Log n)
                return buscar(raiz->esquerda, chave);  //chamada recursiva
            else
                return buscar(raiz->direita, chave);  //chamada recursiva
        }
        
        }
        
}
    
