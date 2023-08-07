#include "stack.h"

/* Function for Poping the element */
int Pop(Stack_t *s)
{
    // check if the stack is empty
    if(s->top == -1)
    {
        // return failure if stack is empty
        return FAILURE;
    }
    
    // decrement the top index to remove the top element
    s->top--;

    // return success
    return SUCCESS;
}