#include "../bst.h"
#include <stdio.h>

void bstInorderRecursive(Node* root)
{
    Node* curr = root;

    if (curr == NULL)
        return;

    if (curr->left != NULL)
        bstInorderRecursive(curr->left);

    printf("%d ", curr->value);

    if (curr->right != NULL)
        bstInorderRecursive(curr->right);
}
void bstPreorderRecursive(Node* root)
{
    Node* curr = root;
    if (curr == NULL)
        return;

    printf("%d ", curr->value);
    if (curr->left != NULL)
        bstPreorderRecursive(curr->left);

    if (curr->right != NULL)

        bstPreorderRecursive(curr->right);
}
void bstPostorderRecursive(Node* root)
{
    Node* curr = root;
    if (curr == NULL)
        return;

    if (curr->left != NULL)
        bstPostorderRecursive(curr->left);

    if (curr->right != NULL)
        bstPostorderRecursive(curr->right);

    printf("%d ", curr->value);
}

void bstInorder(BST* tree)
{
    if (tree != NULL)
        bstInorderRecursive(tree->root);
}
void bstPreorder(BST* tree)
{
    if (tree != NULL)
        bstPreorderRecursive(tree->root);
}
void bstPostorder(BST* tree)
{
    if (tree != NULL)
        bstPostorderRecursive(tree->root);
}
