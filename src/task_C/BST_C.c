#include "../bst.h"
#include <stdio.h>

int bstHeightRecursive(Node* root)
{
    if (root == NULL) {
        return 0;
    }
    int leftHeight = bstHeightRecursive(root->left);
    int rightHeight = bstHeightRecursive(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int bstHeight(BST* tree)
{
    if (tree == NULL) {
        return 0;
    }

    bstHeightRecursive(tree->root);
}

int bstSizeRecursive(Node* root)
{
    if (root == NULL) {
        return 0;
    }

    return 1 + bstSizeRecursive(root->left) + bstSizeRecursive(root->right);
}

int bstSize(BST* tree)
{
    if (tree == NULL) {
        return 0;
    }

    bstSizeRecursive(tree->root);
}

// if tree is empty bstMin will return warning and stop the program
int bstMin(BST* tree)
{
    if (tree == NULL || tree->root == NULL) {
        printf("tree is empty\n");
        exit(-1);
    }

    Node* current = tree->root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current->value;
}

// if tree is empty bstMax will return warning and stop the program
int bstMax(BST* tree)
{
    if (tree == NULL || tree->root == NULL) {
        printf("tree is empty\n");
        exit(-1);
    }

    Node* current = tree->root;
    while (current->right != NULL) {
        current = current->right;
    }
    return current->value;
}
