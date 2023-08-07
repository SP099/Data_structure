/*
Name        : Sushant Patil
Date        : 02/04/2023
Description : WAP to remove duplicates in a SLL
*/

#include "sll.h"

//remove duplicate data's from list
int remove_duplicates( Slist **head )
{
    //check if empty list
    if (*head == NULL) 
    {
        return FAILURE ;
    }
    
    //if list contains only one node
    if ((*head)->link == NULL) 
    {
        return SUCCESS; // list has at most one node, no duplicates to remove
    }
    
    //if list has more than one node
    Slist *temp1 = *head;
    while (temp1 != NULL) 
    {
        Slist *temp2 = temp1->link;
        Slist *prev = temp1;
        while (temp2 != NULL) 
        {
            if (temp1->data == temp2->data) 
            {
                // remove the duplicate node
                prev->link = temp2->link;
                free(temp2);
                temp2 = prev->link;
            } 
            else 
            {
                prev = temp2;
                temp2 = temp2->link;
            }
        }
        temp1 = temp1->link;
    }
    return SUCCESS; // success
}