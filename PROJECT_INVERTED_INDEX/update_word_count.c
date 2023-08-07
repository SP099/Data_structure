#include"invertedIndex.h"

int update_word_count(wlist_t **head, char *fname)
{
    // Compare the filenames of the file table list
    file_table_t *temp = (*head)->t_link;
    while (temp)
    {
        // 1. Check whether the filenames are matching or not
        if (strcmp(temp->f_name, fname) == 0)
        {
            // 2. If file name matches then increment the word count in the respective table node
            temp->w_count++;
            return SUCCESS;
        }
        temp = temp->link;
    }
    // 3. if not matches, then increment the filecount in the head, create filetable node and insert as a last node in the file table list.
    (*head)->f_count++;
    file_table_t *new = malloc(sizeof(file_table_t));
    if (new == NULL)
        return FAILURE;
    strcpy(new->f_name, fname);
    new->w_count = 1;
    new->link = NULL;
    if ((*head)->t_link == NULL)
        (*head)->t_link = new;
    else
    {
        file_table_t *temp = (*head)->t_link;
        while (temp->link != NULL)
            temp = temp->link;
        temp->link = new;
    }
    return SUCCESS;
}

