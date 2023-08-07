#include "stack.h"

int Pop(Stack_t **top)
{
    // If the stack is empty (i.e. the top pointer is NULL)
    if(*top == NULL)
    {
        // Return FAILURE
        return FAILURE;
    }
    
    // Create a temporary pointer to the current top node
    Stack_t *temp = *top;
    
    // Set the top pointer to point to the next node in the stack
    *top = (*top)->link;
    
    // Free the memory allocated for the original top node
    free(temp);
    
    // Return SUCCESS
    return SUCCESS;
}