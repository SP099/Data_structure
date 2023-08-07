/*
Name        : Sushant Patil
Date        : 02/04/2023
Description : WAF to reverse the single linked list using recursive methods
*/
#include "sll.h"

int reverse_recursive(Slist ** head)
{
    ////if the linked list is empty
    if(*head == NULL)
        return LIST_EMPTY;
        
    //checks if the linked list has only one element
    if((*head)->link == NULL)
        return SUCCESS;
        
    // reverse the rest of the linked list recursively
    Slist *rest = (*head)->link;
    int result = reverse_recursive(&rest);

    // update the links
    (*head)->link->link = *head;
    (*head)->link = NULL;
    *head = rest;

    return result;
}