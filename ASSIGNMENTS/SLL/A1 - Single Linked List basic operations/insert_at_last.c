#include "sll.h"

int insert_at_last(Slist **head, data_t data)
{
    Slist *temp;
	temp = *head;

	Slist *new = malloc(sizeof(Slist));

	if (new == NULL)
	{
		return FAILURE;
	}

	/* update the data and link */
	new -> data = data;
	new -> link = NULL;

	/* If empty list */
	if ( *head == NULL )
	{
		/* update head and tail */
		*head = new;
		return SUCCESS;
	} 
	else
	{
		//iterate till the last
		while(temp->link)
		{
			temp = temp -> link;
		}
		/* Establish link between last and new Node and update tail */
		temp -> link = new;
	}
	return SUCCESS;
}