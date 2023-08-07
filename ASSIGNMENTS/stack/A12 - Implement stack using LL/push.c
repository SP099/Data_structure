/*
Name        : Sushant Patil
Date        : 13/04/2023
Description : Implement stack using LL
*/

#include "stack.h"

//Push function for the stack
int Push(Stack_t **top, data_t data)
{
    // Allocate memory for a new node
    Stack_t *newnode = malloc(sizeof(Stack_t));
    
    // Check if memory allocation was successful
    if(newnode == NULL)
    {
        // If allocation failed, return FAILURE
        return FAILURE;
    }
    
    // Set the data field of the new node to the provided data
    newnode->data = data;
    
    // Set the link field of the new node to NULL
    newnode->link = NULL;
    
    // If the stack is empty (i.e. the top pointer is NULL)
    if(*top == NULL)
    {
        // Set the top pointer to point to the new node
        *top = newnode;
        
        // Return SUCCESS
        return SUCCESS;
    }
    else
    {
        // If the stack is not empty, link the new node to the current top node
        newnode->link = *top;
        
        // Set the top pointer to point to the new node
        *top = newnode;
        
        // Return SUCCESS
        return SUCCESS;
    }
}