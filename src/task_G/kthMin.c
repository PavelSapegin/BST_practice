#include "../bst.h"

Node* bstKthMinRecursive(Node* node, int* k)
{
    if (node == NULL)
        return NULL;

    Node* resLeft = bstKthMinRecursive(node->left, k);
    if (resLeft != NULL)
        return resLeft;

    (*k)--;
    if (*k == 0)
        return node;

    Node* resRight = bstKthMinRecursive(node->right, k);
    return resRight;
}

int bstKthMin(BST* tree, int k)
{
    if ((k <= 0) || (k > bstSize(tree)))
        return -42;

    Node* resNode = bstKthMinRecursive(tree->root, &k);

    if (resNode != NULL)
        return resNode->value;
    else
        return -42;
}
