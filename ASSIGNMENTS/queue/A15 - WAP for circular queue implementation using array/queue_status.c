#include "queue.h"

/* Function to check if the queue is full */
int IsQueueFull(Queue_t *q)
{
    // If the count of elements in the queue is equal to the capacity,
    // the queue is full, so return success
    if(q->count==q->capacity)
    {
        return SUCCESS;
    }
    
    // If the queue is not full, return failure
    return FAILURE;
}

/* Function to check if the queue is empty */
int IsQueueEmpty(Queue_t *q)
{
    // If the count of elements in the queue is 0,
    // the queue is empty, so return success
    if(q->count == 0)
    {
        return SUCCESS;
    }
    
    // If the queue is not empty, return failure
    return FAILURE;
}