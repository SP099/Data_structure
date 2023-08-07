#include "invertedIndex.h"

//function definition to validate files
int IsFileValid(char *file_name)
{
    
    FILE *fptr = fopen(file_name, "r");
    if(fptr != NULL)
    {
	if(getc(fptr) == EOF)
	{
	    fclose(fptr);
		//if file is empty
	    return FILE_EMPTY;
	}
	fclose(fptr);
	return SUCCESS;
    }
    else
    {
		//if file is not present
		return NOT_PRESENT;
    }
}

