#include <stdio.h>
#include "../bst.h"

void _bstinorder(Node *root)
{
    Node *curr = root;

    if (curr == NULL)
        return;

    if (curr->left != NULL)
        _bstinorder(curr->left);

    printf("%d ", curr->value);

    if (curr->right != NULL)
        _bstinorder(curr->right);
}
void _bstpreorder(Node *root)
{
    Node *curr = root;
    if (curr == NULL)
        return;

    printf("%d ", curr->value);
    if (curr->left != NULL)
        _bstpreorder(curr->left);

    if (curr->right != NULL)

        _bstpreorder(curr->right);
}
void _bstpostorder(Node *root)
{
    Node *curr = root;
    if (curr == NULL)
        return;

    if (curr->left != NULL)
        _bstpostorder(curr->left);

    if (curr->right != NULL)
        _bstpostorder(curr->right);

    printf("%d ", curr->value);
}

void bstInorder(BST *tree)
{
    if (tree != NULL)
        _bstinorder(tree->root);
}
void bstPreorder(BST *tree)
{
    if (tree != NULL)
        _bstpreorder(tree->root);
}
void bstPostorder(BST *tree)
{
    if (tree != NULL)
        _bstpostorder(tree->root);
}
