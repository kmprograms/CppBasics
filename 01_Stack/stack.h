#ifndef STACK_H
#define STACK_H

#include "node.h"

template <class T>
class stack {
private:
	int counter_;
	node<T>* top_;
public:
	stack() = default;
	bool is_empty() const;
	T top() const;
	void push(const T& new_value);
	void pop();
};

template<class T>
T stack<T>::top() const {
	// zwraca wartosc z wierzcholka stosu
	return top_->value_;
}

template<class T>
bool stack<T>::is_empty() const {
	return counter_ <= 0;
}

template<class T>
void stack<T>::push(const T& val) {

	// tworzymy nowy wezel - to bedzie nowy wierzcholek stosu
	node<T>* new_node = new node<T>(val);

	// kolejny po nowym wierzcholku element to dotychczasowy wierzcholek
	new_node->next_ = top_;

	// nowy wezel staje sie wezlem na ktory pokazuje wierzcholek stosu
	top_ = new_node;

	// licznik elementow zwiekszamy o 1
	counter_++;
}

template <class T>
void stack<T>::pop() {

	// jezeli na stosie nic nie ma to nic nie robimy
	if (is_empty()) {
		return;
	}

	// przechwyujemy element z wierzcholka do usuniecia
	node<T>* node = top_;

	// wierzcholkiem staje sie ten element ktory do tej pory byl za
	// dotychczasowym wierzcholkiem
	top_ = top_->next_;

	// zwalniamy element, ktory byl do tej pory wierzcholkiem
	delete node;

	// zmniejszamy licznik elementow
	counter_--;
}

#endif // !STACK_H

