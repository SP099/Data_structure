#include "main.h"
void swap(int *a, int *b);

/* Function to partition the array */
int partition(int *arr, int first, int last)
{
    // initialize pivot, p, q
    int pivot = first, p = first + 1, q = last;
    
    // loop until p and q cross each other
    while(p <= q)
    {
        // find the next element larger than pivot from left
        while(p <= q && arr[p] < arr[pivot])
        {
            p++;
        }
        
        // find the next element smaller than pivot from right
        while(p <= q && arr[q] >= arr[pivot])
        {
            q--;
        }
        
        // swap the elements at p and q
        if(p < q)
        {
            swap(&arr[p], &arr[q]);
        }
    }
    
    // swap the pivot with the element at q
    swap(&arr[pivot], &arr[q]);
    
    // return the index of pivot after partitioning
    return q;
}

/* Function to swap two elements */
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
