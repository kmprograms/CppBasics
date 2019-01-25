#ifndef NODE_H
#define NODE_H

template <class T>
struct node
{
	T value_;
	node<T>* next_;
	node(const T& value) : value_(value), next_(nullptr) {}
};

#endif // !NODE_H