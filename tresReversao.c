#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "auxFunctions.h"

/* Recive a vector of integers with even size, returns 1 if
 * the vecetor is solvable, retruns 0 otherwise. */
int evenPossible (int *v, int* sorted, uint size) {

    uint ind, inds, dist;
    
    /*Worst case: O(nlogn) || Best case: O(logn)*/
    for (ind = 0; ind < size; ind++) {
        inds = binarySearch(v, size, v[ind]); /*O(logn)*/
        dist = abs(ind - inds);
        if (dist%2) return 0;
    }

    free(sorted);

    return 1;
}

/* The function recieve a vector of integers, its size and the 
 * index of the element it will analyze.
 * Return 0, if the element is out of order. Return 1, otherwise. */
uint checkOrder (int *v, uint size, uint ind) {

    int dif;
    dif = size - ind - 1;
    
    /* Compare v[ind] with next 2 elements of the vector. */
    if (dif < 2) {
        
        /* The v[ind] is either the last or before last element
         * of the vector. */   
        if (v[ind] > v[ind + dif]) 
            return 0;
    }

    else {
        
        if (v[ind] > v[ind + 1])
            return 0;
        
        if (v[ind] > v[ind + 2])
            return 0;
    }
    
    /* Compare v[ind] with the last 2 elements before him of
     * the vector. */
    if (ind < 2) {
        
        /*The v[ind] is either the first or second element
         * of the vector. */
        if (v[0] > v[ind])
            return 0;
    }

    else {
        
        if (v[ind] < v[ind - 1])
            return 0;
        
        if (v[ind] < v[ind - 2])
            return 0;
    }
    
    return 1;
}

/* Recieve a vector of integers, an index and the vector size,
 * and make the reversion starting from the v[ind] */
void reversion (int *v, uint size, uint ind) {
    
    int aux = v[ind];    
    uint ind_nt = (ind + 2)%size;
    
    v[ind] = v[ind_nt];
    v[ind_nt] = aux;

}

void orderVector (int *v, uint size) {
    /* indp --> path's index
     * sizep --> path's size*/
    uint ind, indp, sizep; 
    int *sorted, *path;

    indp = 0;
    sizep = size;
    
    path = malloc(size * sizeof(uint));

    sorted = dupVector(v, size); /*O(n)*/
    qsort (sorted, size, sizeof(int), compare); /*O(nlogn)*/
    
    if (size%2 == 0)
        if (evenPossible(v, sorted, size) == 0) {
            printf("Nao e possivel\n");
            return;
        }
    
    while(cmpVector(v, sorted, size) == 0)
        for (ind = 0; ind < size; ind++)
            if (checkOrder(v, size, ind) == 0) {
                reversion(v, size, ind);
                
                if (indp == sizep)
                    reallocVector(path, sizep);

                path[indp] = ind;
                indp++;
            }
    
    free(sorted);
    sorted = NULL;
    free(path);
    path = NULL;

}

int main () {
    uint size, i;
    int *v;
    
    if (scanf("%u", &size));
    
    v = malloc(size * sizeof(int));

    for (i = 0; i < size; i++)
        if (scanf("%d", &v[i]));
    
    orderVector(v, size);
    
    free(v);
    v = NULL;

    return(0);
}   
