#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{
public:
	T value;
	Node<T>* prev;
	Node<T>* next;
	explicit Node(T value) : value{ value } {};
};

#endif


