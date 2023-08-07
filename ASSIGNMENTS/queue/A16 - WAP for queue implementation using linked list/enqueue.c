#include "queue.h"

int enqueue(Queue_t **front, Queue_t **rear, int data)
{
    // Allocate memory for a new node
    Queue_t *newNode = malloc(sizeof(Queue_t));
    
    // Check if memory allocation was successful
    if(newNode == NULL)
        return FAILURE;
        
    // Set the data of the new node
    newNode->data = data;
    
    // Set the link of the new node to NULL
    newNode->link = NULL;
    
    // If the queue is empty
    if(*front == NULL)
    {
        // Set both front and rear pointers to the new node
        *front = *rear = newNode;
    }
    
    // If the queue is not empty
    else
    {
        // Set the link of the current rear node to the new node
        (*rear)->link = newNode;
        
        // Update the rear pointer to point to the new node
        *rear = newNode;
    }
    newNode->link = *front;
    return SUCCESS;
}