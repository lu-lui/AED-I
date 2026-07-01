//Árvore Binária

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

void  inserir(ArvB *arvore, int valor);
void  inserirEsq(No *no, int valor);
void  inserirDir(No *no, int valor);

int main(){

    
    

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
    } else if (valor < arvore->raiz->valor){
        inserirEsq(arvore->raiz, valor);
    } else {
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
    } else if (valor < no->esquerda->valor)
            inserirEsq(no->esquerda, valor);
         else 
            inserirDir(no->esquerda, valor);
}

void  inserirDir(No *no, int valor){
    if(no->)
}