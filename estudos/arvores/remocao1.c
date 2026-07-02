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
No* buscarNO(No *raiz, int chave); //retorna
No* remover(No *raiz,int chave);
int altura(No *raiz);
int alturaSubArvore(No* raiz, int chave);

int main(){
    int op, valor;
    No *raiz = NULL;
    
    do{
        printf("O - sair \n1 - inserir \n2 - imprimir \n3 - Buscar \n4- Remover \n5 - Altura \n6 - Altura subárvore\n");
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

        case 5:
            printf("Altura da arvore: %d\n", altura(raiz));
            break;

        case 6:
            printf("Digite um valor para cálculo de altura:\n ");
            scanf("%d", &valor);
            printf("Altura da arvore: %d\n", alturaSubArvore(raiz, valor));
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
        //encontrou o valor na raiz (remoção para nós folha)
        if(raiz->valor == chave){ 
            if (raiz->esquerda == NULL && raiz->direita == NULL){
                free(raiz);
                return NULL;
            } else {
                //remover nós que possuem 1 filho
                //se um deles for nulo cai aqui, já foi testado se os dois são simultaneamente
                if(raiz->esquerda == NULL || raiz->direita == NULL){ 
                    No *temp; 
                    if (raiz->esquerda != NULL)
                        temp = raiz->esquerda;
                    else
                        temp = raiz->direita;

                    free(raiz);
                    return temp;
                } else {
                    //vai para a esquerda e pega o nó mais a direita
                    No* temp = raiz->esquerda;
                    while (temp->direita != NULL)
                        temp = temp->direita; //avança o ponteiro mais a direita possível
                    raiz->valor = temp->valor;
                    temp->valor = chave; //quebre momentaneamente a regra de arvore binária (mesmo valor que tava na raiz->valor)
                    raiz->esquerda = remover(raiz->esquerda, chave);
                    return raiz;
                }
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

//para remover um nó de uma subarvore com filhos dos dois lados, ou vou para a esquerda e pego o filho mais a direita, ouvou para a direita e pego o filho mais a esquerda
//assim teremos o nó que mais se aproxima do valor do nó excluído

No* buscarNO(No *raiz, int chave){ //descobrir a altura de um nó
    if (raiz == NULL){
        return NULL; 
    } else {
        if (raiz->valor == chave)
            return raiz; 
        else {
            if (chave < raiz->valor) 
                return buscarNO(raiz->esquerda, chave);  
            else
                return buscarNO(raiz->direita, chave); 
        }
    }     
}

int altura(No *raiz){
    //se raiz for nula ou folha
    if (raiz == NULL)
        return -1;

    int esq = altura(raiz->esquerda);
    int dir = altura(raiz->direita);
    
    //retorna o maior
    if(esq > dir)
        return esq + 1;
    else
        return dir + 1;
}

int alturaSubArvore(No* raiz, int chave){
    No *no = buscarNO(raiz, chave);
    if (no) //diferente de NULL
        return altura(no);
    else
        return -1; 
}