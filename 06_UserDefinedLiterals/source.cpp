#include "conversions.hpp"

using namespace Currency::Conversion;

int main() {

	// przykladowe stale doslowne
	
	auto val1 = 23;
	auto val2 = 23ul;
	auto val3 = 23.4f;
	auto val4 = "hello";

	// stale doslowne definiowane przez programiste

	Currency::Pln curr{ 140 };
	std::cout << curr << std::endl;

	curr = 230.0_GBP;
	std::cout << curr << std::endl;

	curr = 123.3_EUR;
	std::cout << curr << std::endl;

	curr = "dwa_tysiace_czterysta_dwadziescia_trzy"_SLOWNIE;
	std::cout << curr << std::endl;

	std::cin.get();
	return 0;
}