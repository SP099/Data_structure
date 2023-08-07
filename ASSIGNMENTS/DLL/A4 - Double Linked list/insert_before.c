#include "dll.h"

int dl_insert_before(Dlist **head, Dlist **tail, int gdata, int ndata)
{
    // If the list is empty
    if(*head == NULL)
        return LIST_EMPTY;
        
    Dlist *temp = *head;
    
    // Traverse the list to find the first node with data gdata
    while(temp)
    {
        if(temp->data == gdata)
        {
            // Allocate memory for a new node
            Dlist *new_node = malloc(sizeof(Dlist));
    
            // Check if memory allocation was successful
            if(new_node == NULL)
            {
                return FAILURE; // Return FAILURE constant if allocation failed
            }
    
            // Initialize the data and pointer fields of the new node
            new_node->prev = NULL;
            new_node->data = ndata;
            new_node->next = NULL;
            
            // If the first node in the list has data gdata, update the head pointer
            if(temp == *head)
            {
                new_node->next = *head;
                new_node->prev = NULL;
                *head = new_node;
                new_node->next->prev = new_node;
            }
            else  // Otherwise, update the pointers of the new node
            {
                new_node->next = temp;
                new_node->prev = temp->prev;
                temp->prev->next = new_node;
                temp->prev = new_node;
            }
            
            return SUCCESS; // Return SUCCESS constant if the node was successfully inserted
        }
        temp = temp->next;
    }
    return DATA_NOT_FOUND; // Return DATA_NOT_FOUND constant if no node with data gdata was found in the list
}
