#include <stdio.h>
#include "bst.h"

void bstInorder(BST *tree)
{
    Node *curr = tree;

    if (curr == NULL)
    {
        return;
    }

    if (curr->left != NULL)
    {
        bstInorder(curr->left);
    }

    printf("%d ", curr->value);

    if (curr->right != NULL)
    {
        bstInorder(curr->right);
    }
}
void bstPreorder(BST *tree)
{
    Node *curr = tree;
    if (curr == NULL)
    {
        return;
    }
    printf("%d ", curr->value);
    if (curr->left != NULL)
    {
        bstPreorder(curr->left);
    }
    if (curr->right != NULL)
    {
        bstPreorder(curr->right);
    }
}
void bstPostorder(BST *tree)
{
    Node *curr = tree;
    if (curr == NULL)
    {
        return;
    }

    if (curr->left != NULL)
    {
        bstPostorder(curr->left);
    }

    if (curr->right != NULL)
    {
        bstPostorder(curr->right);
    }

    printf("%d ", curr->value);
}
