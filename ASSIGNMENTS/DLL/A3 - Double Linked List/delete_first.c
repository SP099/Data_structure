#include "dll.h"

int dl_delete_first(Dlist **head, Dlist **tail)
{
    // If the list is empty, return FAILURE 
    if(*head == NULL)
    {
        return FAILURE;
    }
    
    // If there is only one node in the list, delete it and set both head and tail to NULL
    if((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        *tail = NULL;
        return SUCCESS; // Return SUCCESS constant if deletion was successful
    }
    
    // Otherwise, delete the first node and update the head pointer
    Dlist *temp = *head;
    *head = temp->next;
    free(temp);
    (*head)->prev = NULL;;
    return SUCCESS;   // Return SUCCESS constant if deletion was successful
}