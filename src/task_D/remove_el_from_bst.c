#include "../bst.h"

Node *find_min(Node *root)
{
    if (root == NULL) {
        return NULL;
    }

    Node *current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node *deleteNode(Node *root, int val, bool *deleted)
{
    if (root == NULL) {
        return NULL;
    }

    if (val < root->value) {
        root->left = deleteNode(root->left, val, deleted);
    } else if (val > root->value) {
        root->right = deleteNode(root->right, val, deleted);
    } else {
        *deleted = true;

        // case no left
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        // case no right
        else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        // case 2 child
        Node *min_right = find_min(root->right);
        root->value = min_right->value;
        // to avoid overwriting make new deleted flag
        bool temp_deleted = false;
        root->right = deleteNode(root->right, min_right->value, &temp_deleted);
    }
    return root;
}

void bstDelete(BST *tree, int value)
{
    if (tree == NULL || tree->root == NULL) {
        return;
    }

    bool deleted = false;
    tree->root = deleteNode(tree->root, value, &deleted);
}