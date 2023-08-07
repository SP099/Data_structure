#include "dll.h"
int dl_delete_element(Dlist **head, Dlist **tail, int data)
{	
    // If the list is empty
    if (*head == NULL) 
    {
        return LIST_EMPTY;
    }

    Dlist *temp = *head;

    // If the first node has the data to be deleted
    if (temp->data == data)
    {
        *head = temp->next;
        if (*head != NULL) 
        {
            (*head)->prev = NULL;
        }
        else 
        {
            *tail = NULL;
        }
        free(temp);
        return SUCCESS;
    }

    // If the node to be deleted is the tail node
    if ((*tail)->data == data)
    {
        temp = *tail;
        *tail = temp->prev;
        if (*tail != NULL)
        {
            (*tail)->next = NULL;
        }
        else
        {
            *head = NULL;
        }
        free(temp);
        return SUCCESS;
    }

    // If the node to be deleted is neither the head nor the tail node
    while (temp != NULL && temp->data != data)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return DATA_NOT_FOUND;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    return SUCCESS;
}
