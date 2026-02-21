#pragma once

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
