#include "sll.h"

/* Function to get the nth node from the last of a linked list*/
int find_nth_last(Slist *head, int pos, int *data) 
{
    // Check if list is empty
    if (head == NULL) 
    {
        return LIST_EMPTY;
    }
    
    if(pos == 0)
    {
        return FAILURE;
    }
    // Initialize two pointers p1 and p2 to the first node in the list
    Slist *p1 = head, *p2 = head;

    // Move p1 pos nodes forward
    for (int i = 0; i < pos; i++) 
    {
        if (p1 == NULL) 
        {
            // If pos is greater than the number of nodes in the list, return failure
            return FAILURE;
        }
        p1 = p1->link;
    }

    // Move both pointers until p1 reaches the end of the list
    while (p1 != NULL) 
    {
        p1 = p1->link;
        p2 = p2->link;
    }

    // Assign the data of p2 to the integer pointed to by data
    *data = p2->data;

    return SUCCESS;
}

