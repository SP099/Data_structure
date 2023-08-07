#include "sll.h"

int sl_insert_before(Slist **head, data_t g_data, data_t ndata)
{
    // Check for list empty
    if (*head == NULL)
    {
        return LIST_EMPTY;
    }

    // Creating a node
    Slist *new = malloc(sizeof(Slist));

    // Assign head value to a temporary pointer variable
    Slist *temp = *head;

    // Check the first node
    if (temp->data == g_data)
    {
        new->data = ndata;
        new->link = *head;
        *head = new;
        return SUCCESS;
    }

    // Assigning the temp variable value to another variable
    Slist *prev = NULL;

    // Traverse till the g_data node is reached
    while (temp)
    {
        if (temp->data == g_data)
        {
            new->data = ndata;
            new->link = temp;
            prev->link = new;
            return SUCCESS;
        }
        prev = temp;
        temp = temp->link;
    }
    return DATA_NOT_FOUND;
}