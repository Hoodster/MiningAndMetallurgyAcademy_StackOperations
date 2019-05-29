#include <iostream>

struct stack 
{
	double value;
	stack* previous;
};


void push(stack& head, double y)
{
	stack* temp = new stack;
	(*temp).value = head.value;
	(*temp).previous = head.previous;

	head.value = y;

	if (head.value != NULL) 
	{
		head.previous = temp;
	}
}

double top(stack& head)
{
	return head.value;
}

double pop(stack& head)
{
	if (head.previous != NULL)
	{
		double headVar = 0.0;
		stack* temp = head.previous;
		stack* previousValue = head.previous;
		headVar = (*previousValue).value;
		temp = head.previous;
		head = *temp;
		return headVar;
	}
}

int main()
{
	try {
		stack* head = new stack;
		head->value = NULL;
		push(*head, 1.5);
		push(*head, -7.0);
		push(*head, 9.0);
		push(*head, 10.45);

		std::cout << "Printing all numbers in stack." << std::endl;
		std::cout << top(*head) << std::endl;
		std::cout << top(*head->previous) << std::endl;
		std::cout << top(*head->previous->previous) << std::endl;
		std::cout << top(*head->previous->previous->previous) << std::endl << std::endl;

		std::cout << "Deleting numbers" << std::endl;
		std::cout << top(*head) << std::endl;
		pop(*head);
		std::cout << top(*head) << std::endl;
		pop(*head);
		std::cout << top(*head) << std::endl;
		pop(*head);
		std::cout << top(*head) << std::endl;
		pop(*head);
		std::cout << top(*head) << std::endl << std::endl << std::endl;

		std::cout << "Adding numbers (showing top stack value)" << std::endl;
		std::cout << "Current stack first element: " << top(*head) << " (empty) "  << std::endl;
		push(*head, 2.0);
		std::cout << top(*head) << std::endl;
		push(*head, 3.3);
		std::cout << top(*head) << std::endl;
		push(*head, 44.43243);
		std::cout << top(*head) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
}
