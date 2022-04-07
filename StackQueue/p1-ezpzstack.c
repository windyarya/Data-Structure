#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stackNode {
    int data;
    struct stackNode *next;
} StackNode;

typedef struct st {
    StackNode *top;
    unsigned size;
} Stack;

void sInit(Stack *stack) {
    stack->size = 0;
    stack->top = NULL;
}

bool sisEmpty(Stack *stack) {
    return (stack->top == NULL);
}

void sPush(Stack *stack, int value) {
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->size++;
        newNode->data = value;

        if (sisEmpty(stack)) {
            newNode->next = NULL;
        } else {
            newNode->next = stack->top;
        }
        stack->top = newNode;
    }
}

void sPop(Stack *stack) {
    if (!sisEmpty(stack)) {
        StackNode *temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
        stack->size--;
    }
}

int sTop(Stack *stack) {
    if (!sisEmpty(stack)) {
        return stack->top->data;
    }
    return 0;
}

unsigned stack_size(Stack *stack) {
    return stack->size;
}

int main(int argc, char const *argv[]) {
    Stack mystack;
    int n, i, index, j;
    sInit(&mystack);
    scanf("%d", &index);

    for (i = 0; i < index; i++) {
        scanf("%d", &n);
        if (n == 1) {
            scanf("%d", &j);
            sPush(&mystack, j);
        } else if (n == 2) {
            sPop(&mystack);
        } else if (n == 3) {
            if (sisEmpty(&mystack)) {
                printf("kosong!\n");
            } else {
                printf("%d\n", sTop(&mystack));
            }
        }
    }
    return 0;
}