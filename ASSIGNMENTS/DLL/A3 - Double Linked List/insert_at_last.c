#include "dll.h"

int dl_insert_last(Dlist **head, Dlist **tail, int data)
{
    // Allocate memory for a new node
    Dlist *new = malloc(sizeof(Dlist));
    
    // Check if memory allocation was successful
    if(new == NULL)
    {
        return FAILURE;
    }
    
    // Initialize the data and pointer fields of the new node
    new->prev = NULL;
    new->data = data;
    new->next = NULL;
    
    // If the list is empty, set head and tail pointers to the new node
    if(*head == NULL)
    {
        *head = new;
        *tail = new;
        return SUCCESS; // Return SUCCESS constant if insertion was successful
    }
    
    // Otherwise, insert the new node at the end of the list
    (*tail)->next = new;
    new->prev = *tail;
    *tail = new;
    return SUCCESS; // Return SUCCESS constant if insertion was successful
}