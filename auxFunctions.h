/* This file contains the auxiliar funtions used in the main
 * file: the compare funtion, used in the qsort function;
 * the binarySearch funtion and the duplicateVector. */

#ifndef AUX_FUNCTIONS_H
#define AUX_FUNCTIONS_H


/* Function used by qsort to compare integers */
int compare (const void *a, const void *b);


/* Recieve a vector of integers, its size and the number that
 * is searching for. Returns the index of the number on the vector,
 * or -1 if the vector is not the vector.*/
int binarySearch (int *v, int size, int num);

/* Recieve a vector and its size. Returns a new vector
 * which is a clone from the recieved vector. */
int* dupVector (int* v, uint size);

/* Recieve 2 vectors of integers with the same size.
 * Return 1, if the vectors are equal, 0 otherwise*/
int cmpVector (int *v, int *w, uint size); 


uint reallocVector (int* v, uint size);

#endif
