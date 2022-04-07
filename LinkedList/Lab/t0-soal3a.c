/*Tugas Praktikum Struktur Data - Modul 0 Soal 3 Singly List
I Putu Windy Arya Sagita - 5027201071*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* Struktur Node */
typedef struct snode_t {
    char data;
    struct snode_t *next;
} SListNode;

/* Struktur ADT SinglyList */ 
typedef struct slist_t {
    unsigned _size;
    SListNode *_head;
} SinglyList;

/* Inisialisasi Single Linked List */
void slist_init(SinglyList *list) {
    list->_head = NULL;
    list->_size = 0;
}

/* Memeriksa apakah list kosong */
bool slist_isEmpty(SinglyList *list) {
    return (list->_head == NULL);
}

//memeriksa apakah list full
bool slist_isFull(int data) {
    return (data <= 100);
}

//fungsi untuk melakukan push back atau menambahkan data
void slist_pushBack(SinglyList *list, char value) {
    if (slist_isFull(list->_size)) {
        SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
        if (newNode) {
            list->_size++;
            newNode->data = value;
            newNode->next = NULL;
            
            if (slist_isEmpty(list)) {
                list->_head = newNode;
            } else {
                SListNode *temp = list->_head;
                while (temp->next != NULL) { 
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }
    }
}


//fungsi untuk menghapus data 
void slist_popBack(SinglyList *list) {
    if (!slist_isEmpty(list)) {
        SListNode *nextNode = list->_head->next;
        SListNode *currNode = list->_head;

        if (currNode->next == NULL) {
            free(currNode);
            list->_head = NULL;
            return;
        }

        while (nextNode->next != NULL) {
            currNode = nextNode;
            nextNode = nextNode->next;
        }
        currNode->next = NULL;
        free(nextNode);
        list->_size--;
    }
}

void forEachElement(SinglyList *list, void func (char *)) {
    SListNode *point = list->_head;

    if (point != NULL) {
        while(point != NULL) {
            func(&point->data);
            point = point->next;
        }
    }
}

// Fungsi untuk mencetak data pada list
void printElement(char *data) {
    printf("%c", *data);
}

//main program
int main() {
    // Membuat objek SinglyList
    SinglyList myList;

    // Melakukan inisialisasi
    slist_init(&myList);

    // Menggunakan operasi pushback
    slist_pushBack(&myList, 'P');
    slist_pushBack(&myList, 'e');
    slist_pushBack(&myList, 'm');
    slist_pushBack(&myList, 'r');
    slist_pushBack(&myList, 'o');
    slist_pushBack(&myList, 'g');
    slist_pushBack(&myList, 'r');
    slist_pushBack(&myList, 'a');
    slist_pushBack(&myList, 'm');
    slist_pushBack(&myList, 'a');
    slist_pushBack(&myList, 'n');

    // Menampilkan ata print data
    forEachElement(&myList, printElement);
    printf("\n");

    // Menampilkan panjang string
    printf("String Length: %d \n", myList._size);
    
    return 0;
}