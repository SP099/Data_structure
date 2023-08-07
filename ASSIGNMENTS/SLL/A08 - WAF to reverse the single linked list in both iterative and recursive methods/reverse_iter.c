/*
Name        : Sushant Patil
Date        : 02/04/2023
Description : WAF to reverse the single linked list using iterative method
*/

#include "sll.h"

/* Function to reverse the given single linked list */
int reverse_iter(Slist **head) 
{
    //if the linked list is empty
    if(*head == NULL)
        return LIST_EMPTY;
        
    //checks if the linked list has only one element
    if((*head)->link == NULL)
        return SUCCESS;
        
    //declares and initializes three pointers
    Slist *prev = NULL, *cur = *head, *next = NULL;
    
    //iterates until the cur reaches NULL
    while(cur)
    {
        //updates prev,cur,next
        next = cur->link;
        cur->link = prev;
        prev = cur;
        cur = next;
    }
    
    //sets the head pointer to point to the last node in the original linked list, which is now the first node in the reversed linked list.
    *head = prev;
    return SUCCESS;
} 