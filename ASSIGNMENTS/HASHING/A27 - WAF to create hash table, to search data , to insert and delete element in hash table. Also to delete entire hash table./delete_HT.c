#include"hash.h"

int destroy_HT(hash_t *arr, int size)
{
    int index;
    
    // Loop through each element in the hash table
    for (index = 0; index < size; index++)
    {
        // Check if the current element is empty 
        if (arr[index].value == -1)
        {
            // If the current element is empty, skip it and continue to the next element
            continue;
        }
        
        // If the current element is not empty, set its value to -1 to mark it as empty
        arr[index].value = -1;
        
        // Free the linked list of nodes (if any) associated with the current element
        hash_t *temp = arr[index].link;
        while (temp != NULL)
        {
            hash_t *next = temp->link;
            free(temp);
            temp = next;
        }
        
        // Set the link of the current element to NULL
        arr[index].link = NULL;
    }
    return SUCCESS;
}