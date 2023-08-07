#include "queue.h"

/* Function to Insert the element */
int enqueue(Queue_t *q, int data)
{
    // Check if the queue is full
    if(IsQueueFull(q) == SUCCESS)
    {
        // If the queue is full, return failure
        return FAILURE;
    }
    
    // If the queue is not full, insert the element
    // If the front of the queue is -1, set it to 0
    if(q->front == -1)
    {
        q->front = 0;
    }
    
    // Increment the rear and insert the element into the queue
    q->rear = (q->rear + 1) % (q->capacity);
    q->Que[q->rear] = data;
    
    // Increment the count of elements in the queue
    ++(q->count);
    
    // Return success
    return SUCCESS;
}
