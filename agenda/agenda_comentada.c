#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Adicionar_Pessoa ( void **pBuffer ); //ponteiro p/ ponteiro pois modifica a memória dentro da função
void Remover_Pessoa ( void **pBuffer );
void Buscar_Pessoa ( void *pBuffer );
void Listar_Todos ( void *pBuffer );
void Sair( void *pBuffer );

int main ( ) {
    void *pBuffer = (void *)malloc( 3 *sizeof(int) );
    //*(int*)pBuffer; //menu;
    *( (int*)pBuffer + 1 ) = 0; //qtd pessoas
    *( (int*)pBuffer + 2 ) = 12; //posição atual

    for ( ; ; ) {
        printf ("----------AGENDA PBUFFER---------- \n");
        printf ("Selecione uma opção: \n");
        printf ("1- Adicionar Pessoa \n");
        printf ("2- Remover Pessoa\n");
        printf ("3- Buscar Pessoa\n");
        printf ("4- Listar todos\n");
        printf ("5- Sair\n");

        scanf ("%d", (int*)pBuffer);

        switch ( *(int*)pBuffer ) {
            case 1: Adicionar_Pessoa (&pBuffer);
                break; 
            case 2: Remover_Pessoa (&pBuffer);
                break;
            case 3: Buscar_Pessoa (pBuffer);
                break;
            case 4: Listar_Todos (pBuffer);
                break;
            case 5: Sair (pBuffer);
                break;
            default:
                break;
        }
    } 
    return 0;
}

/*
====================
Adicionar_Pessoa
 Adiciona uma pessoa na agenda, com nome, idade e email. Atualiza o tamanho do pBuffer dinamicamente
====================
*/
void Adicionar_Pessoa ( void **pBuffer ) {
    char *temp = (char *)malloc( 100 * sizeof(char) );
    int *qtd;
    int *ptr = (int*)*pBuffer + 2; //onde o ponteiro está no buffer

    printf ("Opção selecionada: Adicionar Pessoa \n");
    printf ("Nome: ");
    scanf (" %99[^\n]", temp);
   
    *pBuffer = (char *)realloc( *pBuffer, *ptr + strlen(temp) + 1 );//realloc p guardar nome
    ptr = (int*)*pBuffer + 2; //atribuir de novo porque realloc pode mudar lugar na memória

    strcpy ( (char *)*pBuffer + *ptr, temp );

    *ptr += strlen(temp) + 1; //avança 
    
    free(temp);

    *pBuffer = (int *)realloc( *pBuffer, *ptr + sizeof(int) );//realloc p guardar idade
    ptr = (int*)*pBuffer + 2;
    
    printf ("Idade: ");
    scanf ( "%d", (int *)( (char *)*pBuffer + *ptr) ); //avança 1 byte de cada vez
 
   *ptr += sizeof(int);

    printf ("Email: ");
    temp = (char *)malloc( 100 * sizeof(char) );
    scanf (" %99[^\n]", temp);

    *pBuffer = (char *)realloc( *pBuffer, *ptr + strlen(temp) + 1 );//realloc p guardar email
    ptr = (int*)*pBuffer + 2;

    strcpy( (char *)*pBuffer + *ptr, temp );

    *ptr += strlen(temp) + 1;

    free(temp);

    qtd = (int*)*pBuffer + 1;
    (*qtd)++;
}

