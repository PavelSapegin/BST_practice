#include <bst.h>

Node* createNode(int value)
{
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL)
        return NULL;

    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode
}

Node* insertNode(Node* node, value)
{
    if (node == NULL)
        return createNode(value);

    if (value < node->value)
        node->left = insertNode(node, value);
    else if (value > node->value)
        node->right = insertNode(node, value);

    return node;
}

void bstInsert(BST* tree, int value)
{
    if (tree == NULL)
        return;
    tree->root = insertNode(tree->root, value);
}

bool nodeContains(Node* node, int value)
{
    if (node == NULL)
        return false;

    if (node->value == value)
        return true;

    else if (value < node->value)
        return nodeContains(node->left, value);
    else
        return nodeContains(node->right, value);
}

bool bstContains(BST* tree, int value)
{
    if (tree = NULL)
        return;

    return nodeContains(tree->root, value);
}

void freeNodes(Node* node)
{
    if (node == NULL)
        return;

    freeNodes(node->left);
    freeNodes(node->right);
    free(node);
}

void bstFree(BST* tree)
{
    if (tree == NULL)
        return;

    freeNodes(tree->root);
    tree->root = NULL;
}
