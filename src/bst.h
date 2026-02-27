#pragma once

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct BST {
    Node* root;
} BST;

// TASK A
Node* createNode(int value);

Node* insertNode(Node* node, int value);
void bstInsert(BST* tree, int value);

bool nodeContains(Node* node, int value);
bool bstContains(BST* tree, int value);

void freeNodes(Node* node);
void bstFree(BST* tree);

// TASK B
void bstInorderRecursive(Node* root);
void bstPreorderRecursive(Node* root);
void bstPostorderRecursive(Node* root);

void bstInorder(BST* tree);
void bstPreorder(BST* tree);
void bstPostorder(BST* tree);

// TASK C
int bstHeightRecursive(Node* root);
int bstHeight(BST* tree);

int bstSizeRecursive(Node* root);
int bstSize(BST* tree);

// if tree is empty bstMin will return warning and stop the program
int bstMin(BST* tree);

// if tree is empty bstMax will return warning and stop the program
int bstMax(BST* tree);

//TASK D
Node* findMin(Node* root);
Node* deleteNode(Node* root, int val, bool* deleted);
void bstDelete(BST* tree, int value);

// Task E
void inorderFillArr(Node* root, int* arr, int* index);
int* mergeSorted(const int* tree1, int tree1size, const int* tree2, int tree2size, int* newSize);
Node* buildBalanced(int* arr, int left, int right);
BST* bstMerge(BST* tree1, BST* tree2);

// Task F
bool isNodeValid(const Node* node, long long minVal, long long maxVal);
bool bstIsValid(BST* tree);
