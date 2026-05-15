//listar todos

#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

typedef struct aluno{
    int matricula;
    char nome[30];
    float n1, n2, n3;
}Aluno;

struct elemento{
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento *Lista;
typedef struct elemento Elem;

Lista* cria_Lista();
void libera_Lista (Lista* li);
int insere_Lista_final(Lista* li, Aluno al);
int insere_Lista_inicio(Lista* li, Aluno al);
int insere_Lista_ordenada(Lista* li, Aluno al);
int remove_Lista_final(Lista* li);
int remove_Lista_inicio(Lista* li);
int remove_Lista(Lista* li, int matricula);
int tamanho_Lista (Lista* li);
int Lista_vazia (Lista* li);
int Lista_cheia (Lista* li);
int busca_lista_matricula(Lista* li, int matricula, Aluno *al);
int busca_lista_posicao(Lista* li, int posicao, Aluno *al);

int main() {
    Lista *li;
    Aluno al;
    int op, matricula, posicao;

    li = cria_Lista();

    if (li == NULL) {
        printf("Erro ao criar lista!\n");
        return 1;
    }

    do {
        printf("\n----- MENU -----\n");
        printf("1 - Inserir no inicio\n");
        printf("2 - Inserir no final\n");
        printf("3 - Inserir ordenado\n");
        printf("4 - Remover do inicio\n");
        printf("5 - Remover do final\n");
        printf("6 - Remover por matricula\n");
        printf("7 - Buscar por matricula\n");
        printf("8 - Buscar por posicao\n");
        printf("9 - Ver tamanho da lista\n");
        printf("10 - Ver se lista esta vazia\n");
        printf("11 - Ver se lista esta cheia\n");
        printf("0 - Sair\n");

        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {

            case 1:
            case 2:
            case 3:
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

                if (op == 1) {
                    if (insere_Lista_inicio(li, al))
                        printf("Aluno inserido no inicio!\n");
                    else
                        printf("Erro ao inserir!\n");
                }

                else if (op == 2) {
                    if (insere_Lista_final(li, al))
                        printf("Aluno inserido no final!\n");
                    else
                        printf("Erro ao inserir!\n");
                }

                else {
                    if (insere_Lista_ordenada(li, al))
                        printf("Aluno inserido ordenadamente!\n");
                    else
                        printf("Erro ao inserir!\n");
                }

                break;

            case 4:
                if (remove_Lista_inicio(li))
                    printf("Primeiro aluno removido!\n");
                else
                    printf("Lista vazia!\n");

                break;

            case 5:
                if (remove_Lista_final(li))
                    printf("Ultimo aluno removido!\n");
                else
                    printf("Lista vazia!\n");

                break;

            case 6:
                printf("Digite a matricula: ");
                scanf("%d", &matricula);

                if (remove_Lista(li, matricula))
                    printf("Aluno removido!\n");
                else
                    printf("Matricula nao encontrada!\n");

                break;

            case 7:
                printf("Digite a matricula: ");
                scanf("%d", &matricula);

                if (busca_lista_matricula(li, matricula, &al)) {
                    printf("\n--- ALUNO ENCONTRADO ---\n");
                    printf("Matricula: %d\n", al.matricula);
                    printf("Nome: %s\n", al.nome);
                    printf("N1: %.2f\n", al.n1);
                    printf("N2: %.2f\n", al.n2);
                    printf("N3: %.2f\n", al.n3);
                } else {
                    printf("Aluno nao encontrado!\n");
                }

                break;

            case 8:
                printf("Digite a posicao: ");
                scanf("%d", &posicao);

                if (busca_lista_posicao(li, posicao, &al)) {
                    printf("\n--- ALUNO ENCONTRADO ---\n");
                    printf("Matricula: %d\n", al.matricula);
                    printf("Nome: %s\n", al.nome);
                    printf("N1: %.2f\n", al.n1);
                    printf("N2: %.2f\n", al.n2);
                    printf("N3: %.2f\n", al.n3);
                } else {
                    printf("Posicao invalida!\n");
                }

                break;

            case 9:
                printf("Tamanho da lista: %d\n", tamanho_Lista(li));
                break;

            case 10:
                if (Lista_vazia(li))
                    printf("Lista vazia!\n");
                else
                    printf("Lista possui elementos!\n");

                break;

            case 11:
                if (Lista_cheia(li))
                    printf("Lista cheia!\n");
                else
                    printf("Lista nao esta cheia!\n");

                break;

            case 0:
                printf("Encerrando programa...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (op != 0);

    libera_Lista(li);

    return 0;
}

Lista* cria_Lista(){
    Lista *li = (Lista *)malloc(sizeof(Lista));
    if (li != NULL)
        *li = NULL;
    return li;
}

void libera_Lista (Lista* li){
    if (li != NULL){
        Elem *no;
        while ((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int insere_Lista_final(Lista* li, Aluno al){
     if(li == NULL)
        return 0;
    Elem *no;
    no = (Elem *)malloc(sizeof(Elem));
    if (no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if ((*li) == NULL) //lista vazia, insere no inicio
        *li = no;
    else {
        Elem *aux;
        aux = *li;
        while (aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    } 
    return 1;
}

int insere_Lista_inicio(Lista* li, Aluno al){
    if(li == NULL)
        return 0;
    Elem *no;
    no = (Elem *)malloc(sizeof(Elem));
    if (no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*li);
    *li = no;
    return 1;
}

int insere_Lista_ordenada(Lista* li, Aluno al){
    if (li == NULL)
        return 0;
    Elem *no;
    no = (Elem *)malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    if((*li) == NULL){//lista vazia, insere no inicio
        no->prox = NULL;
        *li = no;
        return 1;
    } else {
        Elem *ant, *atual = *li;
        while (atual != NULL && atual->dados.matricula < al.matricula){
            ant = atual;
            atual = atual->prox;
        }
        if (atual == *li) {//insere inicio
            no->prox = (*li);
            *li = no;
        } else {
            no->prox =atual;
            ant->prox = no;
        }
        return 1;
    }
}

int remove_Lista_final(Lista* li){
     if (li == NULL)
     return 0;
    if((*li) == NULL)
        return 0;

    Elem *ant, *no = *li;
    while (no->prox != NULL){
        ant = no;
        no = no->prox;
    }
    
    if(no == (*li)) //remover o primeiro
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

int remove_Lista_inicio(Lista* li){
    if (li == NULL)
     return 0;
    if((*li) == NULL)
        return 0;

    Elem *no = *li;
    *li = no->prox;
    free(no);
    return 1;
}

int remove_Lista(Lista* li, int matricula){ //elemento especifico
    if (li == NULL)
     return 0;
    if((*li) == NULL)
        return 0;
    Elem *ant, *no = *li;
    while (no != NULL && no->dados.matricula != matricula) {
        ant = no;
        no = no->prox;
    }
    if(no == NULL) //não encontrado
        return 0;
    if(no == *li) // remover o primero?
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

int tamanho_Lista (Lista* li){
    if (li == NULL)
        return 0;
    int cont  = 0;
    Elem *no = *li;
    while (no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int Lista_vazia (Lista* li){
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}

int Lista_cheia (Lista* li){
    return 0;
}

int busca_lista_matricula(Lista* li, int matricula, Aluno *al){
    if(li == NULL) 
        return 0;
    Elem *no = *li;
    while (no != NULL && no->dados.matricula != matricula){
        no = no->prox;
    }
    if (no == NULL)
        return 0;
    else {
        *al = no->dados;
        return 1;
    }
}

int busca_lista_posicao(Lista* li, int posicao, Aluno *al){
    if(li == NULL) //posicao <= 0
        return 0;
    Elem *no = *li;
    int i = 1;
    while (no != NULL && i < posicao){
        no = no->prox;
        i++;
    }
    if (no == NULL)
        return 0;
    else {
        *al = no->dados;
        return 1;
    }
}