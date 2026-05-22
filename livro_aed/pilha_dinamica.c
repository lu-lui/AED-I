//falta implementar listar todos


#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
}Aluno;

struct elemento{
    Aluno dados;
    struct elemento *prox;
};

typedef struct elemento *Pilha;
typedef struct elemento Elem;

Pilha* cria_Pilha();
void libera_Pilha (Pilha* pi);
int acessa_topo_Pilha(Pilha* pi, Aluno *al);
int insere_Pilha(Pilha* pi, Aluno al);
int remove_Pilha (Pilha* pi);
int tamanho_Pilha (Pilha* pi);
int Pilha_vazia (Pilha* pi);
int Pilha_cheia (Pilha* pi);

int main(){
    Pilha *pi;
    Aluno al;
    int opcao;

    pi = cria_Pilha();

    if (pi == NULL) {
        printf("Erro ao criar pilha!\n");
        return 1;
    }

    do {
        printf("\n----- MENU -----\n");
        printf("1 - Inserir aluno\n");
        printf("2 - Remover topo\n");
        printf("3 - Ver tamanho da pilha\n");
        printf("4 - Ver se pilha esta cheia\n");
        printf("5 - Ver se pilha esta vazia\n");
        printf("6 - Acessar topo\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                printf("Matricula: ");
                scanf("%d", &al.matricula);

                printf("Nome: ");
                scanf(" %[^\n]", al.nome);

                printf("Nota 1: ");
                scanf("%f", &al.n1);

                printf("Nota 2: ");
                scanf("%f", &al.n2);

                printf("Nota 3: ");
                scanf("%f", &al.n3);

                if (insere_Pilha(pi, al))
                    printf("Aluno inserido com sucesso!\n");
                else
                    printf("Erro ao inserir aluno!\n");
                break;

            case 2:
                if (remove_Pilha(pi))
                    printf("Aluno removido do topo!\n");
                else
                    printf("Pilha vazia!\n");
                break;

            case 3:
                printf("Tamanho da pilha: %d\n", tamanho_Pilha(pi));
                break;

            case 4:
                if (Pilha_cheia(pi))
                    printf("Pilha cheia!\n");
                else
                    printf("Pilha nao esta cheia!\n");
                break;

            case 5:
                if (Pilha_vazia(pi))
                    printf("Pilha vazia!\n");
                else
                    printf("Pilha possui elementos!\n");
                break;

            case 6:
                if (acessa_topo_Pilha(pi, &al)) {
                    printf("\n--- TOPO DA PILHA ---\n");
                    printf("Matricula: %d\n", al.matricula);
                    printf("Nome: %s\n", al.nome);
                    printf("N1: %.2f\n", al.n1);
                    printf("N2: %.2f\n", al.n2);
                    printf("N3: %.2f\n", al.n3);
                } else {
                    printf("Pilha vazia!\n");
                }
                break;

            case 0:
                printf("Programa encerrado com sucesso\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    libera_Pilha(pi);

    return 0;
}

Pilha* cria_Pilha(){
    Pilha* pi = (Pilha *)malloc(sizeof(Pilha));
    if (pi != NULL)
        *pi = NULL;

    return pi;    
}

void libera_Pilha (Pilha* pi){
    if (pi != NULL){
        Elem *no;
        while ((*pi) != NULL){
            no = *pi;
            *pi = ((*pi)->prox);
            free(no);
        }
        free(pi);
    }
}

int acessa_topo_Pilha(Pilha* pi, Aluno *al){
    if (pi == NULL)
        return 0;
     if ((*pi) == NULL)
        return 0;

    *al = (*pi)->dados;
    return 1;
}

int insere_Pilha(Pilha* pi, Aluno al){
    if (pi == NULL)
        return 0;
    Elem* no;
    no = (Elem *)malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*pi);
    *pi = no;
    return 1; 
}

int remove_Pilha (Pilha* pi){
    if (pi == NULL)
        return 0;
     if ((*pi) == NULL)
        return 0;

    Elem *no = *pi;
    *pi = no->prox;
    free(no);
    return 1;
}

int tamanho_Pilha (Pilha* pi){
    if(pi == NULL)
        return 0;
    int cont = 0;
    Elem* no = *pi;
    while (no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int Pilha_vazia (Pilha* pi){
    if (pi == NULL)
        return 1;
    if ((*pi) == NULL)
        return 1;
    return 0;
}

int Pilha_cheia (Pilha* pi){
    return 0;
}