#include "invertedIndex.h"
//function definition to search word in database
int search_DB(wlist_t **head, char *word)
{
    // initialize the counter to 0
	int i=0;
	
    // if the list is empty, return a constant value that indicates an empty list
	if( *head == NULL)
		return EMPTYLIST;

    // loop through each element of the word list until we find the word we are looking for
	while(i<SIZE)
    
    {
        // get the pointer to the current word list
		wlist_t *w_temp = head[i];

        // loop through the linked list of file_table_t for the current word
        while(w_temp)
        {
			if(strcmp(w_temp -> word, word) == 0)
			{
                // if we find the word in the word list, print the files that contain it
				printf(RED "The word" RESET" "GREEN"%s"RESET" "RED" is present in the following files : \n" RESET,word);
				file_table_t *f_temp = w_temp -> t_link;

                // loop through the linked list of file_table_t for the current word
	            while(f_temp)
				{
                    // print the file name and the number of occurrences of the word in the file
					printf("%s(%d times)\n",f_temp -> f_name, f_temp -> w_count);
		            f_temp = f_temp -> link;
	            }       
				return SUCCESS;  // return a constant value that indicates a successful search
			}
            // move to the next node in the word list
		    w_temp=w_temp -> link;
	    }
		i++; // move to the next element of the word list
    }
	printf(RED "ERROR : The word" RESET""GREEN" %s"RESET" "RED" is not found in the database \n" RESET,word);
	return NOT_PRESENT; 
}

	





