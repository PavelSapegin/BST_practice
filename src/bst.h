#pragma once

#inlcude <stdbool.h>

typedef struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
}Node;

typedef struct BST
{
    Node *root;
}BST;

// TASK A
Node* createNode(int value);

Node* insertNode(Node* node, value);
void bstInsert(BST* tree, int value);

bool nodeContains(Node* node, int value);
bool bstContains(BST* tree, int value);

void freeNodes(Node* node);
void bstFree(BST* tree);

// TASK B
void _bstinorder(Node *root);
void _bstpreorder(Node *root);
void _bstpostorder(Node *root);

void bstInorder(BST *tree);
void bstPreorder(BST *tree);
void bstPostorder(BST *tree);

