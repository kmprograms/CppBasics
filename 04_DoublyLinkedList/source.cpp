#include <iostream>
#include "doubly_linked_list.h"

int main() {

	/*
		1. Zlozonosc obliczeniowa

		2. Zlozonosc czasowa

		3. Zlozonosc pamieciowa

		4. Notacja duze-O

		5. Co to znaczy, ze algorytm ma zlozonosc logarytmiczna O(log n) ?

		6. Ktora zlozonosc jest "lepsza"? O(n) czy O(log n) i dlaczego ?

		7. Jakie znamy inne popularne zlozonoœci czasowe ?

		8. Jaka zlozonosc czasowa maja algorytmy takie jak:
		--> sortowanie przez scalanie
		--> wyszukiwanie binarne
		--> sortowanie szybkie
	*/

	DoublyLinkedList<int> list{};

	std::cout << "------------- INSERT ----------------" << std::endl;
	list.insert_head(1);
	list.insert_head(2);
	
	list.insert_tail(3);
	list.insert_tail(4);

	list.insert(0, 5);
	list.insert(list.size(), 6);
	list.insert(3, 7);
	
	std::cout << "SIZE = " << list.size() << std::endl;
	
	std::cout << "FORWARD" << std::endl;
	list.show();

	std::cout << "BACKWARD" << std::endl;
	list.show_backward();

	std::cout << "------------- REMOVE ----------------" << std::endl;

	list.remove_head();
	list.remove_head();
	list.remove_tail();
	list.remove_tail();
	list.remove(2);
	list.remove(30);

	std::cout << "FORWARD" << std::endl;
	list.show();

	std::cout << "BACKWARD" << std::endl;
	list.show_backward();

	std::cout << "------------------ GET -----------------" << std::endl;
	std::cout << "EL -> " << list.get(0)->value << std::endl;
	std::cout << "EL -> " << list.get(1)->value << std::endl;

	std::cout << "----------------- SEARCH ---------------" << std::endl;
	std::cout << list.search(1) << std::endl;
	std::cout << list.search(7) << std::endl;
	std::cout << list.search(17) << std::endl;

	std::cin.get();
	return 0;
}