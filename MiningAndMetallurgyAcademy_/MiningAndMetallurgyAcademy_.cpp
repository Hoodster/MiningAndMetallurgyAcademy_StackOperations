
#include <iostream>

struct stack 
{
	double value;
	stack* next = NULL;
};

void push(stack *stk, double y) 
{
	stack* temp;
	temp = stk;
	stk = new stack;
	stk->value = y;
	stk->next = temp;
}

double pop(stack *stk)
{
	if (stk != NULL)
	{
		double stkVar = 0.0;
		stack* temp;
		stkVar = stk->value;
		temp = stk->next;
		delete stk;
		stk = temp;
		return stkVar;
	}
}

double top(stack *stk)
{
	return stk->value;
}

int main()
{
	stack sta1;
	push(&sta1, 1.0);
	push(&sta1, -7.0);
	pop(&sta1);
	std::cout << top(&sta1) << std::endl;
}
