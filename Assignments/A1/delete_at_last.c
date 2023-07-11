#include "sll.h"

int sl_delete_last(Slist **head)
{
    // Validation
    if (*head == NULL)
    {
        return FAILURE;
    }

    // Check if the head is the only node
    if ((*head)->link == NULL)
    {
        free(*head);
        *head = NULL;
        return SUCCESS;
    }

    // Traverse till the second to last node
    Slist *temp = *head;
    while (temp->link->link != NULL)
    {
        temp = temp->link;
    }

    // Free the last node and set the next of second to last node to NULL
    free(temp->link);
    temp->link = NULL;
    return SUCCESS;
}