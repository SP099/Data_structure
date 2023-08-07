#include "queue.h"

/* Function to deque the element */
int dequeue(Queue_t *q)
{
    // Check if the queue is empty
    if(IsQueueEmpty(q) == SUCCESS)
    {
        // If the queue is empty, return failure
        return FAILURE;
    }
    
    // If the queue is not empty, remove the element
    // Get the front element of the queue
    int data = q->Que[q->front];
    
    // Increment the front and decrement the count of elements in the queue
    q->front = (q->front + 1) % (q->capacity);
    --(q->count);
    
    // Return SUCCESS
    return SUCCESS;
}