//Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* insere(int valor);
bool verifica(struct TreeNode* a, struct TreeNode* b);
bool isSymmetric(struct TreeNode* root);

int main() {
    struct TreeNode* root = insere(1);
    root->left = insere(2);
    root->right = insere(2);

    root->left->left = insere(3);
    root->left->right = insere(4);

    root->right->left = insere(4);
    root->right->right = insere(3);

    if (isSymmetric(root))
        printf("A arvore é simetrica.\n");
    else
        printf("A arvore não é simetrica.\n");

    return 0;
}

struct TreeNode* insere(int valor) {
    struct TreeNode* no = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    no->val = valor;
    no->left = NULL;
    no->right = NULL;
    return no;
}

bool verifica(struct TreeNode* a, struct TreeNode* b) {
    if (a == NULL && b == NULL)
        return true;

    if (a == NULL || b == NULL)
        return false;

    if (a->val != b->val)
        return false;

    return verifica(a->left, b->right) && verifica(a->right, b->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL)
        return true;
    else
        return verifica(root->left, root->right);
}