#include <iostream>
#include "linked_list.h"

int main() {

	LinkedList<int> llist{};

	llist.insert_head(10);
	llist.insert_head(20);
	llist.insert_head(30);

	llist.insert_tail(1);
	llist.insert_tail(2);

	llist.insert(0, 111);
	llist.insert(30, 222);
	llist.insert(6, 333);

	int value1 = 20, value2 = 200;
	std::cout << "ELEMENT1 = " << llist.search(value1) << std::endl;
	std::cout << "ELEMENT2 = " << llist.search(value2) << std::endl;

	llist.show();

	std::cout << "REMOVE" << std::endl;
	llist.remove_head();
	llist.remove_head();
	std::cout << "NUMBER OF ELEMENTS = " << llist.size() << std::endl;
	
	llist.remove_tail();
	llist.remove_tail();
	std::cout << "NUMBER OF ELEMENTS = " << llist.size() << std::endl;
	
	llist.remove(1);
	std::cout << "NUMBER OF ELEMENTS = " << llist.size() << std::endl;

	std::cout << "ELEMENTS:" << std::endl;
	llist.show();

	std::cin.get();
	return 0;
}