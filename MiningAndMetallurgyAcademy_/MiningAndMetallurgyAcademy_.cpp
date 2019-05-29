#include <iostream>
using namespace std; //z dedykacj� dla Julki

struct stack //struktura stosu
{
	double value; //warto�� elementu stosu 
	stack* previous; //wskazanie na adres poprzedniego elementu stosu
};

//push(adres g�owy, warto�� typu double [zmiennoprzecinkowa])
//1. rezerwujemy ilo�� pami�ci potrzebn� do zapisania nowej struktury "stack" 
//   i pobranie wskazania na ten obszar pami�ci (dlatego "temp" jest wska�nikiem)
//2. kopiujemy ca�� g�ow� do "temp"
//3. je�eli warto�� g�owy nie jest pusta, co oznacza koniec stosu, to wska� na adres
//   poprzedniej g�owy pod adresem temp (kopiowali�my warto�� [patrz punkt 2.])
//4. zmieniamy warto�� g�owy na najnowsz� podan� w parametrze funkcji
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

//top(adres g�owy)
//1. zwracamy warto�� dla podanego adresu
double top(stack& head)
{
	return head.value; // 1.)
}

//pop(adres g�owy)
//1. upewniamy czy obecna g�owa nie jest ostatnim elementem stosu
//   sprawdzaj�c czy warto�� poprzedniego elementu stosu
//   jest niepusta
//2. rezerwujemy pami�� na potrrzeby struktury
//3. podmieniamy g�ow� daj�c jej warto�ci poprzedniego elementu stosu
//4. zwracamy warto�� bo z jakiego� powodu pop mia� by� double
//   (mo�e w testach zamiast top() u�y� po prostu pop()?
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
	stack* head = new stack; //rezerwacja pami�ci potrzebnej by przechowywa� struct
	head->value = NULL; //danie warto�ci pierwszej struktury NULL aby mie� zdefiniowany koniec stosu

	push(*head, 1.5); // !!! poniewa� argumentem jest adres jako pierwszy parametr jest wska�nik na ten adres, og�lnie pami�taj o gwiazdce

	push(*head, -7.0);
	push(*head, 9.0);
	push(*head, 10.45);

	cout << "Stos: " << endl;

	cout << top(*head) << endl; //to samo jak z push()

	//je�li chcemy przej�� na drugi element stosu musimy odnie�� si� nie do
	//adresu g�owy tylko do adresu poprzedniego elementu stosu
	//kt�ry z definicji w modelu struktury posiada wska�nik
	//na poprzedni element 
	//(dlaczego wska�nik odsy�am do komentarza dla pierwszego pusz()
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