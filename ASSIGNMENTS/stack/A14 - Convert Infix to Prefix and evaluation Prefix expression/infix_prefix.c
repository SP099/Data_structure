#include "main.h"


// Function to convert infix expression to prefix expression
int Infix_Prefix_conversion(char *Infix_exp, char *Prefix_exp, Stack_t *stk)
{
    int i = 0, j = 0;
    
    // Loop through the infix expression
    while (Infix_exp[i])
    {
        // If the current character is a digit, add it to the prefix expression
        if (isdigit(Infix_exp[i]))
        {
            Prefix_exp[j++] = Infix_exp[i];
        }
        
        // If the current character is a closing parenthesis, push it onto the stack
        else if (Infix_exp[i] == ')')
        {
            push(stk, Infix_exp[i]);
        }
        
        // If the current character is an opening parenthesis
        else if (Infix_exp[i] == '(')
        {
            // Pop elements off the stack and add them to the prefix expression
            // until a closing parenthesis is reached
            while (stk->top != -1 && stk->stack[stk->top] != ')')
            {
                Prefix_exp[j++] = peek(stk);
                pop(stk);
            }
            
            // Pop the closing parenthesis off the stack
            if (stk->top != -1) 
            {
                pop(stk);
            }
        }
        
        // If the current character is an operator
        else
        {
            
            // Pop elements off the stack and add them to the prefix expression
            // while their priority is greater than or equal to the current operator's priority
            while (stk->top != -1 && stk->stack[stk->top] != ')' && priority(Infix_exp[i]) < priority(stk->stack[stk->top]))
            {
                Prefix_exp[j++] = peek(stk);
                pop(stk);
            }
            
            // Push the current operator onto the stack
            push(stk, Infix_exp[i]);
        }
        i++;
    }

    // Pop any remaining elements off the stack and add them to the prefix expression
    while (stk->top != -1)
    {
        Prefix_exp[j++] = peek(stk);
        pop(stk);
    }
    // Add null terminator to the end of the prefix expression
    Prefix_exp[j] = '\0';
    // Return success
    return 1;
}
