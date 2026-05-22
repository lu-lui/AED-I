#include <stdio.h>
#include <stdlib.h>

typedef struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
}Aluno;

typedef struct elemento{ 
    Aluno dados;
    struct elemento *prox;
} Elem;

typedef struct fila{
    Elem *inicio;
    Elem *final;
    int qtd;
}Fila;

Fila* cria_Fila();
void libera_Fila (Fila* fi);
int consulta_Fila(Fila* fi, Aluno *al);
int insere_Fila(Fila* fi, Aluno al);
int remove_Fila (Fila* fi);
int tamanho_Fila (Fila* fi);
int Fila_vazia (Fila* fi);
int Fila_cheia (Fila* fi);

int main() {
    Fila *fi;
    Aluno al;
    int op;

    fi = cria_Fila();

    if (fi == NULL) {
        printf("Erro ao criar fila!\n");
        return 1;
    }

    do {
        printf("\n----- MENU -----\n");
        printf("1 - Inserir aluno\n");
        printf("2 - Remover aluno\n");
        printf("3 - Consultar primeiro da fila\n");
        printf("4 - Ver tamanho da fila\n");
        printf("5 - Ver se fila esta vazia\n");
        printf("6 - Ver se fila esta cheia\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch(op) {

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

                if (insere_Fila(fi, al))
                    printf("Aluno inserido com sucesso!\n");
                else
                    printf("Erro ao inserir aluno!\n");

                break;

            case 2:
                if (remove_Fila(fi))
                    printf("Aluno removido da fila!\n");
                else
                    printf("Fila vazia!\n");

                break;

            case 3:
                if (consulta_Fila(fi, &al)) {
                    printf("\n--- PRIMEIRO DA FILA ---\n");
                    printf("Matricula: %d\n", al.matricula);
                    printf("Nome: %s\n", al.nome);
                    printf("N1: %.2f\n", al.n1);
                    printf("N2: %.2f\n", al.n2);
                    printf("N3: %.2f\n", al.n3);
                } else {
                    printf("Fila vazia!\n");
                }

                break;

            case 4:
                printf("Tamanho da fila: %d\n", tamanho_Fila(fi));
                break;

            case 5:
                if (Fila_vazia(fi))
                    printf("Fila vazia!\n");
                else
                    printf("Fila possui elementos!\n");

                break;

            case 6:
                if (Fila_cheia(fi))
                    printf("Fila cheia!\n");
                else
                    printf("Fila nao esta cheia!\n");

                break;

            case 0:
                printf("Encerrando programa...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (op != 0);

    libera_Fila(fi);

    return 0;
}

Fila* cria_Fila(){
    Fila *fi = (Fila *)malloc(sizeof(Fila));
    if (fi != NULL){
        fi->final = NULL;
        fi->inicio = NULL;
        fi->qtd = 0;
    }
    return fi;
}

void libera_Fila (Fila* fi){
    if (fi != NULL){
        Elem *no;
        while (fi->inicio != NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

int consulta_Fila(Fila* fi, Aluno *al){
    if (fi == NULL)
        return 0;
    if(fi->inicio == NULL)
        return 0;
    *al = fi->inicio->dados;
    return 1;

}

int insere_Fila(Fila* fi, Aluno al){
    if (fi == NULL)
        return 0;
    Elem *no = (Elem *)malloc(sizeof(Elem));
    if (no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if (fi->final == NULL){
        fi->inicio = no; //fila vazia
    } else {
        fi->final->prox = no;
    }
        
    
        fi->final = no;
        fi->qtd++;
        return 1;
}

int remove_Fila (Fila* fi){
    if (fi == NULL)
        return 0;
    if(fi->inicio == NULL) //fila vazia
        return 0;
    Elem *no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    free(no);
    if(fi->inicio == NULL) //fila ficou fazia
        fi->final = NULL;
    fi->qtd--;
    return 1;
}

int tamanho_Fila (Fila* fi){
    if (fi == NULL)
        return 0;
    return fi->qtd;
}

int Fila_vazia (Fila* fi){
    if (fi == NULL)
        return -1;
    if (fi->inicio == NULL)
        return 1;
    return 0;
}

int Fila_cheia (Fila* fi){
    return 0;
}
