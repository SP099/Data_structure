#include"hash.h"

int search_HT(hash_t *arr, int data, int size)
{
    // Calculate the index of the element in the hash table
    int index = data % size;
    
    // Check if the data value is in the main hash table slot
    if(arr[index].value == data)
    {
        return DATA_FOUND;
    }
    
    
    // Check the linked list of the corresponding hash table slot
    hash_t *temp = arr[index].link;
    while(temp != NULL)
    {
        if(temp->value == data)
        {
            return DATA_FOUND;
        }
        temp = temp->link;
    }
    
    // The data value is not found in the hash table
    return DATA_NOT_FOUND;
}