#include "sll.h"

/* Function to create the loop */
int create_loop(Slist **head, data_t data)
{
    /* If the list is empty */
    if (*head == NULL)
    {
        return LIST_EMPTY;
    }

    /* Find the node with the given data */
    Slist *temp = *head;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            break;
        }
        temp = temp->link;
    }

    /* If the node with the given data is not found */
    if (temp == NULL)
    {
        return DATA_NOT_FOUND;
    }

    /* Find the last node of the list */
    Slist *temp1 = *head;
    while (temp1->link != NULL)
    {
        temp1 = temp1->link;
    }

    /* Create the loop */
    temp1->link = temp;

    return SUCCESS;
}