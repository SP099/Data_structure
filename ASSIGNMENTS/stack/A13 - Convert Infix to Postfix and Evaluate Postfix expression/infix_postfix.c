#include "main.h"

int Infix_Postfix_conversion(char *Infix_exp, char *Postfix_exp, Stack_t *stk)
{
    // Initialize variables i and j
    int i = 0, j = 0;
    
    // Loop through the infix expression
    while (Infix_exp[i])
    {
         // If the current character is a digit, add it to the postfix expression
        if (isdigit(Infix_exp[i]))
        {
            Postfix_exp[j] = Infix_exp[i];
            j++;
        }
        
        // If the current character is a left parenthesis, push it onto the stack
        else if (Infix_exp[i] == '(')
        {
            push(stk, Infix_exp[i]);
        }
        
        // If the current character is a right parenthesis, pop operators from the stack and add them to the postfix expression until a left parenthesis is found
        else if (Infix_exp[i] == ')')
        {
            while (stk->stack[stk->top] != '(')
            {
                Postfix_exp[j] = peek(stk);
                pop(stk);
                j++;
            }
            pop(stk);
        }
        
        // If the current character is an operator, pop operators from the stack and add them to the postfix expression until an operator with lower or equal precedence is found, then push the current operator onto the stack
        else
        {
            while (stk->top != -1 && stk->stack[stk->top] != '(' && priority(Infix_exp[i]) <= priority(stk->stack[stk->top]))
            {
                Postfix_exp[j] = peek(stk);
                pop(stk);
                j++;
            }
            push(stk, Infix_exp[i]);
        }
        
        // Move to the next character in the infix expression
        i++;
    }
    
    // Pop any remaining operators from the stack and add them to the postfix expression
    while (stk->top != -1)
    {
        Postfix_exp[j] = peek(stk);
        pop(stk);
        j++;
    }
    
    // Add a null terminator to the end of the postfix expression
    Postfix_exp[j] = '\0';
    
    // Return 1 to indicate success
    return 1;
}