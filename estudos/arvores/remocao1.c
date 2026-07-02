//árvore binária
//remoção de um elemento
//remoção 1: remover o nó folha (não tem nenhum filho)

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *esquerda;
    struct no *direita;
}No;

No* inserir(No *raiz, int valor); 
void imprimir(No *arvore);
int tamanho(No *raiz);
int buscar(No *raiz, int chave);
No* remover(No *raiz,int chave);

int main(){
    int op, valor;
    No *raiz = NULL;
    
    do{
        printf("O - sair \n1 - inserir \n2 - imprimir \n3 - Buscar \n4- Remover\n");
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

        case 4:
            printf("Digite um valor para remoção: ");
            scanf("%d", &valor);
            raiz = remover(raiz, valor);
            break;
        
        default:
            printf("Opcao invalida\n");
            break;
        }
    } while ( op != 0);
    
    return 0;
}

No* inserir(No *raiz, int valor){
    if(raiz == NULL){ 
        No *novo = (No *)malloc(sizeof(No));
        novo->valor = valor;      
        novo->esquerda = NULL;    
        novo->direita = NULL;
        return novo;
    } else { //raiz não é nula
        if (valor < raiz->valor)
            raiz->esquerda = inserir(raiz->esquerda, valor); 
        if (valor > raiz->valor)
            raiz->direita = inserir(raiz->direita, valor);
        return raiz;
    } 
}

void imprimir(No *raiz){
    if( raiz != NULL){
        imprimir(raiz->esquerda); 
        printf("%d ", raiz->valor); 
        imprimir(raiz->direita); 
    }
}

int tamanho(No *raiz){
    if (raiz == NULL)
        return 0;
    else
        return 1 + tamanho(raiz->esquerda) + tamanho(raiz->direita);
}

int buscar(No *raiz, int chave){
    if (raiz == NULL){
        return -1; 
    } else {
        if (raiz->valor == chave)
            return raiz->valor; 
        else {
            if (chave < raiz->valor) 
                return buscar(raiz->esquerda, chave);  
            else
                return buscar(raiz->direita, chave); 
        }
    }     
}

No* remover(No *raiz,int chave){
    if (raiz == NULL){ //árvore vazia
        printf("Valor não encontrado\n");
        return NULL; //esse null
    } else {
        if(raiz->valor == chave){ //encontrou o valor na raiz (remoção para nós folha)
            if (raiz->esquerda == NULL && raiz->direita == NULL){
                free(raiz);
                return NULL;
            }
            
        } else {
            if (chave < raiz->valor) //não encontrou na raiz, se é menor, vai para a esquerda
                raiz->esquerda = remover(raiz->esquerda, chave); //raiz->esquerda recebe o retorno NULL de remover
            else
                raiz->direita = remover(raiz->direita, chave); 
                //precisa retornar o endereço para não perder os ponteiros que ligam a arvore
            return raiz;
        }
    }
}