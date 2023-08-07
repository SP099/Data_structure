#include "sll.h"
/* Function to get the middle of the linked list*/
int find_mid(Slist *head, int *mid) 
{ 
    if (head == NULL) 
    {
        return LIST_EMPTY;  // case when list is empty
    }

    Slist *slow_ptr = head, *fast_ptr = head;

    while (fast_ptr != NULL && fast_ptr->link != NULL) 
    {
        fast_ptr = fast_ptr->link->link;
        slow_ptr = slow_ptr->link;
    }

    *mid = slow_ptr->data;  // set mid to the data of the middle node
    return SUCCESS;
} 