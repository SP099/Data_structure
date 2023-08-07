#include "dll.h"

int dl_delete_list(Dlist **head, Dlist **tail)
{
    // If the list is empty, return FAILURE 
    if(*head == NULL)
        return FAILURE;
    // Store the current head node in a temporary variable
    Dlist *temp = *head;

    while(temp)
    {
        // If there is only one node in the list, delete it and set both head and tail to NULL
        if(*head == *tail)
        {
            free(*head);
            *head = NULL;
            *tail = NULL;
            return SUCCESS; // Return SUCCESS constant if deletion was successful
        }

        // Otherwise, delete the current node and update the head pointer
        *head =(*head)->next; // Set the head pointer to point to the next node in the list
        free((*head)->prev); // Free the memory allocated to the current node
        (*head)->prev =NULL; // Set the prev pointer of the new head node to NULL
        temp = temp->next; // Move to the next node in the list
    }
    return SUCCESS; // Return SUCCESS constant if deletion was successful
}