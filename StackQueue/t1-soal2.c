/*Tugas Praktikum Struktur Data - Modul 1 Soal 2 Priority Queue
I Putu Windy Arya Sagita - 5027201071*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//inisialisasi struktur node dan priority queue
typedef struct pqNode {
    int data;
    int priority;
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

//fungsi untuk cek apakah queue kosong atau tidak
bool pqIsEmpty(PriorityQueue *pqueue) {
    return (pqueue->top == NULL);
}

//fungsi untuk memasukan data ke queue
void pqPush(PriorityQueue *pqueue, int val, int urg) {
    PQueueNode *temp = pqueue->top;
    PQueueNode *newNode = (PQueueNode*) malloc(sizeof(PQueueNode));
    newNode->data = val;
    newNode->next = NULL;
    newNode->priority = urg;

    if (pqIsEmpty(pqueue)) {
        pqueue->top = newNode;
        return;
    }
    if (urg > pqueue->top->priority) {
        newNode->next = pqueue->top;
        pqueue->top = newNode;
    } else {
        while (temp->next != NULL && temp->next->priority > urg) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

//fungsi untuk mengeluarkan data dari queue
int pqPop(PriorityQueue *pqueue) {
    int n = 0; 
    if (!pqIsEmpty(pqueue)) {
        n = pqueue->top->data;
        PQueueNode *temp = pqueue->top;
        pqueue->top = pqueue->top->next;
        free(temp);
    }
    return n;
}

//fungsi untuk mendapatkan data paling tinggi pada queue
int pqTop(PriorityQueue *pqueue) {
    if (!pqIsEmpty(pqueue)) {
        return pqueue->top->data;
    } else {
        return 0;
    }
}

//main program
int main() {

    //inisialisasi queue dan variabel
    PriorityQueue mypq;
    pqInit(&mypq);
    int index;
    int i = 0;
    
    //input index atau seberapa banyak command yang akan diberikan
    scanf("%d", &index);

    //loop untuk melakukan priority queue
    while (i < index) {
        int num, urg;
        char command[50];
        //input command dari user
        scanf("%s", command);

        //cek apakah command user merupakan LAYANI
        if (strcmp(command, "LAYANI") == 0) {
            //cek apakah queue kosong atau tidak
            if (pqIsEmpty(&mypq)) {
                printf("HORE!");
            } else {
                printf("%d", pqPop(&mypq));
            }
            printf("\n");
        } else {
            scanf("%d %d", &num, &urg);
            pqPush(&mypq, num, urg);
        }
        i++;
    }

    return 0;
}