#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"

template <class T>
class LinkedList {
private:
	int counter;
public:
	Node<T>* head;
	Node<T>* tail;

	Node<T>* get(int index) const;

	void insert_head(const T& value);
	void insert_tail(const T& value);
	void insert(int index, const T& value);
	
	int search(const T& value);
	
	void remove_head();
	void remove_tail();
	void remove(int index);

	int size() const;

	// operator<<
	void show() const;
};


template <class T>
Node<T>* LinkedList<T>::get(int index) const
{
	if (index < 0 || index > counter)
		return nullptr;

    Node<T> * temp_node = head;

    for(int i = 0; i < index; ++i)
    {
        temp_node = temp_node->next;
    }

    return temp_node;
}


template <class T>
void LinkedList<T>::insert_head(const T& value)
{
	Node<T>* temp_node = new Node<T>{ value };
	temp_node->next = head;

	head = temp_node;

	if (counter == 0)
		tail = head;

	counter++;
}

template <class T>
void LinkedList<T>::insert_tail(const T& value) {
	if (counter == 0)
	{
		insert_head(value);
		return;
	}

	Node<T>* temp_node = new Node<T>{ value };
	tail->next = temp_node;
	tail = temp_node;
	counter++;
}

template <class T>
void LinkedList<T>::insert(int index, const T& value)
{
	if (index < 0 || index > counter)
		return;

	if (index == 0)
	{
		insert_head(value);
		return;
	}
	else if (index == counter)
	{
		insert_tail(value);
		return;
	}

	// szukanie elementu na pozycji przed ta na ktora chcemy wstawic element
	Node<T> * prev_node = head;
	for (int i = 0; i < index - 1; ++i)
	{
		prev_node = prev_node->next;
	}

	// ustawienie sie na elemencie, ktory bedzie kolejnym po wstawianym
	Node<T> * next_node = prev_node->next;

	// tworzenie nowego elementy i wstawianie go na odpowiedniej pozycji
	Node<T> * new_node = new Node<T>{ value };
	new_node->next = next_node;
	prev_node->next = new_node;

	counter++;
}

template <class T>
void LinkedList<T>::show() const {
	Node<T>* temp_node = head;

	while (temp_node) {
		std::cout << temp_node->value << "\t";
		temp_node = temp_node->next;
	}
	std::cout << std::endl;
}

template <class T>
int LinkedList<T>::search(const T& value) {
	
	if (counter == 0) {
		return -1;
	}

	int index = 0;

	Node<T>* temp_node = head;

	while (temp_node->value != value)
	{
		index++;
		temp_node = temp_node->next;

		if (!temp_node)
		{
			return -1;
		}
	}

	return index;
}

template <class T>
void LinkedList<T>::remove_head()
{
	if (counter == 0)
		return;

	Node<T>* temp_node = head;
	head = head->next;
	delete temp_node;
	counter--;
}

template <class T>
void LinkedList<T>::remove_tail()
{
	if (counter == 0) {
		return;
	}
	if (counter == 1)
	{
		remove_head();
		return;
	}

	Node<T>* prev_node = head;
	Node<T>* temp_node = head->next;

	while (temp_node->next)
	{
		prev_node = prev_node->next;
		temp_node = temp_node->next;
	}

	prev_node->next = nullptr;
	tail = prev_node;

	delete temp_node;

	counter--;
}


template <class T>
void LinkedList<T>::remove(int index)
{
	if (counter == 0) {
		return;
	}

	if (index < 0 || index >= counter) {
		return;
	}

	if (index == 0)
	{
		remove_head();
		return;
	}
	else if (index == counter - 1)
	{
		remove_tail();
		return;
	}

	Node<T>* prev_node = head;

	// znajdujemy element przed wybranym indeksem
	for (int i = 0; i < index - 1; ++i)
	{
		prev_node = prev_node->next;
	}

	Node<T>* temp_node = prev_node->next;
	Node<T> * next_node = temp_node->next;
	prev_node->next = next_node;

	delete temp_node;
	counter--;
}

template <class T>
int LinkedList<T>::size() const {
	return counter;
}

#endif // !LINKED_LIST_H

