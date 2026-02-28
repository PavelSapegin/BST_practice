#include "../bst.h"

Node* pop(Iterator* it)
{
    Node* result = it->top->node;
    Stack* temp = it->top->next;
    free(it->top);
    it->top = temp;
    return result;
}

void push(Iterator* it, Node* new)
{
    Stack* newTop = malloc(sizeof(Stack));
    newTop->node = new;
    newTop->next = it->top;
    it->top = newTop;
}

Iterator* iteratorInit(BST* tree)
{
    Stack* top = NULL;
    Iterator* it = malloc(sizeof(Iterator));
    it->top = top;
    Node* curr = tree->root;
    while (curr != NULL) {
        push(it, curr);
        curr = curr->left;
    }

    return it;
}

bool iteratorHasNext(Iterator* it)
{
    return (it->top != NULL);
}

int iteratorNext(Iterator* it)
{
    if (iteratorHasNext(it)) {
        Node* resultNode = pop(it);
        Node* curr = resultNode->right;
        while (curr != NULL) {
            push(it, curr);
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
