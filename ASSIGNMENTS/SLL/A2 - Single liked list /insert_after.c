#include "sll.h"

int sl_insert_after(Slist **head, data_t g_data, data_t ndata)
{
    if (*head == NULL) 
    {
        return LIST_EMPTY; // empty list
    }

    Slist *temp = *head;

    while (temp != NULL) 
    {
        if (temp->data == g_data) 
        {
            // create new node
            Slist *new_node = (Slist*)malloc(sizeof(Slist));
            new_node->data = ndata;
            new_node->link = temp->link;

            // update link of previous node
            temp->link = new_node;

            return SUCCESS; // node inserted successfully
        }
        temp = temp->link;
    }

    return DATA_NOT_FOUND; // node with g_data not found
}