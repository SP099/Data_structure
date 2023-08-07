/*
Name          : Sushant Patil
Date          : 18/04/2023
Description   : WAF to sort given array using insertion sort
*/

#include "main.h"

data_t insertion(data_t *arr, data_t size)
{
    int i, j, key;

    // start from the second element
    for (i = 1; i < size; i++) 
    {  
        key = arr[i];
        j = i - 1;

        // move the elements that are greater than key to one position ahead
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        // insert the key in its correct position
        arr[j + 1] = key;  
    }

    return 1;
}
