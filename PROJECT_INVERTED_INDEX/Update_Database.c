#include"invertedIndex.h"

//function definition to update database
int update_DB(file_node_t **f_head, wlist_t **w_head, char *f_name)
{
	
	if(IsFileValid(f_name)==NOT_PRESENT)
	{
		printf(RED "ERROR : The file %s is not_prsent\n"RESET,f_name );
		return NOT_PRESENT;
	}

	else if(store_filenames_to_list(f_name,f_head)==REPEATED)
	{
		printf(RED "ERROR : The file %s is repeated\n" RESET,f_name);
		printf(BLUE "So we are not adding this file into the list\n" RESET);
		return REPEATED;
	}

	else if(IsFileValid(f_name)==FILE_EMPTY)
	{
		printf(RED "ERROR : The file %s is empty\n" RESET,f_name);
		printf(RED "So we are not adding this file into the list\n" RESET);
		return FILE_EMPTY;
	}

	read_datafile(w_head,f_name);

	printf(BOLDGREEN "The file %s has been added to the database \n" RESET,f_name);
	return SUCCESS;
}




