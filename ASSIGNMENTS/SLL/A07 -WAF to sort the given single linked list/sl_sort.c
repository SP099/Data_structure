/*
Name        : Sushant Patil
Date        : 01/04/2023
Description : WAF to sort the given single linked list
*/

#include "sll.h"

int sl_sort(Slist **head)
{
    // Check if the list is empty
    if(*head == NULL)
        return LIST_EMPTY;

    // Check if the list has only one node
    if((*head)->link == NULL)
        return SUCCESS;

    Slist *ptr = *head;
    data_t count = 0, i, j;
    
    // Count the number of nodes in the list
    while(ptr)
    {
        count++;
        ptr=ptr->link;
    }
    
    
    // Bubble sort algorithm
    for(i = 0;i < count;i++)
    {
        Slist *t1 = *head, *t2 = t1->link, *prev = NULL;
        for(j = 0;j < (count-i-1);j++)
        {
            if((t1->data) > (t2->data))
            {
                // check adjecent nodes or not
                if(prev == NULL)
                {
                    t1->link = t2->link;
                    t2->link = t1;
                    *head = t2;
                }
                else
                {
                    //else swapping other nodes
                    t1->link = t2->link;
                    t2->link = t1;
                    prev->link = t2;
                }
                
                //updating prev and t2
                prev = t2;
                t2 = t1->link;
            }
            else
            {
                prev = t1;
                t1 = t2;
                t2 = t1->link;
            }
        }
    }
    return SUCCESS;
}