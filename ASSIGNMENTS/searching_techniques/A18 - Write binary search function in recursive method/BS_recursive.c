#include "main.h"

/* Function to search the element using binary search */
data_t binarySearch_recursive(data_t *arr, data_t size, data_t key, data_t first, data_t last)
{
    int mid; 

    if(first <= last) // check if the search range is valid
    {
        mid = (first + last) / 2; // find the middle index

        if(arr[mid] == key) 
        {
            return mid; // return the index of the element if found
        }
        else if(arr[mid] > key) 
        {
            // adjust the search range to the left half
            last = mid - 1; 
        }
        else 
        {
            // adjust the search range to the right half
            first = mid + 1; 
        }
        
        // recursive call with updated search range
        return binarySearch_recursive(arr,  size,  key,  first,  last); 
    }

    // if key is not found, return a predefined constant
    return DATA_NOT_FOUND; 
}
