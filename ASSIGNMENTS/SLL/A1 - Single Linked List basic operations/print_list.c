#include "sll.h"

void print_list(Slist *head)
{
    // Check if the list is empty
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
    else
    {
        // Traverse the list and print each node's data value
	    while (head)		
	    {
		    printf("%d -> ", head -> data);
		    head = head -> link;
	    }

        // Print "NULL" to indicate the end of the list
	    printf("NULL\n");
    }
}