// C program to sort Linked List

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct sNode {
    int data;
    struct sNode *next;
} sLNode;

typedef struct sList {
    unsigned size;
    sLNode *head;
} SinglyList;

void sLInit(SinglyList *list) {
    list->head = NULL;
    list->size = 0;
}

bool sLisEmpty(SinglyList *list) {
    return (list->head == NULL);
}

void sLpushFront(SinglyList *list, int value) {
    sLNode *newNode = (sLNode *)malloc(sizeof(sLNode));
    if (newNode) {
        list->size++;
        newNode->data = value;
        if (sLisEmpty(list)) {
            newNode->next = NULL;
        } else {
            newNode->next = list->head;
        }
        list->head = newNode;
    }
}

void swap(sLNode *a, sLNode *b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void bubbleSort(SinglyList *list) {
    int swapped, i;
    sLNode *ptr1;
    sLNode *lptr = NULL;
    if (list == NULL) {
        return;
    }
    do {
        swapped = 0;
        ptr1 = list->head;
        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;

    } while (swapped);
}

void printList(SinglyList *list) {
    sLNode *temp = list->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    SinglyList mylist;
    sLInit(&mylist);
    sLpushFront(&mylist, 1);
    sLpushFront(&mylist, 77);
    sLpushFront(&mylist, 23);
    sLpushFront(&mylist, 41);
    sLpushFront(&mylist, 90);
    printf("Initial List : ");
    printList(&mylist);
    bubbleSort(&mylist);
    printf("\nList after sorting : ");
    printList(&mylist);
    return 0;
}