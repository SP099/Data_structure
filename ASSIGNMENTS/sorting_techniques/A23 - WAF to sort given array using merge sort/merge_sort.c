/*
Name         : Sushant Patil
Date         : 22/04/2023
Description  : WAF to sort given array using merge sort
*/

#include "main.h"


int merge_sort(int *array, int narray)
{
    // If the size of the array is 1, it is already sorted
    if(narray == 1)
    {
        return SUCCESS;
    }

    // Compute the midpoint of the array
    int mid = narray / 2, i;
    
    // Allocate memory for the left half of the array
    int *left =  malloc(mid * sizeof(int));
    
    // If the allocation fails, return FAILURE
    if(left == NULL)
    {
        return FAILURE;
    }
    
    // Copy the elements of the original array up to the midpoint into the left array
    for(i = 0; i < mid; i++)
    {
        left[i] = array[i];
    }
    
    // Allocate memory for the right half of the array
    int *right =  malloc((narray - mid) * sizeof(int));
    
    // If the allocation fails, return FAILURE
    if(right == NULL)
    {
        return FAILURE;
    }
    
    // Copy the elements of the original array from the midpoint to the end into the right array 
	for (i = mid; i < narray; i++)
	{
		right[i-mid] = array[i];
	}
	
	// Recursively call merge_sort() on the left and right halves of the array
	merge_sort(left, mid);
	merge_sort(right, (narray - mid));

    // Merge the left and right halves of the array into a sorted array
    merge(array, narray, left, mid, right, (narray - mid));
    
    // Free the memory allocated for the left and right arrays
    free(left);
	free(right); 
	return SUCCESS;
}
