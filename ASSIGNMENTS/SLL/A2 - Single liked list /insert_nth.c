#include "sll.h"

int sl_insert_nth(Slist **head, data_t data, data_t n)
{
    Slist *new = NULL;
    Slist *temp = *head;
    int count = 1;

    /* Create new node */
    new = (Slist*)malloc(sizeof(Slist));
    if (new == NULL)
    {
        return FAILURE;
    }
    new->data = data;
    new->link = NULL;

    /* Insert at first position */
    if (n == 1)
    {
        new->link = *head;
        *head = new;
        return SUCCESS;
    }

    /* Check if the list is empty */
    if (*head == NULL)
    {
        free(new);
        return LIST_EMPTY;
    }

    /* Traverse the list to find the nth position */
    while (temp != NULL && count < n-1)
    {
        temp = temp->link;
        count++;
    }

    /* If nth position is not found */
    if (temp == NULL)
    {
        free(new);
        return POSITION_NOT_FOUND;
    }

    /* Insert the new node at nth position */
    new->link = temp->link;
    temp->link = new;

    return SUCCESS;
}