/*
====================
Remover_Pessoa
 Remove todos os dados de uma pessoa previamente adicionada na agenda. Atualiza o tamanho do pBuffer dinamicamente, deslocando as próximas pessoas da lista para o lugar da pessoa removida, evitando lacunas no pBuffer
====================
*/
void Remover_Pessoa ( void **pBuffer ) {
    char *temp = (char *)malloc( 100 *sizeof(char) );
    char *ptr = (char *)*pBuffer + ( 3 * sizeof(int) );
    char *ptr_fim_pessoa = (char *)*pBuffer + ( 3 * sizeof(int) );
    char *ptr_fim_agenda = (char*)*pBuffer + *( (int*)*pBuffer + 2 );
    int *qtd = (int *)*pBuffer + 1;
    void *flag = NULL;

    printf ("Opção selecionada: Remover Pessoa \n");
    printf ("Nome: ");
    scanf (" %99[^\n]", temp);

    while ( ptr < ptr_fim_agenda ) {
        if ( strcmp( ptr, temp ) == 0 ) {
            flag = ptr;

            ptr_fim_pessoa += strlen(ptr_fim_pessoa) + 1;
            ptr_fim_pessoa += sizeof(int);
            ptr_fim_pessoa += strlen(ptr_fim_pessoa) + 1;

            memmove ( ptr, ptr_fim_pessoa, ptr_fim_agenda - ptr_fim_pessoa );
            *pBuffer = (void *)realloc( *pBuffer, *( (int*)*pBuffer + 2 ) - ( ptr_fim_pessoa - ptr ) );
            *( (int*)*pBuffer + 2 ) -= ( ptr_fim_pessoa - ptr );  
            ptr_fim_agenda = (char*)*pBuffer + *( (int*)*pBuffer + 2 ); 

            qtd = (int*)*pBuffer + 1;
            (*qtd)--;

            printf ("Contato excluído com sucesso: \n");

            break;
        } else {
            ptr += strlen(ptr) + 1;
            ptr += sizeof(int);
            ptr += strlen(ptr) + 1;

            ptr_fim_pessoa += strlen(ptr_fim_pessoa) + 1;
            ptr_fim_pessoa += sizeof(int);
            ptr_fim_pessoa += strlen(ptr_fim_pessoa) + 1;
        }    
    }    
    
    if ( flag == NULL ) {
        printf ("O contato não está na agenda \n");
    }
        
    free(temp);
}

/*
====================
Buscar_Pessoa
 Percorre toda a extensão de dados do pBuffer, pesquisando o nome digitado pelo usuário, se encontra, mostra todos os dados na tela(nome, idade e email), senão, informa que não encontrou
====================
*/
void Buscar_Pessoa ( void *pBuffer ) {
    char *temp = (char *)malloc( 100 *sizeof(char) );
    char *ptr = (char *)pBuffer + ( 3 * sizeof(int) );
    char *ptr_fim_agenda = (char*)pBuffer + *( (int*)pBuffer + 2 );
    void *flag = NULL;

    printf ("Opção selecionada: Buscar Pessoa \n");
    printf ("Nome: ");
    scanf (" %99[^\n]", temp);

    while (ptr < ptr_fim_agenda) {
        
        if ( strcmp( ptr, temp ) == 0 ) {

            flag = ptr;

            printf ("Contato encontrado: \n");
            printf ("Nome: %s \n", ptr);
            ptr += strlen(ptr) + 1;
        
            printf ("Idade: %d \n", *(int *)ptr);
            ptr += sizeof(int);

            printf ("Email: %s \n\n", ptr);
            ptr += strlen(ptr) + 1;

            break;
        } else {
            ptr += strlen(ptr) + 1;
            ptr += sizeof(int);
            ptr += strlen(ptr) + 1;
        }    
    }   
    
    if ( flag == NULL ) {
        printf ("O contato não está na agenda \n");
    }
        
    free(temp);
}

/*
====================
Listar_Todos
 Percorre toda a agenda e exibe os dados de todos os contatos salvos
====================
*/
void Listar_Todos ( void *pBuffer ) {
    int *qtd = (int*)pBuffer + 1;
    char *ptr = (char*)pBuffer + ( 3 * sizeof(int) );
    char *ptr_fim_agenda = (char*)pBuffer + *( (int*)pBuffer + 2 );

    printf ("Opção selecionada: Listar Todos \n");

    if ( *qtd == 0 ) {
        printf("Nenhuma pessoa cadastrada\n");
        
        return;
    }

    printf ("Lista de contatos: \n");
    while (ptr < ptr_fim_agenda) {
        printf ("Nome: %s \n", ptr);
        ptr += strlen(ptr) + 1;
    
        printf ("Idade: %d \n", *(int *)ptr);
        ptr += sizeof(int);

        printf ("Email: %s \n\n", ptr);
        ptr += strlen(ptr) + 1;
    }
}

/*
====================
Sair
 Libera toda a memória alocada para o pBuffer e encerra o programa.
====================
*/
void Sair ( void *pBuffer ) {
    free(pBuffer);
    printf ("Agenda encerrada, os contatos não foram salvos. \n");
    exit(0);
}