#include "stack.h"

/* Fuction for inserting the element */
int Push(Stack_t *s, int element)
{
    // check if the stack is full
    if(s->top == s->capacity - 1)
    {
        // return failure if stack is full
        return FAILURE;
    }
    
    // increment the top index
    s->top++;
    
    // add the new element to the top of the stack
    s->stack[s->top] = element;
    
    // return success
    return SUCCESS;
}