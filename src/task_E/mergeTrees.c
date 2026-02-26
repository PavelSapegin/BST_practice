#include "../bst.h"

void inorderFillArr(Node* root, int* arr, int* index)
{
    if (root == NULL)
        return;

    inorderFillArr(root->left, arr, index);
    arr[(*index)++] = root->value;
    inorderFillArr(root->right, arr, index);
}

int* mergeSorted(const int* tree1, int tree1Size, const int* tree2, int tree2Size, int* newSize)
{
    if (tree1Size + tree2Size == 0) {
        *newSize = 0;
        return NULL;
    }

    int* result = malloc((tree1Size + tree2Size) * sizeof(int));
    if (!result) {
        printf("Couldn't allocate memory\n");
        return NULL;
    }

    int i = 0, j = 0, k = 0;
    while (i < tree1Size && j < tree2Size) {
        if (tree1[i] < tree2[j])
            result[k++] = tree1[i++];
        else if (tree1[i] > tree2[j])
            result[k++] = tree2[j++];
        else {
            result[k++] = tree1[i];
            ++i;
            ++j;
        }
    }
    while (i < tree1Size)
        result[k++] = tree1[i++];
    while (j < tree2Size)
        result[k++] = tree2[j++];

    *newSize = k;
    return result;
}

Node* buildBalanced(int* arr, int left, int right)
{
    if (left > right)
        return NULL;

    int mid = (left + right) / 2;

    Node* root = createNode(arr[mid]);
    if (!root) {
        printf("Couldn't allocate memory for node");
        return NULL;
    }

    root->left = buildBalanced(arr, left, mid - 1);
    if ((mid - 1) >= left && !root->left) {
        free(root);
        return NULL;
    }
    root->right = buildBalanced(arr, mid + 1, right);
    if ((mid + 1) <= right && !root->right) {
        freeNodes(root->left);
        free(root);
        return NULL;
    }

    return root;
}

BST* bstMerge(BST* tree1, BST* tree2)
{
    int tree1Size = (tree1 != NULL) ? bstSize(tree1) : 0;
    int tree2Size = (tree2 != NULL) ? bstSize(tree2) : 0;

    int* tree1Arr = NULL;
    if (tree1Size > 0) {
        tree1Arr = malloc(tree1Size * sizeof(int));
        if (!tree1Arr) {
            printf("Couldn't allocate memory\n");
            return NULL;
        }
    }
    int* tree2Arr = NULL;
    if (tree2Size > 0) {
        tree2Arr = malloc(tree2Size * sizeof(int));
        if (!tree2Arr) {
            free(tree1Arr);
            printf("Couldn't allocate memory\n");
            return NULL;
        }
    }
    int idx1 = 0;
    if (tree1Size > 0)
        inorderFillArr(tree1->root, tree1Arr, &idx1);
    int idx2 = 0;
    if (tree2Size > 0)
        inorderFillArr(tree2->root, tree2Arr, &idx2);

    int mergedSize = 0;
    int* mergedArr = mergeSorted(tree1Arr, tree1Size, tree2Arr, tree2Size, &mergedSize);

    free(tree1Arr);
    free(tree2Arr);

    if (!mergedArr)
        return NULL;

    BST* mergedTree = malloc(sizeof(BST));
    if (!mergedTree) {
        free(mergedArr);
        printf("Couldn't allocate memory\n");
        return NULL;
    }

    mergedTree->root = buildBalanced(mergedArr, 0, mergedSize - 1);
    if (!mergedTree->root) {
        free(mergedTree);
        free(mergedArr);
        return NULL;
    }

    free(mergedArr);
    return mergedTree;
}
