#include "main.h"
void swap(data_t *, data_t *) ;

data_t selection(data_t *arr, data_t size )
{
    // Loop over each element in the array
    for (int j = 0; j < size - 1; j++) 
    {
        // Find the smallest element in the unsorted portion of the array
        int current_min = j;
        for (int current_item = j + 1; current_item < size; current_item++) 
        {
            if (arr[current_item] < arr[current_min]) 
            {
                current_min = current_item;
            }
        }
        
        // Swap the smallest element with the first unsorted element
        if (current_min != j) 
        {
            swap(&arr[j], &arr[current_min]);
        }
    }
    return 1;
}

void swap(data_t *a, data_t *b) 
{
  data_t temp = *a;
  *a = *b;
  *b = temp;
}
