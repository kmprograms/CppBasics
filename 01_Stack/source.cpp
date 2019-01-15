#include <iostream>
#include <string>
#include "stack.h"

// podobna metoda wystepuje juz w STL
std::string reverse_string(const std::string& str) {
	if (str.empty()) {
		return str;
	}

	stack<char> char_stack{};
	for (const char x : str) {
		char_stack.push(x);
	}

	std::string rev_str;
	while (!char_stack.is_empty()) {
		rev_str += char_stack.top();
		char_stack.pop();
	}
	return rev_str;
}

int main() {

	std::string sentence = "home sweet home";
	std::cout << sentence << std::endl;
	std::cout << reverse_string(sentence) << std::endl;

	std::cin.get();
	return 0;
}