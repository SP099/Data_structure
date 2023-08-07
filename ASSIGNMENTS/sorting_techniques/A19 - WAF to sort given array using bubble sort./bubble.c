/* 
Name         : Sushant Patil
Date         : 18/04/2023
Description  : WAF to sort given array using bubble sort.
*/

#include "main.h"

data_t bubble(data_t *arr, int size )
{
    int i,j,temp,flag;
    
    // Iterate through the entire array
    for(i = 0; i < size - 1; i++)
    {
        flag = 0;
        // Iterate from the beginning of the array to the unsorted part of the array
        for(j = 0;j < (size - i - 1); j++)
        {
            // If the current element is greater than the next element, swap them
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                
                // Set flag to 1 to indicate a swap was made
                flag = 1;
            }
        }
        
        // If no swaps were made in the inner loop, the array is already sorted
        if(flag == 0)
        {
            break;
        }
    }
}
