//Given the roots of two binary trees p and q, write a function to check if they are the same or not.
//Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };

bool isSameTree(struct TreeNode* p, struct TreeNode* q);
bool verifica(struct TreeNode* p, struct TreeNode* q);
struct TreeNode* insere(int valor);

int main (){
    struct TreeNode* p, *q;
    
    p = insere(1);
    p->left = insere(2);
    p->right = insere(3);

    q = insere(1);
    q->left = insere(4);
    q->right = insere(3);

    if (isSameTree(p, q))
        printf("As arvores sao iguais.\n");
    else
        printf("As arvores sao diferentes.\n");

    return 0;
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    return verifica(p, q);
}

struct TreeNode* insere(int valor) {
    struct TreeNode* no = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    no->val = valor;
    no->left = NULL;
    no->right = NULL;
    return no;
}

bool verifica(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL)
        return true;

    if (p == NULL || q == NULL)
        return false;

    if (p->val != q->val)
        return false;

    return verifica(p->left, q->left) &&
           verifica(p->right, q->right);
}