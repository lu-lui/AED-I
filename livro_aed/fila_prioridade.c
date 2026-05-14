#define MAX 100

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct paciente{
    char nome[30];
    int prio;
}Paciente;

typedef struct FilaPrio_prioridade{
    int qtd;
    Paciente dados[MAX];
}FilaPrio;

FilaPrio* cria_FilaPrio();
void libera_FilaPrio (FilaPrio* fp);
int consulta_FilaPrio(FilaPrio* fp, char  *nome);
int insere_FilaPrio(FilaPrio* fp, char *nome, int prio);
int remove_FilaPrio (FilaPrio* fp);
int tamanho_FilaPrio (FilaPrio* fp);
int FilaPrio_vazia (FilaPrio* fp);
int FilaPrio_cheia (FilaPrio* fp);

int main() {
    FilaPrio *fp;
    int op, prio;
    char nome[30];

    fp = cria_FilaPrio();

    if (fp == NULL) {
        printf("Erro ao criar fila de prioridade!\n");
        return 1;
    }

    do {
        printf("\n----- MENU -----\n");
        printf("1 - Inserir paciente\n");
        printf("2 - Remover paciente\n");
        printf("3 - Consultar proximo paciente\n");
        printf("4 - Ver tamanho da fila\n");
        printf("5 - Ver se fila esta vazia\n");
        printf("6 - Ver se fila esta cheia\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch(op) {

            case 1:
                printf("Nome do paciente: ");
                scanf(" %[^\n]", nome);

                printf("Prioridade: ");
                scanf("%d", &prio);

                if (insere_FilaPrio(fp, nome, prio))
                    printf("Paciente inserido com sucesso!\n");
                else
                    printf("Erro ao inserir paciente!\n");

                break;

            case 2:
                if (remove_FilaPrio(fp))
                    printf("Paciente removido!\n");
                else
                    printf("Fila vazia!\n");

                break;

            case 3:
                if (consulta_FilaPrio(fp, nome))
                    printf("Proximo paciente: %s\n", nome);
                else
                    printf("Fila vazia!\n");

                break;

            case 4:
                printf("Tamanho da fila: %d\n", tamanho_FilaPrio(fp));
                break;

            case 5:
                if (FilaPrio_vazia(fp))
                    printf("Fila vazia!\n");
                else
                    printf("Fila possui pacientes!\n");

                break;

            case 6:
                if (FilaPrio_cheia(fp))
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

    libera_FilaPrio(fp);

    return 0;
}

FilaPrio* cria_FilaPrio(){
    FilaPrio *fp;
    fp = (FilaPrio *)malloc(sizeof(FilaPrio));
    if (fp != NULL)
        fp->qtd = 0;
    return fp;
}

void libera_FilaPrio (FilaPrio* fp){
    free(fp);
}

int consulta_FilaPrio(FilaPrio* fp, char  *nome){
    if (fp == NULL || fp->qtd == 0)
        return 0;
    strcpy(nome, fp->dados[fp->qtd-1].nome);
    return 1;
}

int insere_FilaPrio(FilaPrio* fp, char *nome, int prio){
    if (fp == NULL)
        return 0;
    if(fp->qtd == MAX)
        return 0;
    
        int i = fp->qtd-1;
        while (i >= 0 && fp->dados[i].prio) {
            fp->dados[i+1] = fp->dados[i];
            i--;
        }
        
        strcpy(fp->dados[i+1].nome, nome);
        fp->dados[i+1].prio = prio;
        fp->qtd++;
        return 1;
}

int remove_FilaPrio (FilaPrio* fp){
    if (fp == NULL)
        return 0;
    if (fp->qtd == 0)
        return 0;
    fp->qtd--;
    return 1;
        
}

int tamanho_FilaPrio (FilaPrio* fp){
    if (fp == NULL)
        return -1;
    else
        return fp->qtd;
}

int FilaPrio_vazia (FilaPrio* fp){
    if(fp == NULL)
        return -1;
    return(fp->qtd == 0);
}

int FilaPrio_cheia (FilaPrio* fp){
    if (fp == NULL)
        return -1;
    return (fp->qtd == MAX);
}
