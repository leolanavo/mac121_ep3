#include <stdio.h>
#include <stdlib.h>
#include "types.h"

/* The function receives a vector of integers, its size and the 
 * index of the element it will analyze.
 * Return 0, if the element is out of order. Return 1, otherwise. */
uint checkOrder (int *v, uint size, int ind, uint next) {

    if (ind > 0 && next && v[ind] < v[ind - 1])
        return 0;
        
    if (ind > 1 && v[ind] < v[ind - 2])
        return 0;
    
    if (ind < size - 1 && next && v[ind] > v[ind + 1])
        return 0;
        
    if (ind < size - 2 && v[ind] > v[ind + 2])
        return 0;
    
    return 1;
}

/* Receives a vector of integers, an index and the vector size,
 * and make the reversion between v[ind] and v[ind + 2] */
void reversion3 (int *v, uint size, int ind) {
    
    int aux = v[ind];    
    uint ind_nt = (ind + 2)%size;
    
    v[ind] = v[ind_nt];
    v[ind_nt] = aux;

}

/* Receives a vector of integers, an index and the vector size,
 * and make the reversion between v[ind] and v[ind + 1] */
void reversion2 (int *v, uint size, int ind) {
    
    /* fwd is the number of times v[ind+1] will be moved foward
     * and bwd is the times v[ind] will be moved backwards. 
     * track is the index where v[ind + 1] will be after moving
     * v[ind] bwd times. */
    uint fwd, bwd;
        
    int track;

    track = 0; 
    bwd = (size - 1)/2;
    fwd = bwd - 1;

    while (bwd > 0) {
        
        ind = ind - 2;
        
        /* In case indp is negative*/
        if (ind < 0)
            ind += size;
        else 
            ind = ind%size;
        
        reversion3(v, size, ind);
        
        if (bwd == 1)
            track = ind;
        
        bwd--;
        printf("%d\n", ind);
    }
    
    ind = track;
    
    while (fwd > 0) {
        ind = (ind + 2)%size;
        reversion3(v, size, ind);
        fwd--;
        printf("%d\n", ind);
    }

}

/* Receives a vector of integers with even size, returns 1 if
 * the vector is solvable, returns 0 otherwise. And sorts the
 * vector. */
void evenVector (int *v, uint size) {
    
    uint beg, end, next, indp;
    int *path, ind;

    path = malloc(size * sizeof(int));
    for (indp = 0; indp < size; indp++)
        path[indp] = -1;

    beg = indp = next = 0;
    end = size - 1;

    /*BubbleSort --> O(n²)*/
    while (beg < end) {
        for (ind = 0; ind < end; ind++) {
            if (checkOrder(v, size, ind, next) == 0) {                
                reversion3(v, size, ind);
                path[indp] = ind;
                indp++;
            }
        }
        end--;
    }

    next = 1;       
    for (ind = 0; ind < size - 2; ind++)
        if (checkOrder(v, size, ind, next) == 0) {
            printf("Nao e possivel\n");
            free(path);
            path = NULL;
            return;
        }

    for (indp = 0; path[indp] != -1 && indp < size; indp++)
        printf("%d\n", path[indp]);

    free(path);
    path = NULL;
    return;
        
}

/* Receives a vector of integers with odd size. And
 * sorts the vector. */
void oddVector (int *v, uint size) {
    
    int ind;
    uint order, next, ind1, ind2;
    
    order = 0;
    next = 1;

    while (order == 0) {
        order = 1;
        for (ind = 0; ind < size; ind++) {
            if (checkOrder(v, size, ind, next) == 0) {
                ind1 = ind + 1;
                ind2 = ind + 2;

                if ((ind1 < size && v[ind] >= v[ind1]) 
                        && (ind2 < size && v[ind] >= v[ind2])) {
                    reversion3(v, size, ind);
                    printf("%d\n", ind);
                }
                
                else {
                    reversion2(v, size, ind);
                }
                order = 0;
            }
        }
    }
    return;
}

int main () {
    uint size, ind;
    int *v;
    
    if (scanf("%u", &size));
    
    v = malloc(size * sizeof(int));

    for (ind = 0; ind < size; ind++)
        if (scanf("%d", &v[ind]));
    
    if (size%2)
        oddVector (v, size);
    else
        evenVector (v, size);
 
    free(v);
    v = NULL;

    return(0);
}   
