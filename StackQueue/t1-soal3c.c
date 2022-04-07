/*Tugas Praktikum Struktur Data - Modul 1 Soal 3 String dengan Deque
I Putu Windy Arya Sagita - 5027201071*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//inisialisasi node dan deque
typedef struct dNode {
    char data[100];
    struct dNode *next, *prev;
} DListNode;

typedef struct dq {
    DListNode *head, *tail;
    unsigned size;
} Deque;

//fungsi untuk membuat node
DListNode* dListCreateNode(char val[100]) {
    DListNode *newNode = (DListNode*) malloc(sizeof(DListNode));
    
    if (!newNode) {
        return NULL;
    }
    strcpy(newNode->data, val);
    newNode->next = NULL;
    newNode->prev = NULL;
    return (DListNode*) newNode;
}

//fungsi untuk inisialisasi deque
void dqInit(Deque *deque) {
    deque->head = deque->tail = NULL;
    deque->size = (unsigned) 0;
}

//fungsi untuk cek apakah deque kosong
bool dqIsEmpty(Deque *deque) {
    return (deque->head == NULL && deque->tail == NULL);
}

//fungsi untuk memasukan data ke deque pada posisi paling depan
void dqPushFront(Deque *deque, char val[100]) {
    DListNode *newNode = dListCreateNode(val);

    if (newNode) {
        deque->size++;
        if (dqIsEmpty(deque)) {
            deque->head = newNode;
            deque->tail = newNode;
            return;
        }
        newNode->next = deque->head;
        deque->head->prev = newNode;
        deque->head = newNode;
    }
}

//fungsi untuk memasukan data ke deque pada posisi paling belakang
void dqPushBack(Deque *deque, char val[100]) {
    DListNode *newNode = dListCreateNode(val);

    if (newNode) {
        deque->size++;
        if (dqIsEmpty(deque)) {
            deque->head = newNode;
            deque->tail = newNode;
            return;
        }
        deque->tail->next = newNode;
        newNode->prev = deque->tail;
        deque->tail = newNode;
    }
}

//fungsi untuk mendapatkan data paling depan dari deque
char *dqFront(Deque *deque) {
    if (!dqIsEmpty(deque)) {
        return (deque->head->data);
    }
    return 0;
}

//fungsi untuk mendapatkan data paling belakang dari deque
char *dqBack(Deque *deque) {
    if (!dqIsEmpty(deque)) {
        return (deque->tail->data);
    }
    return 0;
}

//fungsi untuk mengeluarkan data paling depan dari deque
void dqPopFront(Deque *deque) {
    if (!dqIsEmpty(deque)) {
        DListNode *temp = deque->head;
        if (deque->head == deque->tail) {
            deque->head = NULL;
            deque->tail = NULL;
            free(temp);
        } else {
            deque->head = deque->head->next;
            deque->head->prev = NULL;
            free(temp);
        }
        deque->size--;
    }
}

//fungsi untuk mengeluarkan data paling belakang dari deque
void dqPopBack(Deque *deque) {
    if (!dqIsEmpty(deque)) {
        DListNode *temp;
        if (deque->head == deque->tail) {
            temp = deque->head;
            deque->head = NULL;
            deque->tail = NULL;
            free(temp);
        } else {
            temp = deque->tail;
            deque->tail = deque->tail->prev;
            deque->tail->next = NULL;
            free(temp);
        }
        deque->size--;
    }
}

//main program
int main() {
    //deklarasi dan inisialisasi deque dan variabel
    Deque mydq;
    char str[100];
    char ex[] = "exit";
    dqInit(&mydq);

    //loop untuk input dari user dan memasukan data tsb ke deque
    do {
        gets(str);
        if (strcmp(ex, str) == 0) {
            break;
        } else {
            dqPushBack(&mydq, str);
        }
    } while (1);
    
    //loop untuk menampilkan data deque dari paling depan dan mengeluarkannya dari deque
    while (!dqIsEmpty(&mydq)) {
        printf("%s ", dqFront(&mydq));
        dqPopFront(&mydq);
    }

    return 0;
}