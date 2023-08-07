#include "sll.h"

int sl_delete_element(Slist **head, data_t data)
{
    // Check if the list is empty
    if (*head == NULL)
    {
        return FAILURE;
    }

    Slist *temp = *head;
    Slist *prev = NULL;

    // Search for the node with the given data
    while (temp != NULL && temp->data != data)
    {
        prev = temp;
        temp = temp->link;
    }

    // If data not found
    if (temp == NULL)
    {
        return DATA_NOT_FOUND;
    }

    // If first node contains the data
    if (temp == *head)
    {
        *head = temp->link;
    }
    // If an intermediate node contains the data
    else
    {
        prev->link = temp->link;
    }

    free(temp);

    return SUCCESS;
}