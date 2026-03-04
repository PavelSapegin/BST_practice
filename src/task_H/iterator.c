#include "../bst.h"

Node* pop(Iterator* it)
{
    if ((it == NULL) || (it->top == NULL))
        return NULL;
    Node* result = it->top->node;
    Stack* temp = it->top->next;
    free(it->top);
    it->top = temp;
    return result;
}

bool push(Iterator* it, Node* new)
{
    if ((it == NULL) || (new == NULL))
        return false;
    Stack* newTop = malloc(sizeof(Stack));
    if (newTop == NULL)
        return false;
    newTop->node = new;
    newTop->next = it->top;
    it->top = newTop;
    return true;
}

Iterator* iteratorInit(BST* tree)
{
    if (tree == NULL) {
        printf("Pointer to tree is NULL");
        return NULL;
    }
    Stack* top = NULL;
    Iterator* it = malloc(sizeof(Iterator));
    if (it == NULL)
        return NULL;
    it->top = top;
    Node* curr = tree->root;
    while (curr != NULL) {
        if (!push(it, curr)) {
            IteratorFree(it);
            return NULL;
        }
        curr = curr->left;
    }

    return it;
}

bool iteratorHasNext(Iterator* it)
{
    if (it == NULL)
        return false;
    return (it->top != NULL);
}

int iteratorNext(Iterator* it)
{
    if (iteratorHasNext(it)) {
        Node* resultNode = pop(it);
        if (resultNode == NULL)
            return -42;
        Node* curr = resultNode->right;
        while (curr != NULL) {
            if (!push(it, curr))
                return -42;
            curr = curr->left;
        }

        return resultNode->value;
    } else
        return -42;
}

void iteratorFree(Iterator* it)
{
    if (it == NULL)
        return;

    while (iteratorHasNext(it)) {
        pop(it);
    }

    free(it);
}
