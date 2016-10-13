/* This file contains the auxiliar funtions used in the main
 * file: the compare funtion, used in the qsort function;
 * the binarySearch funtion and the duplicateVector. */

#include "types.h"
#include <stdlib.h>

/* Function used by qsort to compare integers */
int compare (const void *a, const void *b) {
    int cmp;
    
    if (*(int*)a <  *(int*)b) cmp = -1;
    if (*(int*)a == *(int*)b) cmp =  0;
    if (*(int*)a >  *(int*)b) cmp =  1;

    return cmp;

}

/* Recieve a vector of integers, its size and the number that
 * is searching for. Returns the index of the number on the vector,
 * or -1 if the vector is not the vector.*/
int binarySearch (int *v, int size, int num) {
    int mid = size/2;
    uint beg, end;
    
    beg = 0;
    end = size - 1;
    mid = size/2;
    
    while (v[mid] != num && beg <= end) {
        if (v[mid] < num) 
            beg = mid + 1;

        else
            end = mid - 1;
        
        mid = (beg + end)/2;
    }

    if (v[mid] == num) return mid;
    else return -1;
}


/* Recieve a vector and its size. Returns a new vector
 * which is a clone from the recieved vector. */
int* dupVector (int* v, uint size) {
    uint ind;
    int* new;
    
    new = malloc(size * sizeof(int));
    
    for (ind = 0; ind < size; ind++)
        new[ind] = v[ind];

    return new;
}

/* Recieve 2 vectors of integers with the same size.
 * Return 1, if the vectors are equal, 0 otherwise*/
int cmpVector (int *v, int *w, uint size) {
    uint ind;

    for (ind = 0; ind < size; ind++)
        if (v[ind] != w[ind]) 
            return 0;

    return 0;
}

uint reallocVector (int* v, uint size) {
    
    int* aux;

    aux = dupVector(v, size);

    free(v);
    v = malloc(2 * size * sizeof(int));
    v = dupVector(aux, size);
    free(aux);

    size *= 2;
    
    return size;
}
