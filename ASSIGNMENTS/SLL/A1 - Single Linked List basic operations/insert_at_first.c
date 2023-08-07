#include "sll.h"

int insert_at_first(Slist **head, data_t data)
{
	Slist *new = malloc(sizeof(Slist));

    //check if node is created
	if (new == NULL)
	{
		return FAILURE;
	}
	
	/* updating the data and link */
	new -> data = data;
	new -> link = NULL;
	
	//cheking if the list is empty
	if(*head == NULL)
	{
	    *head = new;
	    return SUCCESS;
	}
	
	//assigning link to the new
	else
	{
	    new -> link = *head;
	    *head = new;
	    return SUCCESS;
	}
	
	return FAILURE;
}