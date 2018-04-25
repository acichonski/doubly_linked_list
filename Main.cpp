#include<iostream>
#include<sstream>
#include<string>
#include<assert.h>

using namespace std;

template<class T>
T stringToValue(string str) {
	istringstream iss(str);
	T value;
	iss >> value;
	return value;
}

struct EL
{
	double v;
	EL * next = NULL;
	EL * previous = NULL;
	EL();
	EL(double v);
	virtual ~EL();
};

EL::EL(double v)
{
	this->v = v;

}

class List
{
	EL* head; //przechowuje adres pierwszego el listy
	EL* tail; //przechowuje adres ostatniego el listy
	EL* addHead(double val);
	EL* addTail(double val);
	EL* removeHead();
	EL* removeTail();


public:
	List();
	~List();
	EL * add(double val);
	EL * removeValue(double val);
	void removeList();
	void showRightToLeft();
	void showLeftToRight();
	void swap(EL * &tmp, EL * &k); //zmienia ze soba dwa el listy

};

EL * List::addHead(double val)
{
	EL *newEl = new EL(val);
	if (head) {
		//head istnieje
		head->previous = newEl;
		newEl->next = head;
		head = newEl;
	}
	else {
		//lista pusta
		head = newEl;
		tail = newEl;
	}

	return nullptr;
}

EL * List::addTail(double val)
{
	EL *newEl = new EL(val);
	if (tail) {
		//tail istnieje
		tail->next = newEl;
		newEl->previous = tail;
		tail = newEl;
	}
	else {
		//lista pusta
		head = newEl;
		tail = newEl;
	}

	return nullptr;
}

EL * List::removeHead()
{
	if (head) //sprawdzamy czy istnieje head
	{
		EL * tempEl = head;
		if (tempEl == tail)
		{
			head = nullptr;
			tail = nullptr;
		}
		else { //jesli istnieja kolejne elementy po head
			head = tempEl->next; //przypisanie kolejnego elementu jako head
			head->previous = nullptr; //usuwanie powiazania wstecz
		}
	}

	return nullptr;
}

EL * List::removeTail()
{
	if (tail) //sprawdzamy czy istnieje tail
	{
		EL * tempEl = tail;
		if (tempEl == head) { //sprawdzamy czy lista nie jest jednoelementowa
							  //usuwanie elementu z listy
			head = nullptr;
			tail = nullptr;
		}
		else {
			tail = tempEl->previous; //przypisanie poprzedniego elementu jako tail
			tail->next = nullptr; //usuwanie powiazania w przod
		}
	}

	return nullptr;
}

List::List()
{
}

List::~List()
{
	removeList();
}

void List::removeList()
{
	EL * tempEl;
	while (head) //dopoki istnieje lista
	{
		tempEl = head;
		head = head->next;
		delete tempEl;
	}
}

void List::showRightToLeft()
{
	EL* temp = head;
	while (temp->next != nullptr) {
		cout << temp->v << endl;
		temp = temp->next;
	}
	cout << endl;
}

void List::showLeftToRight()
{
	EL* temp = tail;
	while (temp->previous != nullptr) {
		cout << temp->v << endl;
		temp = temp->previous;
	}
	cout << endl;
}


