/*Tugas Praktikum Struktur Data - Modul 0 Soal 1
I Putu Windy Arya Sagita - 5027201071*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//struktur linked list
typedef struct snode_t {
    int data;
    struct snode_t *next;
} SListNode;

typedef struct slist_t {
    unsigned _size;
    SListNode *_head;
} SinglyList;

//definisi fungsi
//fungsi untuk inisialiasi singly list
void slist_init(SinglyList *list) {
    list->_head = NULL;
    list->_size = 0;
}

//fungsi untuk cek apakah list kosong atau tidak
bool slist_isEmpty(SinglyList *list) {
    return (list->_head == NULL);
}

//fungsi untuk melakukan pushback
void slist_pushBack(SinglyList *list, int value) {
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

//fungsi untuk melakukan popback
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

//fungsi untuk operasi setiap elemen
void forEachElement(SinglyList *list, void func (int *)) {
    SListNode *temp = list->_head;

    while (temp != NULL) {
        func(&temp->data);
        temp = temp->next;
    }
}

//fungsi untuk print elemen
void printElement(int *data) {
    printf("%d ", *data);
}

//fungsi untuk mengalikan data dengan 2
void multiply2(int *data) {
    *data *= 2;
}

//fungsi untuk membalikan setiap data
void reverseEach(int *data) {
    int temp = *data;
    *data = 0;

    while (temp != 0) {
        *data *= 10;
        *data = *data + temp % 10;
        temp /= 10;
    }
}

//fungsi untuk sum atau total dari digit setiap data
void sumDigit(int *data) {
    int rmd = 0;
    int sum = 0;

    while (*data != 0) {
        rmd = *data % 10;
        sum += rmd;
        *data /= 10;
    }
    *data = sum;
}

//main program
int main() {
    //deklarasi list
    SinglyList myList;
    //inisialiasi
    slist_init(&myList);
    //masukan data ke list (pushback)
    slist_pushBack(&myList, 7);
    slist_pushBack(&myList, 3);
    slist_pushBack(&myList, 39);
    slist_pushBack(&myList, 77);
    slist_pushBack(&myList, 676);
    //print isi list awal
    printf("The initial data : ");
    forEachElement(&myList, printElement);
    printf("\n");
    //kalikan setiap data dengan dua dan print
    printf("The data after multiply by 2 : ");
    forEachElement(&myList, multiply2);
    forEachElement(&myList, printElement);
    printf("\n");
    //membalikan setiap data
    printf("The data after, reverse the element : ");
    forEachElement(&myList, reverseEach);
    forEachElement(&myList, printElement);
    printf("\n");
    //menambahkan setiap digit dari data
    printf("The data after summing the digit : ");
    forEachElement(&myList, sumDigit);
    forEachElement(&myList, printElement);
    printf("\n");

    return 0;
}