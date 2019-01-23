#include <iostream>
#include "point.h"
#include "list.h"

int main() {

	try {
		ArrayList<Point> list;

		std::cout << "------------------------------------------" << std::endl;
		std::cout << "INSERT" << std::endl;
		list.insert(0, Point{ 1, 1 });
		list.insert(1, Point{ 2, 2 });
		list.insert(2, Point{ 3, 3 });
		list.insert(3, Point{ 4, 4 });
		list.insert(4, Point{ 5, 5 });
		list.insert(2, Point{ 6, 6 });
		list.insert(4, Point{ 7, 7 });

		for (int i = 0; i < list.count(); ++i) {
			std::cout << list.get(i) << std::endl;
		}

		std::cout << "------------------------------------------" << std::endl;
		std::cout << "SEARCH" << std::endl;
		std::cout << "POS = " << list.search(Point{ 3, 3 }) << std::endl;
		std::cout << "POS = " <<  list.search(Point{ 10, 10 }) << std::endl;

		std::cout << "------------------------------------------" << std::endl;
		std::cout << "REMOVE" << std::endl;
		list.remove(2);
		list.remove(6);
		list.remove(3);

		for (int i = 0; i < list.count(); ++i) {
			std::cout << list.get(i) << std::endl;
		}

		/*
		list.insert(1, list2);
		list.insert(20).insert(21).insert(22);
		list.insert({ 10, 20, 30, 40 });
		list += 20;
		list -= 30;
		if (list1 == list2) {...}
		list.remove_all({21, 13, 22, 4})
		list.frequency(21)
		list >> 1
		list << 1
	    list[2]
		*/

		

	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
	std::cin.get();
	return 0;
}