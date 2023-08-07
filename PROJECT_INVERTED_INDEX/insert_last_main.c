#include"invertedIndex.h"

int insert_at_last_main(wlist_t **head, char *word, char *f_name)
{
	wlist_t *new = malloc(sizeof(wlist_t));
    if (new == NULL)
    {
        return FAILURE;
    }

    new->f_count = 1;
    new->t_link = NULL;
    strcpy(new->word, word);

    update_link_table(&new, f_name);

    if (*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }

    wlist_t *temp = *head;
    while (temp->link)
    {
        temp = temp->link;
    }
    temp->link = new;
    return SUCCESS;
}

