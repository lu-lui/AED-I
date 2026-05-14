/*Faça um programa que arnazene a informação de várias pessoas numa pilha. O programa deve possuir um menu:
0: Insere pessoa
1: Deleta pesosa do topo
2: Deleta pessoa por nome
3: Limpa a pilha 
4: Lista as pessoas
5: Sair do programa*/

#define MAX 10 //fazer dinâmica depois

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    char nome[30];
    int idade;
}Pessoa;

typedef struct{
    Pessoa pessoas[MAX];
    int topo;
    int base;
    int limite;
}Pilha;


bool FULL(Pilha *pilha);
bool EMPTY(Pilha *pilha);
void RESET(Pilha *pilha);
//void CLEAR(Pilha *pilha);
//void EXIT(Pilha *Pilha);
//void LIST(Pilha *pilha, Pessoa *pessoas);
bool PUSH(Pilha *pilha);
void POP(Pilha *pilha);
//void POP_NAME(Pilha *pilha, Pessoa *pessoas);

int main(){
    Pilha pilha;
    int escolha;

    RESET(&pilha);

    for ( ; ; ) {
        printf("-----MENU-----\n");
        printf("O que você gostaria de fazer?\n");
        printf("0- Inserir Pessoa\n");
        printf("1- Deletar Pessoa do Topo\n");
        printf("2- Deletar Pessoa por Nome\n");
        printf("3- Limpar a Pilha\n");
        printf("4- Listar Pessoas\n");
        printf("5- Sair");

        scanf("%d", &escolha);

        switch (escolha){
        case 0:
            PUSH(&pilha);
            break;

        // case 1:
        //     POP(&pilha);
        //     break;

        // case 2:
        //     POP_NAME(pilha, pessoas);
        //     break;

        // case 3:
        //     CLEAR(pilha);
        //     break;

        // case 4:
        //     LIST(pilha, pessoas);
        //     break;

        // case 5:
        //     EXIT(pilha);
        //     break;
        
        default:
            break;
        }
    }

    return 0;
}

bool FULL(Pilha *pilha){
    return pilha->topo == MAX;
}

bool EMPTY(Pilha *pilha){
    return pilha->topo == 0;
}

void RESET(Pilha *pilha){
    pilha->base = 0;
    pilha->topo = 0;
    pilha->limite = MAX;
}

// void CLEAR(Pilha *pilha){
    
    
// }

bool PUSH(Pilha *pilha){
    if (!FULL(pilha)) {
        printf("Nome: ");
        scanf(" %29[^\n]", pilha->pessoas[pilha->topo].nome);

        printf("Idade: ");
        scanf("%d", &pilha->pessoas[pilha->topo].idade);

        pilha->topo++;

        return true;
    } else {
        return false;
    }
}

// void POP(Pilha *pilha){

// }