#include "../bst.h"
#include <stdio.h>

void bstInorder(Node* root)
{
    Node* curr = root;

    if (curr == NULL)
        return;

    if (curr->left != NULL)
        bstInorder(curr->left);

    printf("%d ", curr->value);

    if (curr->right != NULL)
        bstInorder(curr->right);
}
void bstPreorder(Node* root)
{
    Node* curr = root;
    if (curr == NULL)
        return;

    printf("%d ", curr->value);
    if (curr->left != NULL)
        bstPreorder(curr->left);

    if (curr->right != NULL)

        bstPreorder(curr->right);
}
void bstPostorder(Node* root)
{
    Node* curr = root;
    if (curr == NULL)
        return;

    if (curr->left != NULL)
        bstPostorder(curr->left);

    if (curr->right != NULL)
        bstPostorder(curr->right);

    printf("%d ", curr->value);
}

void bstInorder(BST* tree)
{
    if (tree != NULL)
        bstInorder(tree->root);
}
void bstPreorder(BST* tree)
{
    if (tree != NULL)
        bstPreorder(tree->root);
}
void bstPostorder(BST* tree)
{
    if (tree != NULL)
        bstPostorder(tree->root);
}
