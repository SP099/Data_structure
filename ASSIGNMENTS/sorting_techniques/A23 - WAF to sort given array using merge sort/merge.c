#include "main.h"


void merge(int *array, int narray, int *left, int nleft, int *right, int nright)
{
    // Initialize variables for array indices
    int i, j, k;
    i = j = k = 0;
    
    // Compare elements of the left and right arrays and merge them into the final sorted array
    while(i < nleft && j < nright)
    {
        if(left[i] < right[j])
        {
            array[k] = left[i];
            i++;
            k++;
        }
        else
        {
            array[k] = right[j];
            j++;
            k++;
        }
    }
    
    // Add the remaining elements of the right array to the final sorted array
    while(j < nright)
	{
		array[k++] = right[j++];
	}
	
	// Add the remaining elements of the left array to the final sorted array
	while(i < nleft)
	{
		array[k++] = left[i++];
	}
}
