#include"invertedIndex.h"


void read_datafile(wlist_t **head, char *f_name)
{
	FILE *fptr = fopen(f_name, "r");
	char word[BUFF_SIZE], flag = 0;

while (fscanf(fptr, "%s", word) != EOF)
{
	flag = 1;
	int index;

	// find the index number to store the word information
	if(isupper(word[0]))
	{
		index = word[0] % 65;
	}
	else
	{
		index = word[0] % 97;
	}

	//Check index is empty or not
		if (head[index] != NULL)
		{
			wlist_t *temp = head[index];
			while (temp)
			{
				// Checking the word is already exist in the database
				if (strcmp(temp -> word, word) == 0)
				{
					update_word_count(&temp, f_name);
					flag = 0;
					break;
				}
				temp = temp -> link;
			}
		}
		if (flag)
			insert_at_last_main(&head[index], word, f_name);
	}
	printf(GREEN"Successfull: Creation of database for %s\n"RESET, f_name);

}

