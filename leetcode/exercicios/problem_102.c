// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

//Input: root = [3,9,20,null,null,15,7]
//Output: [[3],[9,20],[15,7]

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

int altura(struct TreeNode* root);
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes);
struct TreeNode* insere(struct TreeNode* root, int valor);
void imprimir(struct TreeNode *root);
int contarNivel(struct TreeNode* root, int nivel_atual, int nivel);

int main(){
     struct TreeNode *root = NULL;
     int** level; 
     int returnSize; //quantidade de linhas
     int *returnColumnSizes; //tamaho de cada linha

     root = insere(root, 1); //root recebe o retorno da função
     root = insere(root, 3);
     root = insere(root, 4);
     root = insere(root, 5);

     level = levelOrder(root, &returnSize, &returnColumnSizes); //passar o endereço do retorno para alterar no main

     imprimir(root);

     for (int i = 0; i < returnSize; i++){
          for (int j = 0; j < returnColumnSizes[i]; j++){
               printf("%d ", level[i][j]);
          }
          printf("\n");
     }
     return 0;
}

//columnsize é o tamanho de cada linha individualmente
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
     int niveis = altura(root) + 1;
     int x = 0;
     *returnSize = niveis; //conteudo do ponteiro recebe tamanho da arvore
     *returnColumnSizes = (int *)malloc(niveis * sizeof(int)); //quantidade de niveis
     int **level = (int **)malloc(niveis * sizeof(int *));

     for (int i = 0; i < niveis; i++){
          int qtd = contarNivel(root, 0, i);
          (*returnColumnSizes)[i] = qtd;         // guarda o tamanho desse nível
          level[i] = (int *)malloc(qtd * sizeof(int)); // aloca o matriz desse nível
     }
     return level;
}

struct TreeNode* insere(struct TreeNode* root, int valor){
     if (root == NULL){
          struct TreeNode* novo = (struct TreeNode *)malloc(sizeof(struct TreeNode));
          novo->val = valor;
          novo->left = NULL;
          novo->right = NULL;
          return novo;
     } else {
          if(valor < root->val)
               root->left = insere(root->left, valor); //precisa receber o retorno
          if(valor > root->val)
               root->right = insere(root->right, valor);
          return root;
     }
}

void imprimir(struct TreeNode *root){
    if( root != NULL){
        imprimir(root->left); //imprime esquerda
        printf("%d ", root->val); //imprime raiz
        imprimir(root->right); //imprime direita
    }
}

//pegar o tamanho da raiz, imprimir o tamanho dos nós 
// fazer um for talvez para ir imprimindo coisas de tamanho por tamanho

int altura(struct TreeNode* root){
     if (root == NULL)
          return -1;
     
     int left = altura(root->left);
     int right = altura(root->right);
     
     if (left > right)
          return left + 1;
     else
          return right + 1; 
}

int contarNivel(struct TreeNode* root, int nivel_atual, int nivel){
    if (root == NULL){
        return 0;
    } else {
        if (nivel_atual == nivel){
            return 1;
        } else {
            int left = contarNivel(root->left, nivel_atual + 1, nivel);
            int right = contarNivel(root->right, nivel_atual + 1, nivel);
            return left + right;
        }
    }
}