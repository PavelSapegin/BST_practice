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

Node* createNode(int value);

Node* insertNode(Node* node, value);
void bstInsert(BST* tree, int value);

bool nodeContains(Node* node, int value);
bool bstContains(BST* tree, int value);

void freeNodes(Node* node);
void bstFree(BST* tree);
