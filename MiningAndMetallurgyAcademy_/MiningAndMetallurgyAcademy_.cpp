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
	if (head.previous->value != NULL)
	{
		stack* previousValue = head.previous;
		double headVar = (*previousValue).value;
		head = *previousValue;
		return headVar;
	}
}

int main()
{
	stack* head = new stack;
	head->value = NULL;
	push(*head, 1.5);
	push(*head, -7.0);
	push(*head, 9.0);
	push(*head, 10.45);

	std::cout << "Stos: " << std::endl;
	std::cout << top(*head) << std::endl;
	std::cout << top(*head->previous) << std::endl;
	std::cout << top(*head->previous->previous) << std::endl;
	std::cout << top(*head->previous->previous->previous) << std::endl << std::endl;

	std::cout << "Usuniecie liczby drugiej i trzeciej z gory" << std::endl;
	pop(*head->previous);
	pop(*head->previous);
	std::cout << top(*head) << std::endl;
	std::cout << top(*head->previous) << std::endl;
	std::cout << "Wartosc na szczycie stosu: " << top(*head) << std::endl << std::endl << std::endl;

	std::cout << "Dodawanie liczby na szczyt stosu" << std::endl;
	push(*head, 2.0);
	std::cout << top(*head) << std::endl;
	std::cout << top(*head->previous) << std::endl;
	std::cout << top(*head->previous->previous) << std::endl;
}