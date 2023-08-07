#include "main.h"

/* Function to sort the array in quick sort method */
int quick_sort( int *arr, int first, int last )
{
    // check if the sub-array has more than one element
    if (first < last) 
    {
        // partition the sub-array
        int index = partition(arr, first, last);
        
        // recursively sort the left sub-array
        quick_sort(arr, first, index - 1);
        
        // recursively sort the right sub-array
        quick_sort(arr, index + 1, last);
    }
    
    // return 1 to indicate that the function has completed successfully
    return 1;
}
