#include "dll.h"

int dl_delete_last(Dlist **head, Dlist **tail)
{
    // If the list is empty, return FAILURE constant
    if(*head == NULL)
    {
        return FAILURE;
    }
    
     // If there is only one node in the list, delete it and set both head and tail to NULL
    if(*head == *tail)
    {
        free(*head);
        *head = NULL;
        *tail = NULL;
        return SUCCESS; // Return SUCCESS constant if deletion was successful
    }
    
    // Otherwise, delete the last node and update the tail pointer
    *tail = (*tail)->prev;
    free((*tail)->next);
    (*tail)->next = NULL;
    return SUCCESS;   // Return SUCCESS constant if deletion was successful
}