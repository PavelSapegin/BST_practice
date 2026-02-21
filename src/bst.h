typedef struct Node
{
    int value;
    Node *left;
    Node *right;
}Node;

typedef struct BST
{
    Node *root;
}BST;

// TASK B
void _bstinorder(Node *root);
void _bstpreorder(Node *root);
void _bstpostorder(Node *root);

void bstInorder(BST *tree);
void bstPreorder(BST *tree);
void bstPostorder(BST *tree);
