#include "queue.h"

int dequeue(Queue_t **front, Queue_t **rear)
{
    // If the queue is empty
    if(*front == NULL)
    {
        // Return the FAILURE value
        return FAILURE;
    }
    
    // If there is only one element in the queue
    if(*front == *rear)
    {
        // Free the memory allocated for the front node
        free(*front);
        
        // Set both front and rear pointers to NULL
        *front = *rear = NULL;
    }
    
    // If there are multiple elements in the queue
    else
    {
        // Update the front pointer to point to the next node
        *front = (*front)->link;
        
        // Free the memory allocated for the current rear node
        free((*rear)->link);
        
        // Set the link of the new rear node to the new front node
        (*rear)->link = *front;
    }
    
    // Return the SUCCESS value
    return SUCCESS;
}