/*
Name        : Sushant Patil
Date        : 09/04/2023
Description : Double Linked List
*/

#include "dll.h"

int dl_insert_first(Dlist **head, Dlist **tail, int data)
{
    //creates a new node by dynamically allocating memory 
    Dlist *new= malloc(sizeof(Dlist));

    // If the memory allocation fails, the function returns FAILURE.
    if(new == NULL)
        return FAILURE;

    new->data =data;
    new->prev =NULL;
    new->next = NULL;

    // If the list is empty, the new node becomes both the head and tail of the list.
    if(*head == NULL)
    {
        *head = new;
        *tail = new;
        return SUCCESS;
    }

    // If the list is not empty, the new node is inserted at the beginning of the list and becomes the new head.
    new->next = *head;
    (*head)->prev = new;
    *head =new;
    
    // The function returns SUCCESS upon successful insertion.
    return SUCCESS;
}