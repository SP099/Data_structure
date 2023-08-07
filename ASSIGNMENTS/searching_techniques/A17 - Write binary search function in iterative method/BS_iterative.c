/*
Name       : Sushant Patil
Date       : 18/04/2023
Description: Write binary search function in iterative method
*/

#include "main.h"

/* Function for binary search using iterations */
data_t binarySearch_iterative(data_t *arr, data_t size, data_t key)
{
    int start = 0, end = (size - 1), mid; // initialize start and end indices
    while(start <= end) // loop until start index is less than or equal to end index
    {
        mid = (start + end) / 2; // calculate the middle index
        if(arr[mid] == key) // if key is found at middle index, return it
        {
            return mid; 
        }
        else if(arr[mid] > key) // if key is smaller than middle element, search the left half
        {
            end = mid - 1;
        }
        else // if key is greater than middle element, search the right half
        {
            start = mid + 1;
        }
    }
    return DATA_NOT_FOUND; // if key is not found, return a predefined constant
}
