#include "invertedIndex.h"

void validate_n_store_filenames(file_node_t **fhead, char *file_names[])
{
	int i = 0, status;
	while (file_names[i] != NULL)
	{
		status = IsFileValid(file_names[i]);

		if (status == NOT_PRESENT)
		{
			printf(RED"%s is not present\n"RESET, file_names[i]);
			printf(BLUE"So we are not adding the file to the list\n"RESET);
			i++;
		}
		else if(status == FILE_EMPTY)
		{
			printf(RED"%s is an empty file\n"RESET, file_names[i]);
			printf(BLUE"So we are not adding the file to the list\n"RESET);
			i++;
		}
		else
		{
			if (store_filenames_to_list(file_names[i], fhead) == REPEATED)
			{
				printf(RED"%s is repeated\n"RESET, file_names[i]);
				printf(BLUE"So we are not adding the file to the list\n"RESET);
			}
			else
			{
				printf(GREEN"Successfull: %s is added the list\n"RESET, file_names[i]);
			}
			i++;
		}
	}
}
