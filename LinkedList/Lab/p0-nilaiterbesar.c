#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Struktur ADT DynamicArray

typedef struct dynamicarr_t {
    int *_arr;
    unsigned _size, _capacity;
} DynamicArray;

void dArray_init(DynamicArray *darray)
{
    darray->_capacity = 2u;
    darray->_size = 0u;
    darray->_arr = (int*) malloc(sizeof(int) * 2);
}

bool dArray_isEmpty(DynamicArray *darray) {
    return (darray->_size == 0);
}

void dArray_pushBack(DynamicArray *darray, int value)
{
    if (darray->_size + 1 > darray->_capacity) {
        unsigned it;
        darray->_capacity *= 2;
        int *newArr = (int*) malloc(sizeof(int) * darray->_capacity);

        for (it=0; it < darray->_size; ++it)
            newArr[it] = darray->_arr[it];
        
        int *oldArray = darray->_arr;
        darray->_arr = newArr;
        free(oldArray);
    }
    darray->_arr[darray->_size++] = value;
}

int dArray_getAt(DynamicArray *darray, unsigned index)
{
    int bil;
    if (!dArray_isEmpty(darray)) {
        if (index >= darray->_size)
            bil = darray->_arr[darray->_size-1];
        else
            bil = darray->_arr[index];
    }
    return bil;
}

int main() {
    int n;
    DynamicArray myArray;

    dArray_init(&myArray);

    do
    {
        scanf("%d", &n);
        if (n != 0)
        {
            dArray_pushBack(&myArray, n);
        }
    } while (n!= 0);
    
    int i;
    int temp1, temp2;
    temp1 = dArray_getAt(&myArray, 0);
    for (i = 1; i < myArray._size; i++)
    {
        temp2 = dArray_getAt(&myArray, i);
        if (temp1 < temp2) {
            temp1 = temp2;
        }
    }

    printf("%d", temp1);
    return 0;    
    
}