#include "pln.hpp"

namespace Currency {

	Pln::Pln(double value) : value{ value } {}

	Pln& Pln::operator=(const Pln& currency_pln) {
		if (this == &currency_pln) {
			return *this;
		}
		this->value = currency_pln.value;
		return *this;
	}

	std::ostream& operator<<(std::ostream& out, const Pln& currency) {
		return out << currency.value;
	}

}