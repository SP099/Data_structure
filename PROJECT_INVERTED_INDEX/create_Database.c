#include"invertedIndex.h"

int create_DB(file_node_t *file_head, wlist_t **head)
{
    while (file_head)
    {
        read_datafile(head, file_head->f_name);
        file_head = file_head->link;
    }
    return SUCCESS;
}

