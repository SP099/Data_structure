#include "invertedIndex.h"

//function definition to save database content
int save_DB(wlist_t **head, char *f_name)
{
    if(*head == NULL)
	return EMPTYLIST;
    FILE *fptr = fopen(f_name, "w");
    int i = 0, flag = 0;

   	while( i < SIZE)
    {
        wlist_t *temp = NULL;

        if (head[i] != NULL) {
            fprintf(fptr, "#%d;  \n" RESET, i);
            temp = head[i];
            file_table_t *T_temp = temp -> t_link;
            flag = 0;
  
			while (temp) 
			{
                if (flag == 0)
                    fprintf(fptr, "%s;", temp->word);
                else
                    fprintf(fptr, "%s", temp->word);

                fprintf(fptr, "%d" , temp->f_count);

                while (T_temp)
				{
                    fprintf(fptr, ";%s;%d", T_temp->f_name, T_temp->w_count);
                    T_temp = T_temp->link;
                }
                fprintf(fptr, ";#\n");

                temp = temp->link;

                if (temp != NULL)
				{
                    T_temp = temp->t_link;
                }
                flag = 1;
            }
        }
	i++;
    }
    return SUCCESS;
}

