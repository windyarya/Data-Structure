/*Tugas Praktikum Struktur Data - Modul 0 Soal 2
I Putu Windy Arya Sagita - 5027201071*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Struktur DynamicArray */
typedef struct dynamicArr_t {
    int *_array;
    unsigned _size, _capacity;
} DynamicArray;

/* Definisi fungsi */
//fungsi untuk inisialiasi
void dArray_init(DynamicArray *darray) {
    darray->_capacity = 2u;
    darray->_size = 0u;
    darray->_array = (int*) malloc(sizeof(int) * 2);
}

//fungsi untuk mengecek apakah array kosong atau tidak
bool dArray_isEmpty(DynamicArray *darray) {
    return (darray->_size == 0);
}

//fungsi untuk melakukan pushback/menambahkan data baru
void dArray_pushBack(DynamicArray *darray, int value) {
    if (darray->_size + 1 > darray->_capacity) {
        unsigned _it;
        darray->_capacity *= 2;
        int *newArray = (int*) malloc(sizeof(int) * darray->_capacity);

        for (_it=0; _it < darray->_size; _it++) {
            newArray[_it] = darray->_array[_it];
        }
        int *oldArray = darray->_array;
        darray->_array = newArray;
        free(oldArray);
    }
    darray->_array[darray->_size++] = value;
}

//fungsi untuk melakukan popback/mendelete data terakhir
void dArray_popBack(DynamicArray *darray) {
    if (!dArray_isEmpty(darray)) darray->_size--;
    else return;
}

//fungsi untuk mengubah data di suatu index
void dArray_setAt(DynamicArray *darray, unsigned index, int value) {
    if (!dArray_isEmpty(darray)) 
    {
        if (index >= darray->_size)
            darray->_array[darray->_size-1] = value;
        else
            darray->_array[index] = value;
    }
}

//fungsi untuk mendapatkan data di suatu index
int dArray_getAt(DynamicArray *darray, unsigned index) {
    if (!dArray_isEmpty(darray)) 
    {
        if (index >= darray->_size)
            return darray->_array[darray->_size-1];
        else
            return darray->_array[index];
    }
}

//fungsi untuk menambahkan elemen baru ke array
void dArray_insertAt(DynamicArray *darray, unsigned index, int value) {
	int i;      //deklarasi variabel
    unsigned n;
    //cek apakah array empty atau tidak
    if (!dArray_isEmpty(darray)) {
        //cek apakah index yang akan kita tambahkan melebihi kapasitas array
        if (index < darray->_capacity) {
            //cek apakah size array melebihi kapasitas
            if (darray->_size + 1 > darray->_capacity) {
                darray->_capacity *= 2;
                int *newArray = (int*) malloc(sizeof(int) * darray->_capacity);

                for (n = 0; n < darray->_size; n++) {
                    newArray[n] = darray->_array[n];
                }
                int *oldArray = darray->_array;
                darray->_array = newArray;
                free(oldArray);
            }

            for (i = darray->_size; i > index; i--) {
                darray->_array[i] = darray->_array[i-1];
            }
            darray->_array[index] = value;
            darray->_size++;
        }
    }
}

//fungsi untuk meremove elemen dari array
void dArray_removeAt(DynamicArray *darray, unsigned index) {
	int i;
    if (!dArray_isEmpty(darray)) {
        if (index < darray->_size) {
            for (i = index; i < darray->_size - 1; i++) {
                darray->_array[i] = darray->_array[i+1];
            }
            darray->_size--;
        }
    }
}

/* Mempersingkat penulisan kode */
#define d_init dArray_init
#define d_isEmpty dArray_isEmpty
#define d_pushBack dArray_pushBack
#define d_popBack dArray_popBack
#define d_setAt dArray_setAt
#define d_getAt dArray_getAt
#define d_insertAt dArray_insertAt
#define d_removeAt dArray_removeAt

/* Fungsi utama main() */
int main() 
{
    //deklarasi variabel
	int m;
    // Membuat objek DynamicArray
    DynamicArray myArray;

    // Melakukan Inisialisasi
    d_init(&myArray);

    //pushback untuk menambahkan data
    d_pushBack(&myArray, 17);
    d_pushBack(&myArray, 36);
    d_pushBack(&myArray, 41);
    d_pushBack(&myArray, 55);
    d_pushBack(&myArray, 73);
    //print array awal
    printf("The initial array : ");
	for (m = 0; m < myArray._size; m++) {
        printf("%d ", d_getAt(&myArray, m));
    }
    printf("\n");

    //Memasukan data pada indeks ke-n dan print array setelah ditambahkan data
    d_insertAt(&myArray, 1, 21);
    d_insertAt(&myArray, 4, 45);
    printf("The array after inserting new data : ");
	for (m = 0; m < myArray._size; m++) {
        printf("%d ", d_getAt(&myArray, m));
    }
    printf("\n");

    //Meremove data pada indeks ke-n
    d_removeAt(&myArray, 3);

    // Menampilakn size
    printf("Size of Array : %d \n", myArray._size);
    // Menampilkan capacity
    printf("Capacity of Array : %d \n", myArray._capacity);

    // Menampilkan array akhir
    printf("The final array : ");
    for (m = 0; m < myArray._size; m++) {
        printf("%d ", d_getAt(&myArray, m));
    }
    
    return 0;
}