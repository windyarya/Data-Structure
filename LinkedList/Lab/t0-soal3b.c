/*Tugas Praktikum Struktur Data - Modul 0 Soal 3 Dynamic Array
I Putu Windy Arya Sagita - 5027201071*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Struktur ADT DynamicArray */
typedef struct dynamicArr_t {
    char *_array;
    unsigned _size, _capacity;
} DynamicArray;

/* Definisi fungsi */
//fungsi untuk inisialisasi
void dArray_init(DynamicArray *darray) {
    darray->_capacity = 2u;
    darray->_size = 0u;
    darray->_array = (char*) malloc(sizeof(char) * 2);
}

//fungsi untuk mengecek apakah array empty atau kosong
bool dArray_isEmpty(DynamicArray *darray) {
    return (darray->_size == 0);
}

//fungsi untuk mengecek apakah array full
bool dArray_isFull(int data) {
    return (data <= 100);
}

//fungsi untuk pushback atau menambahkan data
void dArray_pushBack(DynamicArray *darray, char value) {
    if (dArray_isFull(darray->_size)) {
        if (darray->_size + 1 > darray->_capacity) {
            unsigned it;
            darray->_capacity *= 2;
            char *newArray = (char*) malloc(sizeof(char) * darray->_capacity);

            for (it=0; it < darray->_size; it++)
                newArray[it] = darray->_array[it];
            
            char *oldArray = darray->_array;
            darray->_array = newArray;
            free(oldArray);
        }
        darray->_array[darray->_size++] = value;
    }
}

//fungsi untuk mendapatkan elemen atau data di index tertentu
int dArray_getAt(DynamicArray *darray, unsigned index) {
    if (!dArray_isEmpty(darray)) {
        if (index >= darray->_size)
            return darray->_array[darray->_size-1];
        else
            return darray->_array[index];
    }
}

//define penyingkatan
#define d_init dArray_init
#define d_isEmpty dArray_isEmpty
#define d_isFull dArray_isFull
#define d_pushBack dArray_pushBack
#define d_popBack dArray_popBack
#define d_back dArray_back
#define d_front dArray_front
#define d_setAt dArray_setAt
#define d_getAt dArray_getAt

//main program
int main() {
    //deklarasi variabel
    int i;
    // Membuat objek DynamicArray
    DynamicArray myArray;

    // Melakukan Inisialisasi
    d_init(&myArray);

    // Operasi
    d_pushBack(&myArray, 'S');
    d_pushBack(&myArray, 'i');
    d_pushBack(&myArray, 's');
    d_pushBack(&myArray, 't');
    d_pushBack(&myArray, 'e');
    d_pushBack(&myArray, 'm');
    d_pushBack(&myArray, ' ');
    d_pushBack(&myArray, 'D');
    d_pushBack(&myArray, 'B');

    //print data atau seluruh elemen
    for (i = 0; i < myArray._size; i++) {
        printf("%c", d_getAt(&myArray, i));
    }
    
    //print panjang string
    printf("\nString Length : %d \n", myArray._size);
    //print kapasitas array 
    printf("Capacity of Array : %d \n", myArray._capacity);
    return 0;
}