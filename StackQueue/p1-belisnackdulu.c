#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//inisialsasi struktur node dan priority queue
typedef struct pqNode {
    char data[100];
    int harga;
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
void pqPush(PriorityQueue *pqueue, char val[100], int har) {
    PQueueNode *temp = pqueue->top;
    PQueueNode *newNode = (PQueueNode*) malloc(sizeof(PQueueNode));
    strcpy(newNode->data, val);
    newNode->next = NULL;
    newNode->harga = har;

    if (pqIsEmpty(pqueue)) {
        pqueue->top = newNode;
        return;
    }
    if (har < pqueue->top->harga) {
        newNode->next = pqueue->top;
        pqueue->top = newNode;
    } else {
        while (temp->next != NULL && temp->next->harga < har) {
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
    pqInit(&mypq);
    int index;
    int i = 0;
    
    //input index atau seberapa banyak command yang akan diberikan
    scanf("%d", &index);

    //loop untuk melakukan priority queue
    while (i < index) {
        int hrg;
        char command[50];
        //input command dari user
        scanf("%s", command);

        //cek apakah command user merupakan LAYANI
        if (strcmp(command, "BELI") == 0) {
            printf("%s\n", pqTop(&mypq));
            pqPop(&mypq);
        } else {
            scanf("%d", &hrg);
            pqPush(&mypq, command, hrg);
        }
        i++;
    }
    return 0;
}