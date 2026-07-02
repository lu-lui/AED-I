//Árvore Binária
//processo de inserção longo

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *esquerda;
    struct no *direita;
}No;

typedef struct {
    No *raiz;
}ArvB;

void inserir(ArvB *arvore, int valor);
void inserirEsq(No *no, int valor);
void inserirDir(No *no, int valor);
void imprimir(No *arvore);

int main(){
    int op, valor;
    ArvB arvore;
    
    arvore.raiz = NULL;
    
    do{
        printf("O - sair \n1 - inserir \n2 - imprimir\n");
        scanf("%d", &op);

        switch (op){
        case 0:
            printf("Programa encerrado\n");
            break;

        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir(&arvore, valor);
            break;

        case 2:
            printf("Impressão da árvore binária: \n");
            imprimir(arvore.raiz);
            printf("\n");
            break;
        
        default:
            printf("Opcao invalida\n");
            break;
        }
    } while ( op != 0);
    

    return 0;
}

void  inserir(ArvB *arvore, int valor){
    //arvore vazia (raiz nula)
    if(arvore->raiz == NULL){
        No *novo = (No *)malloc(sizeof(No));
        novo->valor = valor;      //novo nó recebe o valor
        novo->esquerda = NULL;    //ponteiros não apontam para nada
        novo->direita = NULL;
        arvore->raiz = novo;      //a raiz aponta para o novo valor
    } else{
        if (valor < arvore->raiz->valor)
            inserirEsq(arvore->raiz, valor);
        if (valor > arvore->raiz->valor)
            inserirDir(arvore->raiz, valor);
    } 
}

void  inserirEsq(No *no, int valor){
    if(no->esquerda == NULL) {
        No *novo = (No *)malloc(sizeof(No));
        novo->valor = valor;      //novo nó recebe o valor
        novo->esquerda = NULL;    //ponteiros não apontam para nada
        novo->direita = NULL;
        no->esquerda = novo;
    } else{
        if (valor < no->esquerda->valor)
            inserirEsq(no->esquerda, valor);
        //uma árvore binaria normalmente nao armazena valores repetidos, então não verifica se é igual    
        if (valor > no->esquerda->valor)
            inserirDir(no->esquerda, valor);
    } 
}

void  inserirDir(No *no, int valor){
    if(no->direita == NULL){
        No *novo = (No *)malloc(sizeof(No));
        novo->valor = valor;      //novo nó recebe o valor
        novo->esquerda = NULL;    //ponteiros não apontam para nada
        novo->direita = NULL;
        no->direita = novo;
    } else {
        if (valor > no->direita->valor) //se o valor é maior que um valor que ja está na direita
            inserirDir(no->direita, valor);
        if (valor < no->direita->valor)
            inserirEsq(no->direita, valor);
    }
}

void imprimir(No *raiz){
    if( raiz != NULL){
        imprimir(raiz->esquerda); //imprime esquerda
        printf("%d ", raiz->valor); //imprime raiz
        imprimir(raiz->direita); //imprime direita
    }
}