/*You are given the root of a binary search tree (BST) and an integer val.
Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.*/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;     
    struct TreeNode *right;
};

struct TreeNode* searchBST(struct TreeNode* root, int val);

void Inicializa(struct TreeNode **root);
void Libera(struct TreeNode **root);
void Lista(struct TreeNode *root);
void Insere(struct TreeNode **root, int val);

int main(){
    struct TreeNode *root;
    Inicializa(&root);

    int qtd, x, val;
    printf("Digite quantos nos deseja inserir? ");
    scanf("%d", &qtd);

    for(int i = 0; i < qtd; i++){
        printf("Nó %d: ", i + 1);
        scanf("%d", &x);
        Insere(&root, x);
    }

    printf("Digite o valor a buscar: ");
    scanf("%d", &val);

    struct TreeNode *root2;
    root2 = searchBST(root, val);
    Lista(root2);

    Libera(&root);
    return 0;
}

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    struct TreeNode *root2;

    if(root == NULL)
        return NULL;
    
    if(val == root->val){
        root2 = root;
        return root2;
    }

    if(val < root->val)
        root2 = searchBST(root->left, val);
    
    if(val > root->val)
        root2 = searchBST(root->right, val);
    
    return root2;
}

void Inicializa(struct TreeNode **root){
    *root = NULL;
}

void Libera(struct TreeNode **root){
    if(*root == NULL)
        return;
    
    Libera(&(*root)->left);
    Libera(&(*root)->right);
    free(*root);
    *root = NULL;
}

void Lista(struct TreeNode *root){
    if(root == NULL)
        return;
    
    printf("%d ", root->val);
    Lista(root->left);
    Lista(root->right);
}

void Insere(struct TreeNode **root, int val){
    struct TreeNode *p;
    p = *root;

    if(*root == NULL){
        *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        (*root)->val = val;
        (*root)->left = NULL;
        (*root)->right = NULL;
        return;
    } else if(val < (*root)->val){
        Insere(&(*root)->left, val);
        return;
    } else if(val > (*root)->val){
        Insere(&(*root)->right, val);
        return;
    } else {
        return;
    }
}