// C program to remove duplicate elements in a single linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} slNode;

slNode *head, *tail = NULL;

void addNode(int value) {
    slNode *newNode = (slNode *)malloc(sizeof(slNode));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void delDuplicate() {
    slNode *current = head;
    slNode *index = NULL;
    slNode *temp = NULL;
    if (head == NULL) {
        return;
    } else {
        while (current != NULL) {
            temp = current;
            index = current->next;
            while (index != NULL) {
                if (current->data == index->data) {
                    temp->next = index->next;
                } else {
                    temp = index;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

void PrintList() {
    slNode *current = head;
    if (head != NULL) {
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
    } else {
        printf("List is empty\n");
    }
}

int main() {
    addNode(9);
    addNode(8);
    addNode(9);
    addNode(7);
    addNode(12);
    addNode(15);
    addNode(5);
    addNode(5);

    printf("Initial List : ");
    PrintList();
    delDuplicate();
    
    printf("\nList after deleting the duplicate element : ");
    PrintList();
    return 0;
}