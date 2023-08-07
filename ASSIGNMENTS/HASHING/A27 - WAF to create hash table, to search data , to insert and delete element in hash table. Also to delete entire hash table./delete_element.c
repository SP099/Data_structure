#include"hash.h"

int delete_element(hash_t *arr, int data, int size)
{
    // compute the hash value of the data
    int i = data % size;
    
    // declare pointers to hash_t nodes
    hash_t *temp, *prev;
    
    // CASE 1: if the element to be deleted is the only element at the computed hash value in the hash table
    if (arr[i].value == data && arr[i].link == NULL) 
    {
        arr[i].value = -1; // set the value to -1
        return SUCCESS; // return success
    }
    
    // CASE 2: if the element to be deleted is the first element in a linked list at the computed hash value
    if (arr[i].value == data && arr[i].link != NULL) 
    {
        temp = arr[i].link; // store the next node in a temporary pointer
        
        arr[i].value = temp->value; // replace the value with the value of the next node
        
        arr[i].link = temp->link; // update the link
        
        free(temp); // free the memory of the element to be deleted
        
        return SUCCESS; 
    }
    
    // CASE 3: if the element to be deleted is in the middle or end of a linked list at the computed hash value
    
    temp = arr[i].link; // start at the first node in the list
    
    prev = NULL; // set the previous node pointer to NULL
    
    while (temp != NULL) // iterate through the list
    {
        if (temp->value == data) // if the node contains the element to be deleted
        {
            if (prev == NULL) // if the node to be deleted is the first node in the list
            {
                arr[i].link = temp->link; // update the link of the hash table
            } 
            else 
            {
                prev->link = temp->link; // update the link of the previous node
            }
            free(temp); // free the memory of the element to be deleted
            return SUCCESS; // return success
        }
        prev = temp; // move the previous node pointer to the current node
        temp = temp->link; // move to the next node in the list
    }
    
    return DATA_NOT_FOUND; // if the element to be deleted is not found, return data not found
}