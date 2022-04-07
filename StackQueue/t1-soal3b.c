/*Tugas Praktikum Struktur Data - Modul 1 Soal 3 String dengan Queue
I Putu Windy Arya Sagita - 5027201071*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//inisialisasi struktur node dan queue
typedef struct qNode {
    char data[100];
    struct qNode *next;
} QueueNode;

typedef struct q {
    QueueNode *front, *rear;
    unsigned size;
} Queue;

//fungsi untuk inisialisasi queue
void qInit(Queue *queue) {
    queue->size = 0;
    queue->front = NULL;
    queue->rear = NULL;
}

//fungsi untuk cek apakah queue kosong
bool qIsEmpty(Queue *queue) {
    return (queue->front == NULL && queue->rear == NULL);
}

//fungsi untuk memasukan data ke queue
void qPush(Queue *queue, char val[100]) {
    QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode));
    if (newNode) {
        queue->size++;
        strcpy(newNode->data, val);
        newNode->next = NULL;
        if (qIsEmpty(queue)) {
            queue->front = queue->rear = newNode;
        } else {
            queue->rear->next = newNode;
            queue->rear = newNode;
        }
    }
}

//fungsi untuk mengeluarkan data dari queue
void qPop(Queue *queue) {
    if (!qIsEmpty(queue)) {
        QueueNode *temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
        if (queue->front == NULL) {
            queue->rear = NULL;
        }
        queue->size--;
    }
}

//fungsi untuk mendapatkan data paling depan di queue
char *qFront(Queue *queue) {
    if (!qIsEmpty(queue)) {
        return (queue->front->data);
    }
    return (int)0;
}

//fungsi untuk mendapatkan size dari queue
int qSize(Queue *queue) {
    return queue->size;
}

//main program
int main() {
    //deklarasi dan inisialisasi queue dan variabel
    Queue myq;
    char str[100];
    char ex[] = "exit";
    qInit(&myq);

    //loop untuk input dari user dan memasukan data ke dalam queue
    do {
        gets(str);
        if (strcmp(ex, str) == 0) {
            break;
        } else {
            qPush(&myq, str);
        }
    } while (1);
    
    //loop untuk menampilkan data yang ada di queue sekaligus mengeluarkannya
    while (!qIsEmpty(&myq)) {
        printf("%s ", qFront(&myq));
        qPop(&myq);
    }

    return 0;
}