#include "sll.h"

int sl_delete_list(Slist **head)
{
    // Validation
    if (*head == NULL)
    {
        return FAILURE;
    }

    // Traverse through all the nodes and free the memory
    Slist *temp;
    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->link;
        free(temp);
    }

    // Set the head to NULL after deleting the list
    *head = NULL;
    return SUCCESS;
}