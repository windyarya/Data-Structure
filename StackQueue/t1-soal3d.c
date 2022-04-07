/*Tugas Praktikum Struktur Data - Modul 1 Soal 3 String dengan Priority Queue
I Putu Windy Arya Sagita - 5027201071*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//inisialsasi struktur node dan priority queue
typedef struct pqNode {
    char data[100];
    struct pqNode *next;
} PQueueNode;

typedef struct pq {
    PQueueNode *top;
    unsigned size;
} PriorityQueue;

//fungsi untuk inisialisasi priority queue
void pqInit(PriorityQueue *pqueue) {
    pqueue->top = NULL;
    pqueue->size = 0;
}

//fungsi untuk cek apakah priority queue kosong
bool pqIsEmpty(PriorityQueue *pqueue) {
    return (pqueue->top == NULL);
}

//fungsi untuk memasukan data ke priority queue
void pqPush(PriorityQueue *pqueue, char val[100]) {
    PQueueNode *temp = pqueue->top;
    PQueueNode *newNode = (PQueueNode*) malloc(sizeof(PQueueNode));
    strcpy(newNode->data, val);
    newNode->next = NULL;

    if (pqIsEmpty(pqueue)) {
        pqueue->top = newNode;
        return;
    }
    if (val[0] < pqueue->top->data[0]) {
        newNode->next = pqueue->top;
        pqueue->top = newNode;
    } else {
        while (temp->next != NULL && temp->next->data[0] < val[0]) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

//fungsi untuk mengeluarkan data dari priority queue
void pqPop(PriorityQueue *pqueue) {
    if (!pqIsEmpty(pqueue)) {
        PQueueNode *temp = pqueue->top;
        pqueue->top = pqueue->top->next;
        free(temp);
    }
}

//fungsi untuk mendapatkan data paling tinggi dari priotity queue
char *pqTop(PriorityQueue *pqueue) {
    if (!pqIsEmpty(pqueue)) {
        return pqueue->top->data;
    } else {
        return '\0';
    }
}

//main program
int main() {
    //deklarasi dan inisialisasi variabel
    PriorityQueue mypq;
    char str[100];
    char ex[] = "exit";
    pqInit(&mypq);

    //loop untuk input dari user dan memasukannya ke priority queue
    do {
        gets(str);
        if (strcmp(ex, str) == 0) {
            break;
        } else {
            pqPush(&mypq, str);
        }
    } while (1);
    
    //loop untuk menampilkan data dari priority queue sekaligus mengeluarkannya
    while (!pqIsEmpty(&mypq)) {
        printf("%s ", pqTop(&mypq));
        pqPop(&mypq);
    }
    return 0;
}