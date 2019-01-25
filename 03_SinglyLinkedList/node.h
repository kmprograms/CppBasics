#ifndef NODE_H
#define NODE_H

template <class T>
struct Node
{
	T value;
	Node<T>* next;

	friend std::ostream& operator<<(std::ostream& out, const Node<T>& node);
};

template <class T>
std::ostream& operator<<(std::ostream& out, const Node<T>& node) {
	return out << node->value;
}

#endif // !NODE_H

