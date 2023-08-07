#include "invertedIndex.h"
int display_DB(wlist_t **head)
{
    //declaring variables
    int i = 0, flag = 0;
    //loop iterates up to SIZE
    while (i < SIZE)
    {
        // Declare a pointer to the current node
        wlist_t *current = NULL;

        // If the current index of the hash table is not empty
        if (head[i] != NULL) 
        {
            // Print the index number
            printf(BLUE "[%d]  " RESET, i);

            // Point to the current node
            current = head[i];

            // Point to the current file in the current node
            file_table_t *inner_current = current->t_link;

            // Set flag to 0
            flag = 0;

            // Loop over all the nodes at the current index
            while (current) 
            {
                // Print the word
                if (flag == 0)
                    printf(GREEN "\t[%s]" RESET, current->word);
                else
                    printf(GREEN "\t[%s]" RESET, current->word);

                // Print the count of the word
                printf(RED "\t%d" RESET, current->f_count);
                printf("\tFiles(s) : File:");

                // Loop over all the files in the current node
                while (inner_current)
                {
                    // Print the file name and its count
                    printf(GREEN "\t%s" RESET ":" RED "%d " RESET "times", inner_current->f_name, inner_current->w_count);

                    // Check if there is a next file in the list
                    if (inner_current->link == NULL)
                        printf("\t-> NULL");
                    else
                        printf("\t: File :");

                    // Point to the next file in the list
                    inner_current = inner_current->link;
                }
                printf("\n");

                // Move to the next node in the list
                current = current->link;

                // If the next node is not null, point to the first file in the new node
                if (current != NULL)
                    inner_current = current->t_link;

                // Set flag to 1
                flag = 1;
            }
        }
        //incrementing i
        i++;
    }
    return SUCCESS;
}
