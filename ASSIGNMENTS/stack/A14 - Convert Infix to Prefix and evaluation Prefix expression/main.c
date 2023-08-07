#include "main.h"

void str_rev(char *string);
void str_rev(char *string)
{
    //j should be initialized to strlen(string) - 1 to avoid accessing out of bounds memory
    int i = 0, j = strlen(string) - 1; 
    
    //the loop should continue until i >= j, not i < j/2
    for (; i < j ; i++, j--) 
    { 
        char temp = string[j];
        string[j] = string[i];
        string[i] = temp;
    }
}

int main()
{
	char Infix_exp[50], Prefix_exp[50], ch;
	int choice, result;
	Stack_t stk;
	stk.top = -1;

	printf("Enter the Infix expression : ");
	scanf("%s", Infix_exp);

	str_rev(Infix_exp);
	Infix_Prefix_conversion(Infix_exp, Prefix_exp, &stk);
	str_rev(Prefix_exp);
	printf("PreFix expression : %s\n", Prefix_exp);

	stk.top = -1;

	str_rev(Prefix_exp);
	result = Prefix_Eval(Prefix_exp, &stk);
	printf("\nResult : %d\n", result);
	return 0;
}
