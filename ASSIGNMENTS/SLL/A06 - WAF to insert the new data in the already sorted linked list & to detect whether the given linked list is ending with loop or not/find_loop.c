#include "sll.h"

/* Function for finding the loop in the link */
int find_loop(Slist *head)
{
    //check if list is empty
    if (head == NULL)
    {
        return LIST_EMPTY;
    }

    Slist *fast = head, *slow = head;

    /* Traverse the linked list using two pointers */
    while (fast != NULL && fast->link != NULL)
    {
        slow = slow->link;
        fast = fast->link->link;

        /* If fast and slow pointers meet, then there is a loop */
        if (fast == slow)
        {
            return SUCCESS;
        }
    }

    /* If the loop is not found */
    return LOOP_NOT_FOUND;
}