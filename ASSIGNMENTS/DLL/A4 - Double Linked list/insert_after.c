#include "dll.h"

int dl_insert_after(Dlist **head, Dlist **tail, int gdata, int ndata)
{
    // If the list is empty
    if (*head == NULL) 
    {
        return LIST_EMPTY;
    }
    
    Dlist *temp = *head;
    
    // Traverse the list to find the first node with data gdata
    while (temp != NULL) 
    {
        if (temp->data == gdata) 
        {
            // Allocate memory for a new node
            Dlist *node = (Dlist*)malloc(sizeof(Dlist));
    
            // Check if memory allocation was successful
            if (node == NULL) 
            {
                return FAILURE; // Return FAILURE constant if allocation failed
            }
    
            // Initialize the data and pointer fields of the new node
            node->data = ndata;
            node->next = NULL;
            node->prev = NULL;
            
            // If the last node in the list has data gdata, update the tail pointer
            if (temp == *tail) 
            {
                node->prev = *tail;
                (*tail)->next = node;
                *tail = node;
            } 
            else // Otherwise, update the pointers of the new node
            {  
                node->prev = temp;
                node->next = temp->next;
                temp->next->prev = node;
                temp->next = node;
            }
            
            return SUCCESS; // Return SUCCESS constant if the node was successfully inserted
        }
        temp = temp->next;
    }
    
    // Return DATA_NOT_FOUND constant if no node with data gdata was found in the list
    return DATA_NOT_FOUND;
}
