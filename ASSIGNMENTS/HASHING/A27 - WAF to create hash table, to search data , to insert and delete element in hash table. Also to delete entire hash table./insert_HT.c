#include"hash.h"

int insert_HT(hash_t *arr, int element, int size)
{
    // Calculate the index of the element in the hash table
    int index = element % size;
    
    // If the index is empty, insert the element at that index
    if(arr[index].value == -1)
    {
        arr[index].value = element;
        return SUCCESS;
    }
    
    // Allocate memory for the new node
    hash_t *new = malloc(sizeof(hash_t));
    
    // Check for memory allocation failure
    if(new == NULL)
    {
        return FAILURE;
    }
    new->value = element;   // Set the value of the new node to the element
    
    new->link = NULL;       // Set the link of the new node to NULL
    
    new->index = index;     // Set the index of the new node to the calculated index
    
    if(arr[index].link ==NULL)
    {
        arr[index].link = new;
        return SUCCESS;
    }
    
    // Start at the head of the linked list
    hash_t *temp = arr[index].link;
    
    
    // Iterate through the linked list until the last node is found
    while(temp->link)
    {
        temp = temp->link;  
    }
    temp->link = new;  // Add the new node to the end of the linked list
    return SUCCESS;
}