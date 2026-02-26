#include "../bst.h"

bool isNodeValid(const Node* node, long long minVal, long long maxVal)
{
    if (node == NULL)
        return true;

    long long val = (long long)node->value;
    if (val <= minVal || val >= maxVal)
        return false;

    return isNodeValid(node->left, minVal, val) && isNodeValid(node->right, val, maxVal);
}

bool bstIsValid(BST* tree)
{
    if (tree == NULL)
        return true;

    return isNodeValid(tree->root, LLONG_MIN, LLONG_MAX);
}
