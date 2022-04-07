/*Tugas Praktikum Struktur Data - Modul 1 Soal 1 Cek Palindrome dengan Stack
I Putu Windy Arya Sagita - 5027201071*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//inisialisasi struktur node dan stack
typedef struct stackNode {
    char data;
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

//fungsi untuk cek apakah stack kosong atau tidak
bool sisEmpty(Stack *stack) {
    return (stack->top == NULL);
}

//fungsi untuk push atau memasukan data ke stack
void sPush(Stack *stack, char value) {
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->size++;
        newNode->data = value;

        if (sisEmpty(stack)) {
            newNode->next = NULL;
        } else {
            newNode->next = stack->top;
        }
        stack->top = newNode;
    }
}

//fungsi untuk pop atau mengeluarkan/eliminasi data dari stack
char sPop(Stack *stack) {
    char chara;
    if (!sisEmpty(stack)) {
        chara = stack->top->data;
        StackNode *temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
        stack->size;
    }
    return chara;
}

//fungsi untuk mengambil data stack paling atas
int sTop(Stack *stack) {
    if (!sisEmpty(stack)) {
        return stack->top->data;
    }
    return 0;
}

//fungsi untuk mencari size atau ukuran dari stack
unsigned sSize(Stack *stack) {
    return stack->size;
}

//fungsi untuk cek palindrome
bool isPalindrome(Stack *stack, char text[]) {
    int len = strlen(text);
    int i;
    for (i = 0; i < len/2; i++) {
        if (text[i] != sPop(stack)) {
            return false;
        }
    }
    return true;
}

//main program
int main() {
    //inisialisasi variabel dan stack
    Stack mystack;
    sInit(&mystack);
    char text[100];
    int i;

    //input text dari user
    gets(text);
    
    //looping untuk memasukan data ke stack
    for (i = 0; i < strlen(text); i++) {
        sPush(&mystack, text[i]);
    }

    //cek apakah data dalam stack palindrome atau tidak
    if (isPalindrome(&mystack, text)) {
        printf("palindrom");
    } else {
        printf("mahal, eh bukan palindrom deh");
    }
    
    return 0;
}