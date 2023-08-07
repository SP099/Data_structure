#include"invertedIndex.h"
//Function definition to store filenames to list
int store_filenames_to_list(char *f_name, file_node_t **head)
{
	// Create the node and update the filename, link = NULL
    file_node_t *new = (file_node_t *)malloc(sizeof(file_node_t));
    if (new == NULL)
    {
        printf(RED"ERROR: Memory allocation for new node is failed.\n"RESET);
        return FAILURE;
    }
    strcpy(new -> f_name, f_name);
    new -> link = NULL;
    //List is empty or not
    if (*head == NULL)
    {
		*head = new;
	    return SUCCESS;
    }

//List not empty
file_node_t *temp = *head, *prev = NULL;
while (temp)
{
	if (strcmp(temp -> f_name, f_name))
	{
		prev = temp;
		temp = temp -> link;
	}
	else
	{
		free(new);
		return REPEATED;
	}
}

prev -> link = new;
return SUCCESS;
}

