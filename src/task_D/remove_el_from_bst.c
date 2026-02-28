#include "../bst.h"

Node* findMin(Node* root)
{
    if (root == NULL) {
        return NULL;
    }

    Node* current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* root, int value)
{
    if (root == NULL) {
        return NULL;
    }

    if (value < root->value) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->value) {
        root->right = deleteNode(root->right, value);
    } else {
        // case no left
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        // case no right
        else if (root->right == NULL) {
            Node* tempNode = root->left;
            free(root);
            return tempNode;
        }

        // case 2 child
        Node* minRightNode = findMin(root->right);
        root->value = minRightNode->value;
        root->right = deleteNode(root->right, minRightNode->value);
    }
    return root;
}

void bstDelete(BST* tree, int value)
{
    if (tree == NULL || tree->root == NULL) {
        return;
    }

    tree->root = deleteNode(tree->root, value);
}

