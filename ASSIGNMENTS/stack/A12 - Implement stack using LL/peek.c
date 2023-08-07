#include "stack.h"

int Peek(Stack_t **top)
{
    // If the stack is empty (i.e. the top pointer is NULL)
    if(*top == NULL)
        return FAILURE;
        
    // Otherwise, return the data field of the top node
    return (*top)->data;
}