#pragma once
#include <iostream>

using namespace std;


template <class T>
struct TElem
{
	TElem *prev=0, *next=0;
	T Val;
};
template <class T>
class TStack
{
private:

	TElem <T> *head, *tail;

public:

	TStack();
	//TStack(TStack& di);
	void add(T);
	T get();
	~TStack();


friend ostream & operator<<(ostream &out, TStack &mt)
{
	if(mt.head!=0)
	for (TElem <T> *i = mt.head; i != 0; i = i->next)
		out << i->Val << endl;
	return out;
}
};

template<class T>
TStack<T>::TStack()
{
	head = 0;
	tail = 0;
}

/*template<class T>
inline TStack<T>::TStack(TStack& di)
{
	head = new TElem <T>;
	tail = new TElem <T>;
	TElem <T> temp=di.head;
	if (di.head != 0)

		do
		{
			head.Val = temp.Val;
		} 
	while (di.temp.next!=0); 
	
}*/

template<class T>
void TStack<T>::add (T s)
{
	if (head == 0)
	{
		head= tail = new TElem <T>;
		tail->Val = s;
	}
	else
	{
		TElem <T> *temp = tail;
		tail = new TElem <T>;
		tail->prev = temp;
		temp->next = tail;
		tail->Val = s;
	}
}

template<class T>
T TStack<T>::get()
{
	if (tail == 0)
		throw 7;
	T temp = tail->Val;
	TElem <T> *temp1 = tail;
	tail = tail->prev;
	tail->next = 0;
	delete temp1;
	return temp;
}

template<class T>
TStack <T>::~TStack()
{
	TElem <T> *f = head;
	while (f != 0)
	{
		head = f;
		f = head->next;
		delete head;
	}
}