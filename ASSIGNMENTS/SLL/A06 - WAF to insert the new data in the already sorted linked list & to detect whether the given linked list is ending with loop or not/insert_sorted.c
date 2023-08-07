#include "sll.h"

/* Function for insert the number in sorted linked list */
int insert_sorted( Slist **head, data_t data) 
{ 
    /* Create a new node */
    Slist *new = (Slist *)malloc(sizeof(Slist));
    if (new == NULL)
    {
        return FAILURE;
    }
    new->data = data;
    new->link = NULL;

    /* If the list is empty */
    if (*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }

    /* If new data is smaller than the first node */
    if (data < (*head)->data)
    {
        new->link = *head;
        *head = new;
        return SUCCESS;
    }

    /* Find the node after which the new node is to be inserted */
    Slist *current = *head;
    while (current->link != NULL && current->link->data < data)
    {
        current = current->link;
    }

    /* Insert the new node */
    new->link = current->link;
    current->link = new;

    return SUCCESS;
} 