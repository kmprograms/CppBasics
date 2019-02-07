#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include "node.h"

template <class T>
class DoublyLinkedList {
private:
	int counter;

public:
	Node<T>* head;
	Node<T>* tail;

	DoublyLinkedList() = default;

	Node<T>* get(int index) const;

	void insert_head(const T& element);
	void insert_tail(const T& element);
	void insert(int index, const T& element);

	int search(const T& value) const;

	void remove_head();
	void remove_tail();
	void remove(int index);

	int size() const;
	void show() const;
	void show_backward() const;
};

template <class T>
void DoublyLinkedList<T>::remove_tail()
{
	if (counter == 0) {
		return;
	}

	if (counter == 1)
	{
		remove_head();
		return;
	}

	Node<T>* node = tail;
	tail = tail->prev;

	tail->next = nullptr;

	delete node;
	counter--;
}

template <class T>
void DoublyLinkedList<T>::remove_head()
{
	if (counter == 0) {
		return;
	}

	Node<T>* node = head;
	head = head->next;

	delete node;

	if (head != nullptr) {
		head->prev = nullptr;
	}

	counter--;
}

template <class T>
void DoublyLinkedList<T>::remove(int index)
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

	Node<T> * prev_node = head;

	for (int i = 0; i < index - 1; ++i)
	{
		prev_node = prev_node->next;
	}

	Node<T> * node = prev_node->next;
	Node<T> * next_node = node->next;

	prev_node->next = next_node;
	next_node->prev = prev_node;

	delete node;
	counter--;
}

template <class T>
void DoublyLinkedList<T>::insert_head(const T& value)
{
	Node<T>* node = new Node<T>{value};
	node->next = head;

	if (head != nullptr) {
		head->prev = node;
	}

	head = node;

	if (counter == 0) {
		tail = head;
	}

	// One element is added
	counter++;
}

template <class T>
void DoublyLinkedList<T>::insert_tail(const T& value)
{
	if (counter == 0)
	{
		insert_head(value);
		return;
	}

	Node<T>* node = new Node<T>{value};
	tail->next = node;
	node->prev = tail;
	tail = node;

	counter++;
}

template <class T>
void DoublyLinkedList<T>::insert(int index, const T& value)
{
	if (index < 0 || index > counter) {
		return;
	}

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

	Node<T>* prev_node = head;

	for (int i = 0; i < index - 1; ++i)
	{
		prev_node = prev_node->next;
	}

	Node<T>* next_node = prev_node->next;

	Node<T>* node = new Node<T>{ value };

	node->next = next_node;
	node->prev = prev_node;
	prev_node->next = node;
	next_node->prev = node;

	counter++;
}

template <class T>
int DoublyLinkedList<T>::size() const {
	return counter;
}

template <class T>
int DoublyLinkedList<T>::search(const T& value) const {

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
Node<T>* DoublyLinkedList<T>::get(int index) const
{
	if (index < 0 || index > counter) {
		return nullptr;
	}

	if (index == 0) {
		return head;
	}

	if (index == counter - 1) {
		return tail;
	}

	Node<T> * temp_node = head;

	for (int i = 0; i < index; ++i)
	{
		temp_node = temp_node->next;
	}

	return temp_node;
}

template <class T>
void DoublyLinkedList<T>::show() const {
	Node<T>* temp_node = head;

	while (temp_node) {
		std::cout << temp_node->value << "\t";
		temp_node = temp_node->next;
	}
	std::cout << std::endl;
}

template <class T>
void DoublyLinkedList<T>::show_backward() const {
	Node<T>* temp_node = tail;

	while (temp_node) {
		std::cout << temp_node->value << "\t";
		temp_node = temp_node->prev;
	}
	std::cout << std::endl;
}

#endif // !DOUBLY_LINKED_LIST

