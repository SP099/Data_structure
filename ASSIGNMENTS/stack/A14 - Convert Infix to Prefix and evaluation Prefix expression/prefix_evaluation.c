#include "main.h"

int Prefix_Eval(char *Prefix_exp, Stack_t *stk)
{
    int i=0;
    while (Prefix_exp[i])
    {
        //If the current character is a digit, it is converted to an integer and pushed onto the stack 
        if (isdigit(Prefix_exp[i]))
        {
            push(stk, Prefix_exp[i] - '0');
        }
        
        /* If the current character is not a digit, it is assumed to be an operator. 
        The top two values on the stack are popped off and used as the operands for the operator. 
        The result is computed and pushed back onto the stack.*/
        else
        {
            int operand1 = peek(stk);
            pop(stk);
            int operand2 = peek(stk);
            pop(stk);
            switch (Prefix_exp[i])
            {
            case '+':
                push(stk, operand1 + operand2);
                break;
            case '-':
                push(stk, operand1 - operand2);
                break;
            case '*':
                push(stk, operand1 * operand2);
                break;
            case '/':
                push(stk, operand1 / operand2);
                break;
            }
        }
        i++;
    }
    
    /*  final result is obtained by calling peek to get the top value on the stack,
    popping it off the stack using pop, and returning it.*/
    int result = peek(stk);
    pop(stk);
    return result;

}