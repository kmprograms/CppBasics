#include <iostream>
#include "bs_tree.h"

int main() {

	auto tree = new BSTree<int>{};
	
	tree->insert(20);
	tree->insert(10);
	tree->insert(23);
	tree->insert(11);
	tree->insert(18);
	tree->insert(16);
	tree->insert(19);
	tree->insert(7);

	tree->traverse_in_order();
	std::cout << "Element 11: " << tree->search(11) << std::endl;
	std::cout << "Element 111: " << tree->search(111) << std::endl;

	std::cout << "Min: " << tree->min().value_or(INT_MIN) << std::endl;
	std::cout << "Max: " << tree->max().value_or(INT_MIN) << std::endl;

	auto successor_op = tree->successor(23);
	if (successor_op) {
		std::cout << "Successor: " << *successor_op << std::endl;
	}
	std::cout << "Predecessor: " << tree->predecessor(7).value_or(INT_MIN) << std::endl;

	tree->remove(11);
	tree->traverse_in_order();

	std::cin.get();
	return 0;
}