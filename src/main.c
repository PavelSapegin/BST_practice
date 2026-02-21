#include "bst.h"
#include <stdio.h>

int main()
{
    BST tree = { NULL };

    bstInsert(&tree, 100);
    bstInsert(&tree, 1);
    bstInsert(&tree, 50);
    if (!bstContains(&tree, 50) || !bstContains(&tree, 100) || !bstContains(&tree, 1)) {
        printf("error: should value wasn't inserted");
        return 1;
    }

    bstFree(&tree);
}
