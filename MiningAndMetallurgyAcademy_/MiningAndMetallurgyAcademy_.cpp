#include <iostream>
using namespace std; //z dedykacj¹ dla Julki

struct stack //struktura stosu
{
	double value; //wartoœæ elementu stosu 
	stack* previous; //wskazanie na adres poprzedniego elementu stosu
};

//push(adres g³owy, wartoœæ typu double [zmiennoprzecinkowa])
//1. rezerwujemy iloœæ pamiêci potrzebn¹ do zapisania nowej struktury "stack" 
//   i pobranie wskazania na ten obszar pamiêci (dlatego "temp" jest wskaŸnikiem)
//2. kopiujemy ca³¹ g³owê do "temp"
//3. je¿eli wartoœæ g³owy nie jest pusta, co oznacza koniec stosu, to wska¿ na adres
//   poprzedniej g³owy pod adresem temp (kopiowaliœmy wartoœæ [patrz punkt 2.])
//4. zmieniamy wartoœæ g³owy na najnowsz¹ podan¹ w parametrze funkcji
void push(stack& head, double y)
{
	stack* temp = new stack; // 1.)
	(*temp).value = head.value;  // 2.)
	(*temp).previous = head.previous;

	if (head.value != NULL) //3.)
	{
		head.previous = temp; 
	}

	head.value = y; //4.)
}

//top(adres g³owy)
//1. zwracamy wartoœæ dla podanego adresu
double top(stack& head)
{
	return head.value; // 1.)
}

//pop(adres g³owy)
//1. upewniamy czy obecna g³owa nie jest ostatnim elementem stosu
//   sprawdzaj¹c czy wartoœæ poprzedniego elementu stosu
//   jest niepusta
//2. rezerwujemy pamiêæ na potrrzeby struktury
//3. podmieniamy g³owê daj¹c jej wartoœci poprzedniego elementu stosu
//4. zwracamy wartoœæ bo z jakiegoœ powodu pop mia³ byæ double
//   (mo¿e w testach zamiast top() u¿yæ po prostu pop()?
double pop(stack& head)
{
	if (head.previous->value != NULL) // 1.)
	{
		stack* previousValue = head.previous; // 2.)
		head = *previousValue;  // 3.)
		return head.value;  // 4.)
	}
}

int main()
{
	stack* head = new stack; //rezerwacja pamiêci potrzebnej by przechowywaæ struct
	head->value = NULL; //danie wartoœci pierwszej struktury NULL aby mieæ zdefiniowany koniec stosu

	push(*head, 1.5); // !!! poniewa¿ argumentem jest adres jako pierwszy parametr jest wskaŸnik na ten adres, ogólnie pamiêtaj o gwiazdce

	push(*head, -7.0);
	push(*head, 9.0);
	push(*head, 10.45);

	cout << "Stos: " << endl;

	cout << top(*head) << endl; //to samo jak z push()

	//jeœli chcemy przejœæ na drugi element stosu musimy odnieœæ siê nie do
	//adresu g³owy tylko do adresu poprzedniego elementu stosu
	//który z definicji w modelu struktury posiada wskaŸnik
	//na poprzedni element 
	//(dlaczego wskaŸnik odsy³am do komentarza dla pierwszego pusz()
	cout << top(*head->previous) << endl; 
	cout << top(*head->previous->previous) << endl;
	cout << top(*head->previous->previous->previous) << endl << endl;

	cout << "Usuniecie liczby drugiej i trzeciej z gory" << endl;
	pop(*head->previous);
	pop(*head->previous);
	cout << top(*head) << endl;
	cout << top(*head->previous) << endl;
	cout << "Wartosc na szczycie stosu: " << top(*head) << endl << endl << endl;

	cout << "Dodawanie liczby na szczyt stosu" << endl;
	push(*head, 2.0);
	cout << top(*head) << endl;
	cout << top(*head->previous) << endl;
	cout << top(*head->previous->previous) << endl;
}