/*
Name        : Sushant Patil
Date        : 03/04/2023
Description : WAF to merge two linked list into one
*/

#include "sll.h"

int sorted_merge( Slist **head1, Slist **head2)
{
    //if both input lists are empty
    if (*head1 == NULL && *head2 == NULL) 
    {
        return LIST_EMPTY;
    } 
    
    //if the first input list is empty then sets the head of the first list to the head of the second list
    else if (*head1 == NULL) 
    {
        *head1 = *head2;
    } 
    
    //If head2 is not empty, appends it to the end of head1.
    else if (*head2 != NULL) 
    {
        Slist *temp = *head1;
        while (temp->link != NULL) 
        {
            temp = temp->link;
        }
        temp->link = *head2;
    }

    //sorts the list in ascending order using sorting algorithm.
    sort(head1);

    return SUCCESS;
}