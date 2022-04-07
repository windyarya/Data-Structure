/*Tugas Praktikum Struktur Data - Modul 1 Soal 3 String dengan Stack
I Putu Windy Arya Sagita - 5027201071*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//inisialisasi struktur node dan stack
typedef struct stackNode {
    char data[100];
    struct stackNode *next;
} StackNode;

typedef struct st {
    StackNode *top;
    unsigned size;
} Stack;

//fungsi untuk inisialisasi stack
void sInit(Stack *stack) {
    stack->size = 0;
    stack->top = NULL;
}

//fungsi untuk cek apakah stack kosong
bool sisEmpty(Stack *stack) {
    return (stack->top == NULL);
}

//fungsi untuk memasukan data ke stack
void sPush(Stack *stack, char str[100]) {
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->size++;
        strcpy(newNode->data, str);
        
        if (sisEmpty(stack)) {
            newNode->next = NULL;
        } else {
            newNode->next = stack->top;
        }
        stack->top = newNode;
    }
}

//fungsi untuk mengeluarkan data dari stack
void sPop(Stack *stack) {
    if (!sisEmpty(stack)) {
        StackNode *temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
        stack->size--;
    }
}

//fungsi untuk mendapatkan data paling atas pada stack
char *sTop(Stack *stack) {
    if (!sisEmpty(stack)) {
        return stack->top->data;
    }

    return 0;
}

//fungsi untuk mendapatkan size atau ukuran stack
unsigned sSize(Stack *stack) {
    return stack->size;
}

//main program
int main(int argc, char const *argv[]) {
    //inisialisasi variabel dan stack
    Stack mystack;
    char str[100];
    char ex[] = "exit";
    sInit(&mystack);

    //loop untuk input dari user dan memasukannya ke stack
    do {
        gets(str);
        if (strcmp(ex, str) == 0) {
            break;
        } else {
            sPush(&mystack, str);
        }
    } while (1);
    
    //loop untuk menampilkan dan mengeluarkan data dari stack
    while (!sisEmpty(&mystack)) {
        printf("%s ", sTop(&mystack));
        sPop(&mystack);
    }

    return 0;
}