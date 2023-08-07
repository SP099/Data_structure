#include"invertedIndex.h"
int update_link_table(wlist_t **word_node, char *f_name)
{
    file_table_t *new = malloc(sizeof(file_table_t));
    if (!new)
    {
        return FAILURE;
    }

    // Update the fields, f_name = f_name, word count = 1, link = NULL
    strcpy(new->f_name, f_name);
    new->w_count = 1;
    new->link = NULL;

    // Update the file table list for the word node
    if ((*word_node)->t_link == NULL)
    {
        (*word_node)->t_link = new;
    }
    else
    {
        file_table_t *temp = (*word_node)->t_link;
        while (temp->link)
        {
            temp = temp->link;
        }
        temp->link = new;
    }
    return SUCCESS;
}

